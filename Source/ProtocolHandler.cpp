/*!
 *  \author	   	Benjamin Stahl
 *  \author	   	stahl04
 *  \version   	1.0
 *  \date		20.08.2021
 */

/*!
 *  \file ProtocolHandler.cpp
 *  \brief This program section is about receiving data and handling it.
 */

/// As include needed header files
#include "ProtocolHandler.h"
#include "OperationModeDetection.h"
#include "IoModule.h"
#include "PinAssign.h"
#include "ControlModule.h"
#include "Calibration.h"
#include "VersionInfo.h"
#include "ErrorHandler.h"

/// Define the receive buffer size for control data
#define RXCTRLDATABUFFER_SIZE    PROTHDL_CTRLDATABUFFER_SIZE
/// Define the receive buffer size for status data (only in operation mode slave)
#define RXSTATUSDATABUFFER_SIZE  PROTHDL_SLAVETXDATASIZE
/// Define the start character
#define START_CHAR      ('$')
/// Define the end character
#define END_CHAR        ('#')
/// Define the size of the control data fields
#define CTRLDATA_DATAFIELDS_CNT     (6)
/// Define the size of the status data fields
#define STATUSDATA_DATAFIELDS_CNT   (17)

/// Buffer for received control data
static char ProtHdl_rxCtrlDataBuffer[RXCTRLDATABUFFER_SIZE] = { '\0' };
/// Buffer for received status data
static char ProtHdl_rxStatusDataBuffer[RXSTATUSDATABUFFER_SIZE] = { '\0' };

/// Received control data
static ProtHdl_TSCtrlData ProtHdl_remoteCtrlData = PROTHDL_CTRLDATA_STRUCT_INIT;
/// Validation parameter for the received remote control data
static Std_ReturnType ProtHdl_remoteCtrlDataValid = E_NOT_OK;
/// Received status data of the slave board
static ProtHdl_TSStatusData ProtHdl_slaveStatusData = PROTHDL_STATUSDATA_STRUCT_INIT;
/// Validation parameter for the slave status data
static Std_ReturnType ProtHdl_slaveStatusDataValid = E_NOT_OK;

/// Function prototypes
static Std_ReturnType ProtHdl_RxCtrlBuffHandler(char data);
static Std_ReturnType ProtHdl_RxStatusBuffHandler(char data);
static bool ProtHdl_RxBuffHandler(char* buffer, char dataRcvd, uint8_t bufferSize, bool* startChrFnd);
static Std_ReturnType ProtHdl_SplitRxData(char* buffer, char** pDataFields, uint8_t dataFieldsSize);
static Std_ReturnType ProtHdl_ParseRxCtrlData(char* buffer);
static Std_ReturnType ProtHdl_ParseRxStatusData(char* buffer, ProtHdl_TSStatusData* statusData);
static bool ProtHdl_CheckData(int32_t data, int32_t min, int32_t max);

/// Empty initialization
void ProtHdl_Init(void){

}

///Empty main function
void ProtHdl_Main(void){

}

/*!
 *  \brief Handle received data from the GUI for operation mode master and standalone.
 *
 *  This function handles the data received via RS232 from the GUI and passes it to the ProtHdl_RxCtrlBuffHandler
 *  if the current operation mode is standalone or master.
 *  \param data The received data character
 *  \return The status of the operation.
 *  \retval E_OK when a whole data set was received.
 *  \retval E_NOT_OK The operation failed.
 */
Std_ReturnType ProtHdl_Rs232DataRcvd(char data){

	/// Get current operation mode
	OpModeDet_TEOpModeType opMode = OpModeDet_GetOpMode();
	Std_ReturnType ret = E_NOT_OK;

	/// Call the control buffer handler if the operation mode is standalone or master
	if ((opMode != OpModeDet_TEOpModeType_Slave) && (opMode != OpModeDet_TEOpModeType_NotAvailable)){

		ret = ProtHdl_RxCtrlBuffHandler(data);
	}

	return ret;
}

