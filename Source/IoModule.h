/*!
 *  \author 	Benjamin Stahl
 *  \author 	stahl04
 *  \version 	1.0
 *  \date 		14.10.2019
 */

/*!
 *  \file IoModule.h
 *  \brief Header file for IoModule.cpp
 *
 *  This is the header file for IoModule.cpp
 */

/// Define constant for calibration
#ifndef IOMODULE_H_
#define IOMODULE_H_

#include "StdTypes.h"
#include "PinAssign.h"

/// Reference voltage 5V
#define IOMOD_VOLT_REFERENCE   (1023)
/// Channel count
#define IOMOD_CURRMEAS_CHANNEL_CNT      (2)

/// Define different states for the current measurement
typedef enum{
	IoMod_CurrMeasState_Init = 0,
	IoMod_CurrMeasState_OK,
	IoMod_CurrMeasState_Error
} IoMod_TECurrMeasState;

/// Define current measurement data
typedef struct{
	IoMod_TECurrMeasState state;
	uint16_t valueAd;
	uint16_t valueAdFilt;
	int32_t valueCurrent;  ///< Current in  1E-4 A
	int32_t valueCurrentFilt;
	bool limitReached;
	bool limitReachedFilt;
} IoMod_TSCurrMeasData;

/// Define different hardware versions
typedef enum{
	IoMod_HWVariant_V1_0 = 0,
	IoMod_HWVariant_V2_0,
	IoMod_HWVariant_V3_0,
	IoMod_HWVariant_UnDef
}IoMod_TEHWVariant;

/// Function prototypes
void IoMod_Init(void);
void IoMod_Main(void);
bool IoMod_IsPowerSupplyConnected(void);
IoMod_TSCurrMeasData IoMod_GetCurrentMeasData(uint8_t channel);
Std_ReturnType IoMod_AllOutputsOff(void);
Std_ReturnType IoMod_SetPin(uint8_t pinId, bool on);
bool IoMod_GetPin(uint8_t pinId);
IoMod_TEHWVariant IoMod_GetHWVariant(void);

#endif /* IOMODULE_H_ */
