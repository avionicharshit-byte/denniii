/*!
 *  \author		Benjamin Stahl
 *  \author 	stahl04
 *  \version 	1.0
 *  \date		24.08.2021
 */

/*!
 *  \file ErrorHandler.h
 *  \brief Header file for ErrorHandler.cpp
 *
 *  This is the header file for ErrorHandler.cpp
 */

/// Define symbolic constant
#ifndef SOURCE_ERRORHANDLER_H_
#define SOURCE_ERRORHANDLER_H_

/// Include StdTypes for ReturnType
#include "StdTypes.h"

/// Define different error states
#define ErrHdl_ErrorStatus_OK    					 (0x00)
#define ErrHdl_ErrorStatus_MasterTimeoutSlaveComm    (0x01)
#define ErrHdl_ErrorStatus_SlaveTimeoutMasterComm    (0x02)
#define ErrHdl_ErrorStatus_MasterWrongHW             (0x04)
#define ErrHdl_ErrorStatus_SlaveWrongHW              (0x08)
#define ErrHdl_ErrorStatus_PowerSupplyNotConnected	 (0x10)
#define ErrHdl_ErrorStatus_MaxValue                  (ErrHdl_ErrorStatus_MasterTimeoutSlaveComm | ErrHdl_ErrorStatus_SlaveTimeoutMasterComm | ErrHdl_ErrorStatus_MasterWrongHW | ErrHdl_ErrorStatus_SlaveWrongHW | ErrHdl_ErrorStatus_PowerSupplyNotConnected)

/// Function prototypes
void ErrHdl_Init(void);
void ErrHdl_Main(void);
uint16_t ErrHdl_GetErrorStatus(void);


#endif /* SOURCE_ERRORHANDLER_H_ */