/*!
 *  \brief Handle received data from the master board for the slave board.
 *
 *  This function handles the data received via I2c and passes it to the ProtHdl_RxCtrlBuffHandler
 *  if the current operation mode is slave.
 *  \param data The received data character
 *  \return The status of the operation.
 *  \retval E_OK when a whole data set was received.
 *  \retval E_NOT_OK The operation failed.
 */
Std_ReturnType ProtHdl_I2cDataFromMasterRcvd(char data){

	/// Get the current operation mode
	OpModeDet_TEOpModeType opMode = OpModeDet_GetOpMode();
	Std_ReturnType ret = E_NOT_OK;

	/// Call the control buffer handler if the current operation mode is slave
	if (opMode == OpModeDet_TEOpModeType_Slave){

		ret = ProtHdl_RxCtrlBuffHandler(data);
	}

	return ret;
}

/*!
 *  \brief Handle the received data from the slave for the master board.
 *
 *  This function handles the data received via I2C and passes it to the ProtHdl_RxCtrlBuffHandler
 *  if the current operation mode is master.
 *  \param data The received data character
 *  \return The status of the operation.
 *  \retval E_OK when a whole data set was received.
 *  \retval E_NOT_OK The operation failed.
 */
Std_ReturnType ProtHdl_I2cDataFromSlaveRcvd(char data){

	OpModeDet_TEOpModeType opMode = OpModeDet_GetOpMode();
	Std_ReturnType ret = E_PENDING;

	if (opMode == OpModeDet_TEOpModeType_Master){

		ret = ProtHdl_RxStatusBuffHandler(data);
	}

	return ret;
}

/*!
 *  \brief Handles the received status data
 *
 *  This function handles the received status data.
 *  It is called when the master board receives data from the slave board.
 *  \param data The received data character.
 *  \return The status of the operation.
 *  \retval E_PENDING The operation is pending.
 *  \retval E_OK if the full status data is read and processed.
 */
static Std_ReturnType ProtHdl_RxStatusBuffHandler(char data){

	static bool startCharFound = false;
	Std_ReturnType ret = E_PENDING;

	/// If a full set of status data is read, parse the data to ProtHdl_slaveStatusData
	if (ProtHdl_RxBuffHandler(&ProtHdl_rxStatusDataBuffer[0], data, RXSTATUSDATABUFFER_SIZE, &startCharFound) == true){

		ret = ProtHdl_ParseRxStatusData(&ProtHdl_rxStatusDataBuffer[0], &ProtHdl_slaveStatusData);
		ProtHdl_slaveStatusDataValid = ret;
		/// Clear the buffer
		ProtHdl_rxCtrlDataBuffer[0] = '\0';
	}

	return ret;
}

/*!
 *  \brief Create a copy of the remote control data.
 *
 *  This function creates a copy of the remote control data.
 *  \param remoteCtrlData Remote control data to save the copy in.
 *  \return ProtHdl_remoteCtrlDataValid if the remote control data is valid.
 */
Std_ReturnType ProtHdl_GetRemoteCtrlData(ProtHdl_TSCtrlData* remoteCtrlData){

	memcpy(remoteCtrlData, &ProtHdl_remoteCtrlData, sizeof(ProtHdl_TSCtrlData));

	return ProtHdl_remoteCtrlDataValid;
}

/*!
 *  \brief Reset the remote control data.
 *
 *  This function resets the remote control data by setting ProdHdl_remoteCtrlDataValid to E_NOT_OK
 */
void ProtHdl_ResetRemoteCtrlData(void){

	ProtHdl_remoteCtrlDataValid = E_NOT_OK;
}

/*!
 *  \brief Create a copy of the status data of the slave board.
 *
 *  This function creates a copy of the status data of the slave board.
 *  \param slaveStatusData Status data to save the copy in.
 *  \return ProtHdl_slaveStatusDataValid if the status data is valid.
 */
Std_ReturnType ProtHdl_GetSlaveStatusData(ProtHdl_TSStatusData* slaveStatusData){

	memcpy(slaveStatusData, &ProtHdl_slaveStatusData, sizeof(ProtHdl_TSStatusData));

	return ProtHdl_slaveStatusDataValid;
}

