/*!
 *  \author 	Benjamin Stahl
 *  \author 	stahl04
 *  \version 	1.0
 *  \date		17.10.2019
 */

/*!
 *  \file ControlModule.cpp
 *  \brief This program section is handling the I/O control.
 */

#include "ControlModule.h"
#include "IoModule.h"
#include "PinAssign.h"
#include "Calibration.h"
#include "ProtocolHandler.h"
#include "OperationModeDetection.h"
#include "ErrorHandler.h"

/// Define index of the pin states
#define IDX_STATE_DEBUG1_2  (0)
#define IDX_STATE_DEBUG1_3  (1)
#define IDX_STATE_WD_SUPP   (2)
#define IDX_STATE_DEBUGGER  (3)
#define IDX_STATE_RELAIS1   (4)
#define IDX_STATE_RELAIS2   (5)
#define IDX_STATE_EXT       (6)
#define IDX_STATE_MULTIPLX_OUTP   (7)
#define IDX_STATE_MULTIPLX_ENABL  (8)
#define IDX_STATE_DTMBOARD_SELECT (9)
#define IDX_STATE_CNT       (10)

/// Switch states for all digital output pins
#define SWITCHSTATE_STRUCT_INIT       {	{ PIN_DEBUG1_DEBUG2_ENABLE,  false, 0 }, \
										{ PIN_DEBUG1_DEBUG3_ENABLE,  false, 0 }, \
										{ PIN_WATCHDOG_SUPPR,        false, 0 }, \
										{ PIN_DEBUGGER_SUPPLY,       false, 0 }, \
										{ PIN_RELAIS_01,             false, 0 }, \
										{ PIN_RELAIS_02,             false, 0 }, \
										{ PIN_RELAIS_EXT,            false, 0 }, \
										{ PIN_MULTIPLEX_OUTP_SELECT, false, 0 }, \
										{ PIN_MULTIPLEX_ENABLE,      true, 0 },     /* low active */  \
										{ PIN_DTMBOARD_SELECT,       false, 0 } }
/// Switch state struct
typedef struct{
	const uint8_t pinId;
	bool state;
	uint16_t delay;
}CtrlMod_TSSwitchState;

/// Define internal states
typedef enum{
	CtrlMod_TEIntStates_Init = 0,
	CtrlMod_TEIntStates_InitWaitAllOff,
	CtrlMod_TEIntStates_CheckErrorStates,
	CtrlMod_TEIntStates_EvalRemoteData,
	CtrlMod_TEIntStates_PrepareAllOff,
	CtrlMod_TEIntStates_WaitAllOff,
	CtrlMod_TEIntStates_PrepareTakeOver,
	CtrlMod_TEIntStates_TakeOverCtrlData,
	CtrlMod_TEIntStates_ProcessSwitching,
	CtrlMod_TEIntStates_PowerSupplyMissing,
	CtrlMod_TEIntStates_CalibrationRunning
}CtrlMod_TEIntStates;

/// Init Switch state of master/standalone and slave
static CtrlMod_TSSwitchState CtrlMod_switchStates[IDX_STATE_CNT] = SWITCHSTATE_STRUCT_INIT;
static CtrlMod_TSSwitchState CtrlMod_switchStatesSlave[IDX_STATE_CNT] = SWITCHSTATE_STRUCT_INIT;

static bool CtrlMod_delaysSet = false;
/// Init control data for slave
static ProtHdl_TSCtrlData CtrlMod_ctrlDataSlave = PROTHDL_CTRLDATA_STRUCT_INIT;

/// Function prototypes
static void CtrlMod_TakeOverCtrlData(ProtHdl_TSCtrlData ctrlData, CtrlMod_TSSwitchState* switchStates);
static void CtrlMod_PrepareAllOff(ProtHdl_TEDebugMode debugMode, ProtHdl_TEDebugMode debugModeOld);
static void CtrlMod_SetDelaysTakeOver(void);
static bool CtrlMod_ProcessSwitching(void);
static void CtrlMod_GenMasterSlaveCtrlData(ProtHdl_TSCtrlData ctrlDataRemote, ProtHdl_TSCtrlData* ctrlData, ProtHdl_TSCtrlData* ctrlDataSlave);

/// No Initialization
void CtrlMod_Init(void){

}

/**
 * @brief Main function of the ControlModule
 *
 * This function is the main function that implements a state machine to control the behavior of the system.
 * The function uses a switch statement to transition between different states and perform specific tasks or operations.
 * The function uses several static variables to maintain state and store temporary data.
 *
 */
