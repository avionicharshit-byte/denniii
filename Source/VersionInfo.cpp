/*!
 *  \author    	Benjamin Stahl
 *  \author    	stahl04
 *  \version   	1.0
 *  \date      	08.07.2020
 */

/*!
 *  \file VersionInfo.cpp
 *  \brief Handle Hardware (HW) and Software (SW) versions.
 *
 *  This program section is about handling the several board versions
 *  and board types.
 */

#include "StdTypes.h"
#include "VersionInfo.h"
#include "IoModule.h"

/// Array for the Hardware version strings
static const char VerInfo_hwVersionStr[HWVERSION_CNT][4] = { "1.0", "2.0", "3.0", "N/A" };

/*!
 *  Get SW version.
 *
 *  \param void
 *  \return swVersion
 */
const char* VerInfo_GetSwVersion(void){

/// Depending on used Arduino get Software version string with suffix 'E' or with 'N'
#ifdef ARDUINO_AVR_NANO_EVERY
	static const char swVersion[VERINFO_SWVERSION_STR_LENGTH] = "4.0E";
#else
	static const char swVersion[VERINFO_SWVERSION_STR_LENGTH] = "4.0N";
#endif

	return swVersion;
}

/*!
 *  Get HW version.
 *
 *  \param void
 *  \return VerInof_hwVersionStr[hwVar]
 */
const char* VerInfo_GetHwVersion(void){

	IoMod_TEHWVariant hwVar = IoMod_GetHWVariant();

	return VerInfo_hwVersionStr[hwVar];
}

/*!
 *  Convert HW version string to Enum
 *
 *  \param char* hwVerStr
 *  \return hwVersion
 */
IoMod_TEHWVariant VerInfo_HwVarStr2Enum(char* hwVerStr){

	IoMod_TEHWVariant hwVersion = IoMod_HWVariant_UnDef;
	uint8_t cnt = 0;

	for (cnt = 0; (cnt < HWVERSION_CNT) && (IoMod_HWVariant_UnDef == hwVersion); cnt++){

		if (strcmp(hwVerStr, VerInfo_hwVersionStr[cnt]) == 0){

			hwVersion = (IoMod_TEHWVariant) cnt;
		}
	}

	return hwVersion;
}

/*!
 *  Convert Enum to HW version string
 *
 *  \param IoMod_TEHWVariant hwVar
 *  \return VerInfo_hwVersionStr[hwVar]
 */
const char* VerInfo_Enum2HwVarStr(IoMod_TEHWVariant hwVar){

	return VerInfo_hwVersionStr[hwVar];
}