/*!
 *  \brief Handle received control data.
 *
 *  This function puts received control data in the ProtHdl_rxCtrlDataBuffer.
 *  If a whole set of control data is in the buffer, the buffer gets parsed to ProtHdl_remoteCtrlData.
 *  \param data Received control data character.
 *  \return ret if the control data is processed.
 */
static Std_ReturnType ProtHdl_RxCtrlBuffHandler(char data){

	static bool startCharFound = false;
	Std_ReturnType ret = E_PENDING;

	/// If the control data is complete, parse the buffer to ProtHdl_remoteCtrlData
	if (ProtHdl_RxBuffHandler(&ProtHdl_rxCtrlDataBuffer[0], data, RXCTRLDATABUFFER_SIZE, &startCharFound) == true){

		ret = ProtHdl_ParseRxCtrlData(&ProtHdl_rxCtrlDataBuffer[0]);
		/// Reset the buffer
		ProtHdl_rxCtrlDataBuffer[0] = '\0';
	}

	return ret;
}

/*!
 *  \brief Put the received data into the buffer, if the start-character was found.
 *
 *  This function puts the received data into the given buffer, if the start-character was found.
 *  \param buffer The buffer for the received data
 *  \param dataRcvd The received data character
 *  \param bufferSize The size of the Buffer
 *  \param startChrFnd Flag, if a start-character was found
 *  \return ret True, if the process is finished
 */
static bool ProtHdl_RxBuffHandler(char* buffer, char dataRcvd, uint8_t bufferSize, bool* startChrFnd){

	bool ret = false;

	char help[2] = { '\0', '\0' };

	/// check if data is start-character
	if (START_CHAR == dataRcvd){
		buffer[0] = '\0';
		*startChrFnd = true;
	}
	/// check if data is end-character
	else if (END_CHAR == dataRcvd){
		if (true == *startChrFnd){
			/// Data complete
			ret = true;
			*startChrFnd = false;
		}
		else{
			/// End character found without start character
			buffer[0] = '\0';
		}
	}
	else if (true == *startChrFnd){
		/// Copy data to buffer
		help[0] = dataRcvd;
		if (strlcat(&buffer[0], help, bufferSize) == 0){
			/// Buffer full, reset
			*startChrFnd = false;
			buffer[0] = '\0';
		}
	}
	else{
		/// nothing to do
	}

	return ret;
}

/*!
 *  \brief Split the data in the buffer at a ";".
 *
 *  This function splits the data buffer at the token ";" and puts the character in pDataFields.
 *  \param buffer Buffer with the received data
 *  \param pDataFields Data field, where the data from the buffer is saved
 *  \param dataFieldsSize Size of the data field
 *  \return ret E_OK if the process is finished
 */
static Std_ReturnType ProtHdl_SplitRxData(char* buffer, char** pDataFields, uint8_t dataFieldsSize){

	Std_ReturnType ret = E_NOT_OK;
	char *p, *f;
	uint8_t cnt = 0;

	p = &buffer[0];

	for (cnt = 0; cnt < dataFieldsSize; cnt++){
		f = strtok(p, ";");
		if (f != NULL){
			pDataFields[cnt] = f;
		}
		else{
			break;
		}
		/// Next call of strtok needs zero pointer as parameter to proceed with previous string
		p = NULL;
	}

	if (dataFieldsSize == cnt){

		ret = E_OK;
	}

	return ret;
}

/*!
 *  \brief Parse the received control data to ProtHdl_remoteCtrlData
 *
 *  This function parses the received data from the buffer to ProtHdl_remoteCtrlData.
 *  \param buffer The buffer with the received data
 *  \return The status of the operation.
 *  \retval E_OK if the process is finished.
 *  \retval E_NOT_OK The operation failed.
 */
