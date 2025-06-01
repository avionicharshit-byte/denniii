/*!
 *  \author 	Benjamin Stahl
 *  \author		stahl04
 *  \version 	1.0
 *  \date 		17.10.2019
 */

/*!
 *  \file ControlModule.h
 *  \brief Header file of ControlModule.cpp
 *
 *  This is the header file for ControlModule.cpp
 */

/// Define symbolic constant
#ifndef SOURCE_CONTROLMODULE_H_
#define SOURCE_CONTROLMODULE_H_

#include "StdTypes.h"
#include "ProtocolHandler.h"

/// Function prototypes
void CtrlMod_Init(void);
void CtrlMod_Main(void);
bool CtrlMod_GetDelaysSet(void);
Std_ReturnType CtrlMod_GetCtrlDataSlave(ProtHdl_TSCtrlData* ctrlDataSlave);

#endif /* SOURCE_CONTROLMODULE_H_ */