void CtrlMod_Main(void){

	static ProtHdl_TSCtrlData rcvdRemoteDataOld = PROTHDL_CTRLDATA_STRUCT_INIT;
	static ProtHdl_TSCtrlData rcvdRemoteData = PROTHDL_CTRLDATA_STRUCT_INIT;
	static CtrlMod_TEIntStates intState = CtrlMod_TEIntStates_Init;
	static bool errorStorage = false;
	Std_ReturnType ret = E_NOT_OK;
	ProtHdl_TSCtrlData ctrlDataTemp = PROTHDL_CTRLDATA_STRUCT_INIT;
	ProtHdl_TSCtrlData ctrlDataSlaveTemp = PROTHDL_CTRLDATA_STRUCT_INIT;
	OpModeDet_TEOpModeType opMode = OpModeDet_GetOpMode();

	/// Do task depending on the internal state
	switch (intState){
	/// Init state
	case CtrlMod_TEIntStates_Init:
		rcvdRemoteDataOld.debugMode = ProtHdl_TEDebugMode_Nothing;
		/// Check if operation mode is valid
		if (opMode != OpModeDet_TEOpModeType_NotAvailable){
			/// Turn all switches off
			CtrlMod_PrepareAllOff(ProtHdl_TEDebugMode_Nothing, ProtHdl_TEDebugMode_Nothing);
			/// Next state InitWaitAllOff
			intState = CtrlMod_TEIntStates_InitWaitAllOff;
		}
		break;
	/// Wait until all pins are off
	case CtrlMod_TEIntStates_InitWaitAllOff:
		/// Process switching returns false, when all delays are at 0
		if (CtrlMod_ProcessSwitching() == false){
			/// Reset the remote control data
			ProtHdl_ResetRemoteCtrlData();
			intState = CtrlMod_TEIntStates_CheckErrorStates;
		}
		break;
	/// Check for the active error state
	case CtrlMod_TEIntStates_CheckErrorStates:
		/// If there is an error and it has not been detected yet, restart the control process
		if (ErrHdl_GetErrorStatus() != ErrHdl_ErrorStatus_OK){
			if (false == errorStorage){
				intState = CtrlMod_TEIntStates_Init;
			}
			errorStorage = true;
		}
		else{
			errorStorage = false;
			intState = CtrlMod_TEIntStates_EvalRemoteData;
		}
		break;
	///
	case CtrlMod_TEIntStates_EvalRemoteData:
		/// If there is no calibration request, get the remote control data
		if (Calib_IsCalibrationRequested() == false){
			ret = ProtHdl_GetRemoteCtrlData(&rcvdRemoteData);
			if (E_OK == ret){
				/// Take over the control data
				intState = CtrlMod_TEIntStates_TakeOverCtrlData;
				/**
				 * 	If the debug mode changes the board switches between JTAG2 and JTAG3. Before that happens, the board sets all
				 * 	pins off. After a short delay the changes will be applied.
				 */
				if ((rcvdRemoteData.debugMode != rcvdRemoteDataOld.debugMode) && (opMode != OpModeDet_TEOpModeType_Slave)){
					intState = CtrlMod_TEIntStates_PrepareAllOff;
				}
				rcvdRemoteDataOld = rcvdRemoteData;
			}
		}
		else{
			/// Start the calibration if there is a calibration request.
			Calib_TriggerCalibration();
			intState = CtrlMod_TEIntStates_CalibrationRunning;
		}

		break;
	/// Prepare to turn all pins off
	case CtrlMod_TEIntStates_PrepareAllOff:
		CtrlMod_PrepareAllOff(rcvdRemoteData.debugMode, rcvdRemoteDataOld.debugMode);
		intState = CtrlMod_TEIntStates_WaitAllOff;
		break;
	/// Wait until all delays are at 0 and switch all pins off
	case CtrlMod_TEIntStates_WaitAllOff:
		if (CtrlMod_ProcessSwitching() == false){
			intState = CtrlMod_TEIntStates_PrepareTakeOver;
		}
		break;
	/// Set the delays for the control take over
	case CtrlMod_TEIntStates_PrepareTakeOver:
		CtrlMod_SetDelaysTakeOver();
		intState = CtrlMod_TEIntStates_TakeOverCtrlData;
		break;
	/// Take over the control data
	case CtrlMod_TEIntStates_TakeOverCtrlData:
		CtrlMod_GenMasterSlaveCtrlData(rcvdRemoteData, &ctrlDataTemp, &ctrlDataSlaveTemp);
		CtrlMod_TakeOverCtrlData(ctrlDataTemp, &CtrlMod_switchStates[0]);
		CtrlMod_TakeOverCtrlData(ctrlDataSlaveTemp, &CtrlMod_switchStatesSlave[0]);
		CtrlMod_switchStates[IDX_STATE_DTMBOARD_SELECT].state = false;
		if ((OpModeDet_TEOpModeType_Master == opMode) && (rcvdRemoteData.debugMode < ProtHdl_TEDebugMode_Slave_Nothing)){
			CtrlMod_switchStates[IDX_STATE_DTMBOARD_SELECT].state = true;
		}
		intState = CtrlMod_TEIntStates_ProcessSwitching;
		break;
	/// Process the control data and switch the pins
	case CtrlMod_TEIntStates_ProcessSwitching:
		if (CtrlMod_ProcessSwitching() == false){
			intState = CtrlMod_TEIntStates_CheckErrorStates;
		}
		break;
	/// When the calibration is finished, init control
	case CtrlMod_TEIntStates_CalibrationRunning:
		if (Calib_IsCalibrationRunning() == false){
			intState = CtrlMod_TEIntStates_Init;
		}
		break;

	default:
		break;
	}
}

