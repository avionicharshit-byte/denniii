/*!
 *  \author    	Benjamin Stahl
 *  \author    	stahl04
 *  \version   	1.0
 *  \date      	08.07.2020
 */

/*!
 *  \file VersionInfo.h
 *  \brief Header file for VersionInof.cpp
 *
 *  This is the Header file for VersionInfo.cpp
 */

/// Define symbolic constant
#ifndef SOURCE_VERSIONINFO_H_
#define SOURCE_VERSIONINFO_H_

/// Define number of HW versions
#define HWVERSION_CNT  (4)

/// Define length of SW version string
#define VERINFO_SWVERSION_STR_LENGTH  (5)

/// Include header file ProtocolHandler.h - Necessary for function prototypes
#include "ProtocolHandler.h"

/// Define function prototypes
const char* VerInfo_GetSwVersion(void);
const char* VerInfo_GetHwVersion(void);
IoMod_TEHWVariant VerInfo_HwVarStr2Enum(char* hwVerStr);
const char* VerInfo_Enum2HwVarStr(IoMod_TEHWVariant hwVar);

#endif /* SOURCE_VERSIONINFO_H_ */
