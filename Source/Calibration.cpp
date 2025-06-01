/*!
 *  \author 	Benjamin Stahl
 *  \author 	stahl04
 *  \version	1.0
 *  \date		03.07.2020
 */

/*!
 *  \file Calibration.cpp
 *  \brief
 *
 *  Handle the calibration with the use of a state machine.
 */

#include "Calibration.h"
#include "IoModule.h"
#include "PinAssign.h"
#include <EEPROM.h>
#include "assert.h"

/// Max count of pins to set for calibration
#define CALIB_PIN_CNT_MAX   (6)
/// Validation pattern for calibration
#define CALIB_DATA_VALID_PATTERN   (0x01072008)

#define CALIB_EEPROM_DATA_START_ADDR  (0)

#define CALIB_AD_AVG_CNT   (10)

#define CALIB_WAIT_PRIO_MEAS  (5)
/// Boolean to index mask
#define BOOL2MASK(v, i)   ((v ? 1 : 0) << i)

/**
 * Define different calibration states as enum for state machine
 */
typedef enum{

	IoMod_TECalibState_Idle = 0,		///< Enum value for Idle
	IoMod_TECalibState_Requested,		///< Enum value for Requested
	IoMod_TECalibState_Triggered,		///< Enum value for Triggered
	IoMod_TECalibState_PreStart,		///< Enum value for PreStart
	IoMod_TECalibState_SwitchIOs,		///< Enum value for SwitchIOs
	IoMod_TECalibState_WaitPrioMeas,	///< Enum value for WaitPrioMeas
	IoMod_TECalibState_Measure,			///< Enum value for Measure
	IoMod_TECalibState_CheckMeasure,	///< Enum value for CheckMeasure
	IoMod_TECalibState_StoreEeprom,		///< Enum value for StoreEeprom
	IoMod_TECalibState_Finished			///< Enum value for Finished
}Calib_TECalibState;

/**
 * typedef for Calib_TSEepromData, defines EEprom data
 * @param validPattern
 * @param calibData 2D Array, second dimension is shifted by CALIB_PIN_CNT_MAX (6)
 */
typedef struct{

	uint32_t validPattern;
	int8_t calibData[2][1 << CALIB_PIN_CNT_MAX]; 		///< calibData[channel][pinIndex]
}Calib_TSEepromData;

static_assert(sizeof(Calib_TSEepromData) <= 256, "Arduino Nano Every has only a EEprom of 256 bytes");

static Calib_TECalibState Calib_mainState = IoMod_TECalibState_Idle;	///< Define default state of the CalibState
static Calib_TSEepromData Calib_eepromData = { 0, { { 0 }, { 0 } } };	///< Initialize EEprom data

/// Function prototypes
static Std_ReturnType Calib_CalibrationSM(void);
static Std_ReturnType Calib_ReadEepromData(void);
static Std_ReturnType Calib_WriteEepromData(void);
static uint8_t Calib_GetCurrMeasTblIdx(void);
static void Calib_GetPinIdTable(const uint8_t **tbl, uint8_t *tblSize);

/// Initialize calibration
void Calib_Init(void){

	Calib_ReadEepromData();
}
/// Main function of the calibration
void Calib_Main(void){

	Calib_CalibrationSM();
}

/*!
 *  \brief Triggers the calibration
 *
 *  This function triggers the calibration if no calibration is running and sets the internal calibration
 *  state to IoMod_TECalibState_Triggered.
 *  \return E_OK if the calibration was triggered
 */
Std_ReturnType Calib_TriggerCalibration(void){

	Std_ReturnType ret = E_NOT_OK;

	if ((Calib_IsCalibrationRunning() == false) && (IoMod_GetHWVariant() != IoMod_HWVariant_UnDef)){
		Calib_mainState = IoMod_TECalibState_Triggered;
		ret = E_OK;
	}

	return ret;
}

/*!
 *  \brief Check calibration request
 *
 *  This function checks if a calibration was requested.
 *  \return Boolean if calibration was requested
 */
bool Calib_IsCalibrationRequested(void){

	bool ret = false;
	/// Check internal state
	if (IoMod_TECalibState_Requested == Calib_mainState){

		ret = true;
	}

	return ret;
}

/*!
 *  \brief Checks if calibration is running
 *
 *  This function checks if a calibration is running.
 *  \return Bool if calibration is running
 */
