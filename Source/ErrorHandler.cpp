/*!
 *  \author 	Benjamin Stahl
 *  \author 	stahl04
 *  \version 	1.0
 *  \date 		24.08.2021
 */

/*!
 *  \file ErrorHandler.cpp
 *  \brief Handles error states of the software
 *
 *  This file handles the different error states of the software.
 */

#include "ErrorHandler.h"
#include "IoModule.h"
#include "OperationModeDetection.h"
#include "ProtocolHandler.h"
#include "InterBoardComm.h"

/// Define errorStatus and initialize it with Status "OK"
static uint8_t ErrHdl_errorStatus = ErrHdl_ErrorStatus_OK;

void ErrHdl_Init(void){

}

/**
 * Main function of the error handler.
 * @param void
 * @return errorStatus
 */
void ErrHdl_Main(void){

	/// Get current operation mode
	OpModeDet_TEOpModeType opMode = OpModeDet_GetOpMode();
	/// Get the HW variant
	IoMod_TEHWVariant hwVariant = IoMod_GetHWVariant();
	ProtHdl_TSStatusData slaveStatusData;
	Std_ReturnType ret = E_NOT_OK;
	uint8_t errorTemp = ErrHdl_ErrorStatus_OK;
	bool pwrSupplCon = false;

	/// Get the slave status data
	ret = ProtHdl_GetSlaveStatusData(&slaveStatusData);
	/// Check power supply connection
	pwrSupplCon = IoMod_IsPowerSupplyConnected();

	/// Check error state of the slave board if in operation mode master
	if ((E_OK == ret) && (OpModeDet_TEOpModeType_Master == opMode)){

		errorTemp |= slaveStatusData.errorStatus;
	}

	/// Check if the wrong HW version is in operation mode master
	if ((OpModeDet_TEOpModeType_Master == opMode) && (IoMod_HWVariant_V3_0 != hwVariant)){
		/// Only "Aurix Board" can be master in combined operation mode
		errorTemp |= ErrHdl_ErrorStatus_MasterWrongHW;
	}

	/// Check if the wrong HW version is in operation mode slave
	if ((OpModeDet_TEOpModeType_Slave == opMode) && (IoMod_HWVariant_V3_0 == hwVariant)){
		/// Only "RH850 Board" can be slave in combined operation mode
		errorTemp |= ErrHdl_ErrorStatus_SlaveWrongHW;
	}
	/// Check if inter board communication timeout is active
	if (IntBrdComm_CommTimeoutActive() == true){
		if (OpModeDet_TEOpModeType_Master == opMode){
			/// Master board detects communication timeout from slave
			errorTemp |= ErrHdl_ErrorStatus_MasterTimeoutSlaveComm;
		}
		else if (OpModeDet_TEOpModeType_Slave == opMode){
			/// Slave board detects communication timeout from master
			errorTemp |= ErrHdl_ErrorStatus_SlaveTimeoutMasterComm;
		}
	}
	/// Check if the power supply is not connected
	if (false == pwrSupplCon){
		errorTemp |= ErrHdl_ErrorStatus_PowerSupplyNotConnected;
	}

	ErrHdl_errorStatus = errorTemp;
}

/// Get the error state
uint16_t ErrHdl_GetErrorStatus(void){

	return ErrHdl_errorStatus;
}