static Std_ReturnType ProtHdl_ParseRxCtrlData(char* buffer){

	bool valid = false;
	Std_ReturnType ret = E_NOT_OK;
	char *pDataFields[CTRLDATA_DATAFIELDS_CNT];
	int data[CTRLDATA_DATAFIELDS_CNT] = { 0 };
	ProtHdl_TEDebugMode debugModeMax = ProtHdl_TEDebugMode_1_3;
	uint8_t cnt = 0;

	/// Get the current operation mode
	OpModeDet_TEOpModeType opMode = OpModeDet_GetOpMode();

	if (OpModeDet_TEOpModeType_Master == opMode){
		debugModeMax = ProtHdl_TEDebugMode_Slave_1_3;
	}

	/// Check if the received message is a calibration request
	if (strncmp(buffer, "TRIGGERCALIBRATION\0", RXCTRLDATABUFFER_SIZE) != 0){

		/// Split the buffer at the token ";"
		ret = ProtHdl_SplitRxData(buffer, &pDataFields[0], CTRLDATA_DATAFIELDS_CNT);

		/// if the split of the data buffer was successful translate the characters to integers
		if (E_OK == ret){
			for (cnt = 0; cnt < CTRLDATA_DATAFIELDS_CNT; cnt++){

				data[cnt] = atoi(pDataFields[cnt]);
				if (0 == cnt){
					/// check if debug mode is valid
					valid = ProtHdl_CheckData(data[cnt], (uint8_t) ProtHdl_TEDebugMode_Nothing, (uint8_t)debugModeMax);
				}
				else{
					/// check the remaining boolean values
					valid &= ProtHdl_CheckData(data[cnt], 0, 1);
				}
			}
		}

		/// If the data is valid, parse the data to ProtHdl_remoteCtrlData
		if (true == valid){
			/* received data seems to be OK */
			ProtHdl_remoteCtrlData.debugMode = (ProtHdl_TEDebugMode)data[0];
			ProtHdl_remoteCtrlData.watchdogSuppression = data[1];
			ProtHdl_remoteCtrlData.debuggerSupply = data[2];
			ProtHdl_remoteCtrlData.relais01 = data[3];
			ProtHdl_remoteCtrlData.relais02 = data[4];
			ProtHdl_remoteCtrlData.extRelais = data[5];
			ret = E_OK;
		}
		else{
			ret = E_NOT_OK;
		}

		ProtHdl_remoteCtrlDataValid = ret;
	}
	/// Only calibrate, if the operation mode is standalone
	else if (OpModeDet_TEOpModeType_Standalone == opMode){
		Calib_SetCalibrationRequest();
		ret = E_OK;
	}

	return ret;
}

/*!
 *  \brief Parse the received status data to statusData
 *
 *  This function parses the received status data from the buffer to the given statusData struct.
 *  \param buffer The buffer with the received status data
 *  \param statusData ProtHdl_TSStatusData, where the status data is saved
 *  \return The status of the operation.
 *  \retval E_NOT_OK The operation failed.
 *  \retval E_OK The operation was successful.
 */