bool Calib_IsCalibrationRunning(void){

	bool ret = false;
	/// Check internal states
	if ((Calib_mainState != IoMod_TECalibState_Idle) && (Calib_mainState != IoMod_TECalibState_Requested)){

		ret = true;
	}

	return ret;
}

/**
 * @brief This function requests calibration
 *
 * This function sets the calibration request state to IoMod_TECalibState_Requested
 * if the current state is IoMod_TECalibState_Idle.
 *
 */
void Calib_SetCalibrationRequest(void){

	if (IoMod_TECalibState_Idle == Calib_mainState){

		Calib_mainState = IoMod_TECalibState_Requested;
	}
}

/*!
 *  \brief Get calibration offset
 *
 *  This function returns the calibration offset for the given channel and saves it in EEprom data.
 *  \param channel
 *  \return offset
 */
int8_t Calib_GetCalibrationOffset(uint8_t channel){

	int8_t offset = 0;
	uint8_t idx = Calib_GetCurrMeasTblIdx();

	if (channel > 1){
		channel = 1;
	}

	if (Calib_IsCalibrationValid() == true){
		offset = Calib_eepromData.calibData[channel][idx];
	}

	return offset;
}

/*!
 *  \brief state machine for the calibration
 *
 *  This function is a state machine for the calibration.
 *  \return ret
 */
static Std_ReturnType Calib_CalibrationSM(void){

	Std_ReturnType ret = E_PENDING;
	static uint16_t calibCntMax = 0;
	static uint16_t calibCnt = 0;
	static uint8_t calibPinCnt = 0;
	static uint32_t measTemp[IOMOD_CURRMEAS_CHANNEL_CNT] = { 0, 0 };
	static const uint8_t *pinIdTbl;
	uint16_t currMeasAd[IOMOD_CURRMEAS_CHANNEL_CNT] = { 0, 0 };
	uint8_t cnt = 0;
	uint8_t idx = 0;
	bool pinOn = false;

	static uint8_t statCnt = 0;
	/// Do tasks depending on internal states
	switch (Calib_mainState){
	/// Do nothing while idle or request
	case IoMod_TECalibState_Idle:
	case IoMod_TECalibState_Requested:
	default:
		break;
	/// Go to state prestart when calibration is triggered
	case IoMod_TECalibState_Triggered:
		Calib_mainState = IoMod_TECalibState_PreStart;
		break;
	/// Prestart calibration
	case IoMod_TECalibState_PreStart:
		calibCnt = 0;
		/// Get the pinIdTbl for the calibration. The calibration will run for each of the pins turned on once.
		Calib_GetPinIdTable(&pinIdTbl, &calibPinCnt);
		calibCntMax = (1 << calibPinCnt);
		/// Set all output pins to false
		IoMod_AllOutputsOff();
		Calib_mainState = IoMod_TECalibState_SwitchIOs;
		break;
	/// Switch on the pin for the current calibration.
	case IoMod_TECalibState_SwitchIOs:
		for (cnt = 0; cnt < calibPinCnt; cnt++){
			pinOn = false;
			/// Check if cnt == calibCnt and set the pin to on, if true
			if ((calibCnt & (1 << cnt)) != 0){
				pinOn = true;
			}
			IoMod_SetPin(pinIdTbl[cnt], pinOn);
		}
		statCnt = CALIB_WAIT_PRIO_MEAS;
		Calib_mainState = IoMod_TECalibState_WaitPrioMeas;
		break;
	/// Wait before the measurement
	case IoMod_TECalibState_WaitPrioMeas:
		if (statCnt == 0){
			measTemp[0] = 0;
			measTemp[1] = 0;
			Calib_mainState = IoMod_TECalibState_Measure;
		}
		else{
			statCnt--;
		}
		break;
	/// Measurement for the calibration
	case IoMod_TECalibState_Measure:
		/// Add all measurements for averaging
		if (statCnt < CALIB_AD_AVG_CNT){
			measTemp[0] += analogRead(PIN_CURRENT_MEAS_01);
			measTemp[1] += analogRead(PIN_CURRENT_MEAS_02);
			statCnt++;
		}
		else{
			/// Get the index for the current calibration
			idx = Calib_GetCurrMeasTblIdx();
			/// Calculate the average measurement for each channel
			for (cnt = 0; cnt < IOMOD_CURRMEAS_CHANNEL_CNT; cnt++){
				currMeasAd[cnt] = measTemp[cnt] / statCnt;
				/// Save the calibration data in the EEprom
				Calib_eepromData.calibData[cnt][idx] = (int8_t)((IOMOD_VOLT_REFERENCE / 2) - currMeasAd[cnt]);
			}
			Calib_mainState = IoMod_TECalibState_CheckMeasure;
		}
		break;

	case IoMod_TECalibState_CheckMeasure:
		Calib_mainState = IoMod_TECalibState_SwitchIOs;
		calibCnt++;
		/// Store the EEprom only if all calibrations are done, so calibCnt == calibCntMax
		if (calibCntMax == calibCnt){
			Calib_mainState = IoMod_TECalibState_StoreEeprom;
		}
		break;
	/// Store calibration data in EEprom storage
	case IoMod_TECalibState_StoreEeprom:
		Calib_WriteEepromData();
		Calib_mainState = IoMod_TECalibState_Finished;
		break;
	/// Calibration finished
	case IoMod_TECalibState_Finished:
		IoMod_AllOutputsOff();
		Calib_mainState = IoMod_TECalibState_Idle;
		ret = E_OK;
		break;
	}

	return ret;
}