/*!
 *  \brief Copy the slave control data to the given location.
 *
 *	This function copies the slave control data to the given location ctrlDataSlave.
 *  Copys the
 *  \param ctrlDataSlave Pointer to the ProtHdl_TSCtrlData structure where the control data for the slave will be stored
 *  \return ret Returns E_OK if the control data are successfully retrieved
 */
Std_ReturnType CtrlMod_GetCtrlDataSlave(ProtHdl_TSCtrlData* ctrlDataSlave){

	Std_ReturnType ret = E_OK;

	memcpy(ctrlDataSlave, &CtrlMod_ctrlDataSlave, sizeof(ProtHdl_TSCtrlData));

	return ret;
}

/*!
 *  \brief Set the pins to the corresponding state from CtrlMod_switchStates.
 *
 *  This function sets the pins to the corresponding state from CtrlMod_switchStates.
 *  Also changes the switchStates for the slave if in operation mode master.
 *  \return CtrlMod_delaysSet True if any control state has a delay greater than 0, false otherwise.
 */
static bool CtrlMod_ProcessSwitching(void){

	uint8_t cnt = 0;
	OpModeDet_TEOpModeType opMode = OpModeDet_GetOpMode();

	CtrlMod_delaysSet = false;

	/// Set the pin state when the delay counter is at zero
	for (cnt = 0; cnt < IDX_STATE_CNT; cnt++){
		if (CtrlMod_switchStates[cnt].delay > 0 ){
			CtrlMod_switchStates[cnt].delay--;
			CtrlMod_delaysSet |= true;
		}
		else{
			IoMod_SetPin(CtrlMod_switchStates[cnt].pinId, CtrlMod_switchStates[cnt].state);
		}
	}

	/// Set the control data of the slave if in operation mode master
	if (OpModeDet_TEOpModeType_Master == opMode){

		for (cnt = 0; cnt < IDX_STATE_CNT; cnt++){
			/// Only set the switch state if delay of pin is at zero
			if (CtrlMod_switchStatesSlave[cnt].delay > 0 ){
				CtrlMod_switchStatesSlave[cnt].delay--;
				CtrlMod_delaysSet |= true;
			}
			else{
				switch (cnt){
				case IDX_STATE_WD_SUPP:
					CtrlMod_ctrlDataSlave.watchdogSuppression = CtrlMod_switchStatesSlave[cnt].state;
					break;

				case IDX_STATE_DEBUGGER:
					CtrlMod_ctrlDataSlave.debuggerSupply = CtrlMod_switchStatesSlave[cnt].state;
					break;

				case IDX_STATE_RELAIS1:
					CtrlMod_ctrlDataSlave.relais01 = CtrlMod_switchStatesSlave[cnt].state;
					break;

				case IDX_STATE_RELAIS2:
					CtrlMod_ctrlDataSlave.relais02 = CtrlMod_switchStatesSlave[cnt].state;
					break;

				case IDX_STATE_EXT:
					CtrlMod_ctrlDataSlave.extRelais = CtrlMod_switchStatesSlave[cnt].state;
					break;

				default:
					break;
				}
			}
		}

		if ((0 == CtrlMod_switchStatesSlave[IDX_STATE_DEBUG1_2].delay) && (0 == CtrlMod_switchStatesSlave[IDX_STATE_DEBUG1_3].delay)){

			CtrlMod_ctrlDataSlave.debugMode = ProtHdl_TEDebugMode_Nothing;
			if (true == CtrlMod_switchStatesSlave[IDX_STATE_DEBUG1_2].state){

				CtrlMod_ctrlDataSlave.debugMode = ProtHdl_TEDebugMode_1_2;
			}else if (true == CtrlMod_switchStatesSlave[IDX_STATE_DEBUG1_3].state){

				CtrlMod_ctrlDataSlave.debugMode = ProtHdl_TEDebugMode_1_3;
			}
		}
	}
	/// delaysSet is false when all delays are at 0
	return CtrlMod_delaysSet;
}