static Std_ReturnType ProtHdl_ParseRxStatusData(char* buffer, ProtHdl_TSStatusData* statusData){

	Std_ReturnType ret = E_NOT_OK;
	char *pDataFields[STATUSDATA_DATAFIELDS_CNT];
	int32_t data[STATUSDATA_DATAFIELDS_CNT] = { 0 };
	uint8_t cnt = 0;
	bool valid = true;
	bool valCheck = true;

	int32_t min, max;

	/// Split the buffer data at the token ";"
	ret = ProtHdl_SplitRxData(buffer, &pDataFields[0], STATUSDATA_DATAFIELDS_CNT);

	if (E_OK == ret){

		for (cnt = 0; (cnt < STATUSDATA_DATAFIELDS_CNT) && (true == valid); cnt++){

			valCheck = true;
			/// Convert the data from char to int
			data[cnt] = atol(pDataFields[cnt]);

			/// Set min and max to the right value
			switch (cnt){

			case 0:
				/// Debug mode
				min = (int32_t) ProtHdl_TEDebugMode_Nothing;
				max = (int32_t) ProtHdl_TEDebugMode_Slave_1_3;
				break;

			case 7:
			case 8:
				/// Current measurement values
				min = -50000;
				max = 50000;
				break;

			case 11:
				/// HW version string conversion
				data[cnt] = (int32_t)VerInfo_HwVarStr2Enum(pDataFields[cnt]);
				min = (int32_t) IoMod_HWVariant_V1_0;
				max = (int32_t) IoMod_HWVariant_V3_0;
				break;

			case 12:
			case 13:
			case 14:
				/// Skip value check for SW version string and slave version strings
				valCheck = false;
				break;

			case 15:
				/// Operation mode
				min = (int32_t) OpModeDet_TEOpModeType_Standalone;
				max = (int32_t) OpModeDet_TEOpModeType_Slave;
				break;

			case 16:
				/// Error status
				min = (int32_t) ErrHdl_ErrorStatus_OK;
				max = (int32_t) (ErrHdl_ErrorStatus_MaxValue);
				break;

			default:
				/// All boolean values
				min = 0;
				max = 1;
				break;
			}

			/// check the data
			if (true == valCheck){

				valid &= ProtHdl_CheckData(data[cnt], min, max);
			}

			ret = E_NOT_OK;
			/// If the data is valid, parse to statusData
			if (true == valid){

				/// Complete RX msg seems to be valid, take over all data
				statusData->debugMode = (ProtHdl_TEDebugMode) data[0];
				statusData->watchdogSuppression = data[1];
				statusData->debuggerSupply = data[2];
				statusData->relais01 = data[3];
				statusData->relais02 = data[4];
				statusData->extRelais = data[5];
				statusData->delaysSet = data[6];
				statusData->currMeasData01 = data[7];
				statusData->currMeasData02 = data[8];
				statusData->calibrationValid = data[9];
				statusData->hwVariant = (IoMod_TEHWVariant) data[11];
				strncpy(statusData->swVersionStr, pDataFields[12], VERINFO_SWVERSION_STR_LENGTH);
				statusData->opMode = (OpModeDet_TEOpModeType) data[15];
				statusData->errorStatus = data[16];
				ret = E_OK;
			}
		}
	}

	return ret;
}

/*!
 *  \brief Check if data is in a given range.
 *
 *  This function checks if data is in the given range between min and max
 *  \param data Data to check
 *  \param min Lower border
 *  \param max Upper border
 *  \return ret Bool if data is in the given range
 */
static bool ProtHdl_CheckData(int32_t data, int32_t min, int32_t max){

	bool ret = false;

	if ((data >= min) && (data <= max)){
		ret = true;
	}

	return ret;
}

/*!
 *  \brief Get the Status data and put it into the txbuffer
 *
 *  This function gets the current status data and writes it into the txbuffer.
 *  \param txBuffer The buffer for the status data
 *  \param bufferSize The size of the buffer
 *  \return The status of the operation.
 *  \retval E_NOT_OK The operation failed.
 *  \retval E_OK The operation was successful.
 */
