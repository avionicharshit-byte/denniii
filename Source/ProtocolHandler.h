/*!
 *  \author    	Benjamin Stahl
 *  \author    	stahl04
 *  \version   	1.0
 *  \date	   	20.08.2021
 */

/*!
 * \file ProtocolHandler.h
 * \brief Header file for ProtocolHandler.cpp
 *
 * This is the header file for ProtocolHandler.cpp
 */

/// Define symbolic constant
#ifndef SOURCE_PROTOCOLHANDLER_H_
#define SOURCE_PROTOCOLHANDLER_H_

/// include header files
#include "StdTypes.h"
#include "IoModule.h"
#include "VersionInfo.h"
#include "OperationModeDetection.h"
#include "ErrorHandler.h"


/*!
 * \brief Enum of the different debugging modes.
 *
 * ProtHdl_TEDebugMode is an enum type with the different debug modes.
 */
typedef enum{

	ProtHdl_TEDebugMode_Nothing = 0,		///< No debug mode (Operation Mode Master/Standalone)
	ProtHdl_TEDebugMode_1_2,				///< Debug mode Debug1 to Debug2 (Operation Mode Master/Standalone)
	ProtHdl_TEDebugMode_1_3,				///< Debug mode Debug1 to Debug3 (Operation Mode Master/Standalone)
	ProtHdl_TEDebugMode_Slave_Nothing,		///< No debug mode (Operation Mode Slave)
	ProtHdl_TEDebugMode_Slave_1_2,			///< Debug mode Debug1 to Debug2 (Operation Mode Slave)
	ProtHdl_TEDebugMode_Slave_1_3,			///< Debug mode Debug1 to Debug3 (Operation Mode Slave)
}ProtHdl_TEDebugMode;

/*!
 *  \brief Struct with the control data.
 *
 *  ProtHdl_TSCtrlData is a struct with all different elements of the control data.
 */
typedef struct{

	ProtHdl_TEDebugMode debugMode;			///< Selected debug mode
	bool watchdogSuppression;				///< Is the watchdog suppression active?
	bool debuggerSupply;					///< Is the Debugger supply active?
	bool relais01;							///< State of relais 1
	bool relais02;							///< State of relais 2
	bool extRelais;							///< External port active?
	bool calibRequest;						///< Is there a calibration request?
}ProtHdl_TSCtrlData;

/*!
 *  \brief Struct with the status data.
 *
 *  ProtHdl_TSStatusData is a struct with all different elements of the status data.
 */
typedef struct{

	ProtHdl_TEDebugMode debugMode;
	bool watchdogSuppression;
	bool debuggerSupply;
	bool relais01;
	bool relais02;
	bool extRelais;
	bool delaysSet;
	int32_t currMeasData01;
	int32_t currMeasData02;
	bool calibrationValid;
	IoMod_TEHWVariant hwVariant;
	char swVersionStr[VERINFO_SWVERSION_STR_LENGTH];
	OpModeDet_TEOpModeType opMode;
	uint8_t errorStatus;
}ProtHdl_TSStatusData;

/// Initial values for the control data and status data
#define PROTHDL_CTRLDATA_STRUCT_INIT      { ProtHdl_TEDebugMode_Nothing, false, false, false, false, false, false }
#define PROTHDL_STATUSDATA_STRUCT_INIT    { ProtHdl_TEDebugMode_Nothing, false, false, false, false, false, false, 0, 0, false, IoMod_HWVariant_UnDef, "N/A", OpModeDet_TEOpModeType_NotAvailable, 0 }

/// Size of the send data
#define PROTHDL_RS232TXDATASIZE  (58)
#define PROTHDL_SLAVETXDATASIZE  PROTHDL_RS232TXDATASIZE    /* same data msg as for RS232 */

/// Size of the control data buffer
#define PROTHDL_CTRLDATABUFFER_SIZE   (20)

/// Define function prototypes
void ProtHdl_Init(void);
void ProtHdl_Main(void);
Std_ReturnType ProtHdl_Rs232DataRcvd(char data);
Std_ReturnType ProtHdl_GetRemoteCtrlData(ProtHdl_TSCtrlData* remoteCtrlData);
void ProtHdl_ResetRemoteCtrlData(void);
Std_ReturnType ProtHdl_GetSlaveStatusData(ProtHdl_TSStatusData* slaveStatusData);
Std_ReturnType ProtHdl_I2cDataFromMasterRcvd(char data);
Std_ReturnType ProtHdl_I2cDataFromSlaveRcvd(char data);
Std_ReturnType ProtHdl_GetTxStatusData(char* txBuffer, uint8_t bufferSize);
Std_ReturnType ProtHdl_GetTxCtrlData(char* txBuffer, uint8_t bufferSize);

#endif /* SOURCE_PROTOCOLHANDLER_H_ */
