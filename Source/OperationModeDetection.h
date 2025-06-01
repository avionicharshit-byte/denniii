/*!
 *  \author 	Benjamin Stahl
 *  \author 	stahl04
 *  \version 	1.0
 *  \date		20.08.2021
 */

/*!
 *  \file OperationModeDetection.h
 * 	\brief Header file for OperationModeDetection.cpp
 *
 * 	This file is the header file for OperationModeDetection.cpp
 */

/// Define symbolic constants
#ifndef SOURCE_OPERATIONMODEDETECTION_H_
#define SOURCE_OPERATIONMODEDETECTION_H_

/// Define the different operation modes
typedef enum{
	OpModeDet_TEOpModeType_Standalone = 0,
	OpModeDet_TEOpModeType_Master = 1,
	OpModeDet_TEOpModeType_Slave = 2,
	OpModeDet_TEOpModeType_NotAvailable = 3
}OpModeDet_TEOpModeType;

/// Function prototypes
void OpModeDet_Init(void);
void OpModeDet_Main(void);
OpModeDet_TEOpModeType OpModeDet_GetOpMode(void);


#endif /* SOURCE_OPERATIONMODEDETECTION_H_ */