Std_ReturnType ProtHdl_GetTxStatusData(char* txBuffer, uint8_t bufferSize){

	Std_ReturnType ret = E_NOT_OK;
	bool pinStates[5] = { false };
	int32_t currentMeasData[2];
	ProtHdl_TSCtrlData remoteCtrlData;
	//bool calibValid = false;
	/// Get the current operation mode
	OpModeDet_TEOpModeType opMode = OpModeDet_GetOpMode();
	ProtHdl_TEDebugMode dbgMode = ProtHdl_TEDebugMode_Nothing;

	/// Check if parameters are valid
	if ((txBuffer != NULL) && (bufferSize >= PROTHDL_RS232TXDATASIZE)){

		ret = E_OK;
		txBuffer[0] = '\0';

		/// Check if calibration is running
		if (Calib_IsCalibrationRunning() == false){

			/// Get remote control data
			if (ProtHdl_GetRemoteCtrlData(&remoteCtrlData) == E_OK){

				dbgMode = remoteCtrlData.debugMode;
			}

			/// Read the pin states
			pinStates[0] = IoMod_GetPin(PIN_WATCHDOG_SUPPR);
			pinStates[1] = IoMod_GetPin(PIN_DEBUGGER_SUPPLY);
			pinStates[2] = IoMod_GetPin(PIN_RELAIS_01);
			pinStates[3] = IoMod_GetPin(PIN_RELAIS_02);
			pinStates[4] = IoMod_GetPin(PIN_RELAIS_EXT);
			/// Get the current measurement
			currentMeasData[0] = IoMod_GetCurrentMeasData(0).valueCurrentFilt;
			currentMeasData[1] = IoMod_GetCurrentMeasData(1).valueCurrentFilt;
			//calibValid = Calib_IsCalibrationValid();

			/// Check if in Master/Slave mode
			if (OpModeDet_TEOpModeType_Master == opMode){

				/// in Master/Slave mode debugger supply is always switched from slave HW
				pinStates[1] = ProtHdl_slaveStatusData.debuggerSupply;

				/// Check if there is an active debug mode
				if (dbgMode >= ProtHdl_TEDebugMode_Slave_Nothing){

					/// Get data
					pinStates[0] = ProtHdl_slaveStatusData.watchdogSuppression;
					pinStates[2] = ProtHdl_slaveStatusData.relais01;
					pinStates[3] = ProtHdl_slaveStatusData.relais02;
					pinStates[4] = ProtHdl_slaveStatusData.extRelais;
					currentMeasData[0] = ProtHdl_slaveStatusData.currMeasData01;
					currentMeasData[1] = ProtHdl_slaveStatusData.currMeasData02;
					//calibValid = ProtHdl_slaveStatusData.calibrationValid;
				}
			}

			/// Copy the status data in the txbuffer
			snprintf(txBuffer, bufferSize, "$%d;%d;%d;%d;%d;%d;%d;%+06ld;%+06ld;%d;%d;%s;%s;%s;%s;%d;%03d#",
					dbgMode, pinStates[0], pinStates[1], pinStates[2], pinStates[3], pinStates[4],
					CtrlMod_GetDelaysSet(), currentMeasData[0], currentMeasData[1],
					Calib_IsCalibrationValid(), ProtHdl_slaveStatusData.calibrationValid, VerInfo_GetHwVersion(), VerInfo_GetSwVersion(), VerInfo_Enum2HwVarStr(ProtHdl_slaveStatusData.hwVariant), ProtHdl_slaveStatusData.swVersionStr,
					OpModeDet_GetOpMode(), ErrHdl_GetErrorStatus());
		}
		else{
			strncpy(txBuffer, "#CALIBRATION RUNNING$", bufferSize);
		}
	}

	return ret;
}

/*!
 *  \brief Get the control data and write it into the txbuffer
 *
 *	This function gets the control data and put it into the txbuffer
 *  \param txBuffer The buffer for the control data
 *  \param bufferSize The Size of the buffer
 *  \return The status of the operation.
 *  \retval E_NOT_OK The operation failed.
 *  \retval E_OK The operation was successful.
 */
Std_ReturnType ProtHdl_GetTxCtrlData(char* txBuffer, uint8_t bufferSize){

	Std_ReturnType ret = E_NOT_OK;

	ProtHdl_TSCtrlData ctrlData;

	/// Get the status data of the slave board
	ret = CtrlMod_GetCtrlDataSlave(&ctrlData);

	if ((E_OK == ret) && (txBuffer != NULL) && (bufferSize >= PROTHDL_CTRLDATABUFFER_SIZE)){

		txBuffer[0] = '\0';

		/// Copy the control data into the txbuffer
		snprintf(txBuffer, bufferSize, "$%d;%d;%d;%d;%d;%d#",
				ctrlData.debugMode, ctrlData.watchdogSuppression, ctrlData.debuggerSupply, ctrlData.relais01, ctrlData.relais02, ctrlData.extRelais);
	}

	return ret;
}