/*!
 *  \brief Get the control data depending on the operation mode.
 *
 *	This function generates the control data depending on the operation mode.
 *  \param ctrlDataRemote Remote control data
 *  \param ctrlData Control data for the board
 *  \param ctrlDataSlave Control data for the slave
 */
static void CtrlMod_GenMasterSlaveCtrlData(ProtHdl_TSCtrlData ctrlDataRemote, ProtHdl_TSCtrlData* ctrlData, ProtHdl_TSCtrlData* ctrlDataSlave){

	OpModeDet_TEOpModeType opMode = OpModeDet_GetOpMode();
	if ((OpModeDet_TEOpModeType_Standalone == opMode) || (OpModeDet_TEOpModeType_Slave == opMode)){

		/// The remote data can directly be taken over for this board
		memcpy(ctrlData, &ctrlDataRemote, sizeof(ProtHdl_TSCtrlData));
	}
	/// Prepare control data in master mode
	else if (OpModeDet_TEOpModeType_Master == opMode){

		switch (ctrlDataRemote.debugMode){
		/// Control data for the master board
		case ProtHdl_TEDebugMode_Nothing:
		case ProtHdl_TEDebugMode_1_2:
		case ProtHdl_TEDebugMode_1_3:
			memcpy(ctrlData, &ctrlDataRemote, sizeof(ProtHdl_TSCtrlData));
			ctrlData->debuggerSupply = false;
			ctrlDataSlave->debugMode = ProtHdl_TEDebugMode_Nothing;
			ctrlDataSlave->debuggerSupply = ctrlDataRemote.debuggerSupply;
			break;
		/// Control data for the slave board
		case ProtHdl_TEDebugMode_Slave_Nothing:
		case ProtHdl_TEDebugMode_Slave_1_2:
		case ProtHdl_TEDebugMode_Slave_1_3:
			memcpy(ctrlDataSlave, &ctrlDataRemote, sizeof(ProtHdl_TSCtrlData));
			ctrlDataSlave->debugMode = (ProtHdl_TEDebugMode) (ctrlDataSlave->debugMode - ProtHdl_TEDebugMode_Slave_Nothing);
			break;

		default:
			break;
		}
	}
}

/// Set the delays for the control data take over
static void CtrlMod_SetDelaysTakeOver(void){

	/// No check for operation mode needed as this interface is only called from Master/Standalone

	uint8_t cnt = 0;

	CtrlMod_switchStates[IDX_STATE_DTMBOARD_SELECT].delay = 10;
	CtrlMod_switchStates[IDX_STATE_DEBUG1_2].delay  = 20;
	CtrlMod_switchStates[IDX_STATE_DEBUG1_3].delay  = 20;
	CtrlMod_switchStates[IDX_STATE_WD_SUPP].delay  = 20;
	CtrlMod_switchStates[IDX_STATE_MULTIPLX_OUTP].delay  = 20;
	CtrlMod_switchStates[IDX_STATE_MULTIPLX_ENABL].delay = 25;
	CtrlMod_switchStates[IDX_STATE_DEBUGGER].delay = 40;
	CtrlMod_switchStates[IDX_STATE_RELAIS1].delay  = 50;
	CtrlMod_switchStates[IDX_STATE_RELAIS2].delay  = 50;
	CtrlMod_switchStates[IDX_STATE_EXT].delay      = 50;

	for (cnt = 0; cnt < IDX_STATE_CNT; cnt++){

		CtrlMod_switchStatesSlave[cnt].delay = CtrlMod_switchStates[cnt].delay;
	}

}
/*!
 *  \brief Set delays and switch states to off.
 *
 *  This function prepares the internal switch states to turn all pins off.
 *  \param debugMode Current debug mode
 *  \param debugModeOld The previous debug mode
 */
