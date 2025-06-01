/*!
 *  \author 	Benjamin Stahl
 *  \author 	stahl04
 *  \version 	1.0
 *  \date		03.07.2020
 */

/*!
 *  \file Calibration.h
 *  \brief Header file for Calibration.cpp
 *
 *  This is the header file for Calibration.cpp
 */

/// Define constant for calibration
#ifndef SOURCE_CALIBRATION_H_
#define SOURCE_CALIBRATION_H_

/// Include StdTypes header, needed for Std_ReturnType
#include "StdTypes.h"

/// Function prototypes
void Calib_Init(void);
void Calib_Main(void);
bool Calib_IsCalibrationRequested(void);
bool Calib_IsCalibrationRunning(void);
bool Calib_IsCalibrationValid(void);
void Calib_SetCalibrationRequest(void);
Std_ReturnType Calib_TriggerCalibration(void);
int8_t Calib_GetCalibrationOffset(uint8_t channel);

#endif /* SOURCE_CALIBRATION_H_ */