/*!
 *  \brief Get the index of the current measurement table
 *
 *  tblIdx is initially 0, the for loop iterates to tblSize-1 and uses IoMod_GetPin
 *  to check if the pin has a signal > 0. Then a bit is set by the BOOL2MASK macro
 *  \return tblIdx
 */
static uint8_t Calib_GetCurrMeasTblIdx(void){

	uint8_t tblIdx = 0;
	uint8_t cnt = 0;
	uint8_t tblSize;
	const uint8_t* pinIdTbl;

	Calib_GetPinIdTable(&pinIdTbl, &tblSize);

	for (cnt = 0; cnt < tblSize; cnt++){
		/// Get the index of the active pin
		/// If the pin is on, GetPin returns true, and BOOL2MASK returns the index mask of the pin
		tblIdx |= BOOL2MASK(IoMod_GetPin(pinIdTbl[cnt]), cnt);
	}

	return tblIdx;
}

/// Read the EEprom data to Calilb_eepromData
static Std_ReturnType Calib_ReadEepromData(void){

	EEPROM.get(CALIB_EEPROM_DATA_START_ADDR, Calib_eepromData);

	return E_OK;
}

/// Write Calib_eepromData to the EEprom
static Std_ReturnType Calib_WriteEepromData(void){

	Calib_eepromData.validPattern = CALIB_DATA_VALID_PATTERN;
	EEPROM.put(CALIB_EEPROM_DATA_START_ADDR, Calib_eepromData);

	return E_OK;
}

/// Get the pin id table with the different pins to switch for the calibration
static void Calib_GetPinIdTable(const uint8_t **tbl, uint8_t *tblSize){

	/// Set pinIdTbl and pinIdTblsSize
	static const uint8_t Calib_pinIdTbl[] = { PIN_DEBUG1_DEBUG2_ENABLE, PIN_DEBUG1_DEBUG3_ENABLE, PIN_WATCHDOG_SUPPR, PIN_DEBUGGER_SUPPLY, PIN_RELAIS_01, PIN_RELAIS_02 };
	static const uint8_t Calib_pinIdTblSize = sizeof(Calib_pinIdTbl) / sizeof(uint8_t);

	/// For HW variant V3.0 debug modes do not care because of multiplexer concept
	static const uint8_t Calib_pinIdTblV3[] = { PIN_WATCHDOG_SUPPR, PIN_DEBUGGER_SUPPLY, PIN_RELAIS_01, PIN_RELAIS_02 };
	static const uint8_t Calib_pinIdTblV3Size = sizeof(Calib_pinIdTblV3) / sizeof(uint8_t);

	/// Set tbl and tblSize depending on board version
	if (IoMod_GetHWVariant() == IoMod_HWVariant_V3_0){

		*tbl = &Calib_pinIdTblV3[0];
		*tblSize = Calib_pinIdTblV3Size;
	}
	else{

		*tbl = &Calib_pinIdTbl[0];
		*tblSize = Calib_pinIdTblSize;
	}
}

/// Checks if the calibration is valid by checking validation pattern
bool Calib_IsCalibrationValid(void){

	bool ret = false;

	if (CALIB_DATA_VALID_PATTERN == Calib_eepromData.validPattern){

		ret = true;
	}

	return ret;
}