static void CtrlMod_PrepareAllOff(ProtHdl_TEDebugMode debugMode, ProtHdl_TEDebugMode debugModeOld){

	/// No check for operation mode needed as this interface is only called from Master/Standalone

	uint8_t cnt = 0;

	CtrlMod_switchStates[IDX_STATE_RELAIS1].delay  = 0;
	CtrlMod_switchStates[IDX_STATE_RELAIS2].delay  = 0;
	CtrlMod_switchStates[IDX_STATE_EXT].delay      = 0;
	CtrlMod_switchStates[IDX_STATE_DEBUGGER].delay = 10;
	CtrlMod_switchStates[IDX_STATE_MULTIPLX_ENABL].delay = 30;
	CtrlMod_switchStates[IDX_STATE_MULTIPLX_OUTP].delay  = 35;
	CtrlMod_switchStates[IDX_STATE_DEBUG1_2].delay  = 30;
	CtrlMod_switchStates[IDX_STATE_DEBUG1_3].delay  = 30;
	CtrlMod_switchStates[IDX_STATE_WD_SUPP].delay  = 30;

	for (cnt = 0; cnt < IDX_STATE_CNT; cnt++){
		/// Almost all off
		if (cnt != IDX_STATE_DTMBOARD_SELECT){
			CtrlMod_switchStates[cnt].state = false;
		}

		if (IDX_STATE_MULTIPLX_ENABL == cnt){
			/// Low active
			CtrlMod_switchStates[cnt].state = true;
		}
		CtrlMod_switchStatesSlave[cnt].state = CtrlMod_switchStates[cnt].state;
		CtrlMod_switchStatesSlave[cnt].delay = CtrlMod_switchStates[cnt].delay;
	}
	/// Check if debug mode changed from slave to normal or from normal to slave
	if (((debugMode < ProtHdl_TEDebugMode_Slave_Nothing) && (debugModeOld >= ProtHdl_TEDebugMode_Slave_Nothing))
			|| ((debugMode >= ProtHdl_TEDebugMode_Slave_Nothing) && (debugModeOld < ProtHdl_TEDebugMode_Slave_Nothing))){
		CtrlMod_switchStates[IDX_STATE_DTMBOARD_SELECT].delay = 30;
		CtrlMod_switchStates[IDX_STATE_DTMBOARD_SELECT].state = false;
	}
}

/*!
 *  \brief Take over the control data to the internal
 *  This function takes over the control data to the switch states.
 *  \param ctrlData Control data
 *  \param switchStates Switch states
 */
static void CtrlMod_TakeOverCtrlData(ProtHdl_TSCtrlData ctrlData, CtrlMod_TSSwitchState* switchStates){
	/// Check for debugMode
	switch (ctrlData.debugMode){

	case ProtHdl_TEDebugMode_Nothing:
	default:
		switchStates[IDX_STATE_DEBUG1_2].state = false;
		switchStates[IDX_STATE_DEBUG1_3].state = false;
		switchStates[IDX_STATE_MULTIPLX_OUTP].state = false;
		switchStates[IDX_STATE_MULTIPLX_ENABL].state = true;    /* low active */
		break;

	case ProtHdl_TEDebugMode_1_2:
		switchStates[IDX_STATE_DEBUG1_2].state = true;
		switchStates[IDX_STATE_DEBUG1_3].state = false;
		switchStates[IDX_STATE_MULTIPLX_OUTP].state = true;
		switchStates[IDX_STATE_MULTIPLX_ENABL].state = false;    /* low active */
		break;

	case ProtHdl_TEDebugMode_1_3:
		switchStates[IDX_STATE_DEBUG1_2].state = false;
		switchStates[IDX_STATE_DEBUG1_3].state = true;
		switchStates[IDX_STATE_MULTIPLX_OUTP].state = false;
		switchStates[IDX_STATE_MULTIPLX_ENABL].state = false;    /* low active */
		break;
	}

	switchStates[IDX_STATE_WD_SUPP].state  = ctrlData.watchdogSuppression;
	switchStates[IDX_STATE_DEBUGGER].state = ctrlData.debuggerSupply;
	switchStates[IDX_STATE_RELAIS1].state  = ctrlData.relais01;
	switchStates[IDX_STATE_RELAIS2].state  = ctrlData.relais02;
	switchStates[IDX_STATE_EXT].state      = ctrlData.extRelais;
}

/// Get delaysSet
bool CtrlMod_GetDelaysSet(void){

	return CtrlMod_delaysSet;
}
