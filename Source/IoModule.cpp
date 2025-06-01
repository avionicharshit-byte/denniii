/*!
 *  \author 	Benjamin Stahl
 *  \author 	stahl04
 *  \version 	1.0
 *  \date		14.10.2019
 */

/*!
 *  \file IoModule.cpp
 *  \brief Handles the in- and output of the arduino board
 *
 *  This file handles the in- and output of the arduino board
 */

#include "Arduino.h"
#include "IoModule.h"
#include "PinAssign.h"
#include "Calibration.h"
#include "math.h"

/// Powersupply detection threshold ca. 1V
#define POWERSUPPL_DETECT_THRESHOLD (200)

/// ADC reference voltage differs on board type
#ifdef ARDUINO_AVR_NANO_EVERY
#define ADCREF   VDD
#else
#define ADCREF   DEFAULT
#endif

/// Define current measurement data int
typedef struct{
	IoMod_TSCurrMeasData measData;
	const uint8_t pin;
	uint16_t filterHelp;
	bool filterInitDone;
} IoMod_TSCurrMeasDataInt;

/// Create two current measurement data int structs
static IoMod_TSCurrMeasDataInt IoMod_currMeasData[IOMOD_CURRMEAS_CHANNEL_CNT] = { { {IoMod_CurrMeasState_Init, 0, 0, 0, 0, false, false }, PIN_CURRENT_MEAS_01, 0, false },
		{ {IoMod_CurrMeasState_Init, 0, 0, 0, 0, false, false }, PIN_CURRENT_MEAS_02, 0, false } } ;

static bool IoMod_powerSupply = false;
static IoMod_TEHWVariant IoMod_hwVariant = IoMod_HWVariant_UnDef;

/// Function prototypes
static void IoMod_InitPorts(void);
static int32_t IoMod_CalcCurrent(uint16_t adValue, uint16_t zeroPoint, bool* limitReached);
static void IoMod_CurrentMeasMain(void);
static void IoMod_CurrentMeas(IoMod_TSCurrMeasDataInt* data, int8_t calibOffset);
static void IoMod_VariantDetection(void);
static void IoMod_InitPortsHwVar(void);
static void IoMod_PowerSupplyDetection(void);

/// Initialization of the ports
void IoMod_Init(void){

	IoMod_InitPorts();
}

/// Main function
void IoMod_Main(void){

	IoMod_CurrentMeasMain();
	IoMod_VariantDetection();
	IoMod_PowerSupplyDetection();
}

/*!
 *  \brief Init all ports of the arduino.
 *
 *  This function initializes all digital and analog pins of the arduino board.
 */
static void IoMod_InitPorts(void){

	uint8_t cnt = 0;

	/// Set the ADC reference to 5V supply
	analogReference(ADCREF);

	/// Init analog ports as inputs
	for (cnt = 0; cnt < IOMOD_CURRMEAS_CHANNEL_CNT; cnt++){
		pinMode(IoMod_currMeasData[cnt].pin, INPUT);
	}
	pinMode(PIN_POWER_SUPPLY_DETECTION, INPUT);
	pinMode(PIN_VARIANT_DETECTION, INPUT);

	/// Init digital inputs
	pinMode(PIN_DTMBOARD_DETECTION, INPUT_PULLUP);
	pinMode(PIN_INTERBOARD_MASTER_DETECTION, INPUT_PULLUP);

	/// Init digital outputs
	pinMode(PIN_DEBUG1_DEBUG2_ENABLE, OUTPUT);
	pinMode(PIN_DEBUG1_DEBUG3_ENABLE, OUTPUT);
	pinMode(PIN_WATCHDOG_SUPPR, OUTPUT);
	pinMode(PIN_DEBUGGER_SUPPLY, OUTPUT);
	pinMode(PIN_RELAIS_01, OUTPUT);
	pinMode(PIN_RELAIS_02, OUTPUT);
	pinMode(PIN_RELAIS_EXT, OUTPUT);
	pinMode(PIN_DTMBOARD_SELECT, OUTPUT);

	/// Set digital outputs
	IoMod_AllOutputsOff();
}

/*!
 *  \brief Init Pins for V3 Board.
 *
 *  This function initializes the extra multiplexer pins for the V3 Board.
 */
static void IoMod_InitPortsHwVar(void){

	if (IoMod_HWVariant_V3_0 == IoMod_hwVariant){

		pinMode(PIN_MULTIPLEX_OUTP_SELECT, OUTPUT);
		pinMode(PIN_MULTIPLEX_ENABLE, OUTPUT);
		IoMod_SetPin(PIN_MULTIPLEX_OUTP_SELECT, false);
		/// Low active
		IoMod_SetPin(PIN_MULTIPLEX_ENABLE, true);
	}
}

/*!
 *  \brief Detect the power supply
 *
 *  This function checks if the power supply is connected
 */
static void IoMod_PowerSupplyDetection(void){

	bool powSupDet = false;

	/// Check for connected power supply - Note: Port A6 is only available as analog input on Arduino Nano
	if (analogRead(PIN_POWER_SUPPLY_DETECTION) < POWERSUPPL_DETECT_THRESHOLD){
		powSupDet = true;
	}

	IoMod_powerSupply = powSupDet;
}

/*!
 *  \brief Main function for the current measurement.
 *
 *  This is the main function for the current measurement.
 */
static void IoMod_CurrentMeasMain(){

	uint8_t cnt = 0;
	int8_t offset = 0;

	/// Execute current measurement
	for (cnt = 0; cnt < IOMOD_CURRMEAS_CHANNEL_CNT; cnt++){

		offset = Calib_GetCalibrationOffset(cnt);
		IoMod_CurrentMeas(&IoMod_currMeasData[cnt], offset);
	}
}

/*!
 *  \brief Handles the current measurement
 *
 *  This function handles the current measurement.
 *  \param data Data where the measurement information is saved
 *  \param calibOffset Calibrated current offset
 */
static void IoMod_CurrentMeas(IoMod_TSCurrMeasDataInt* data, int8_t calibOffset){

	const uint16_t zeroPoint = (const uint16_t)(IOMOD_VOLT_REFERENCE / 2);

	/// Measure the reference voltage from the current measurement IC
	data->measData.valueAd = analogRead(data->pin) + calibOffset;
	data->measData.valueCurrent = IoMod_CalcCurrent(data->measData.valueAd, zeroPoint, &data->measData.limitReached);

	if (true == data->filterInitDone){
		/// Let's filter (delay) the AD value for 200 ms if changed
		if (data->measData.valueAdFilt != data->measData.valueAd){
			if (data->filterHelp < 20){
				data->filterHelp++;
			}
			else{
				data->measData.valueAdFilt = data->measData.valueAd;
			}
		}
		else{
			data->filterHelp = 0;
		}
		/// Calculate the current for valueCurrentFilt. The filtered value is for stabilizing the current when the measurement flicker
		data->measData.valueCurrentFilt = IoMod_CalcCurrent(data->measData.valueAdFilt, zeroPoint, &data->measData.limitReachedFilt);
		data->measData.state = IoMod_CurrMeasState_Init;
	}
	/// Init the filter
	else{
		data->measData.valueAdFilt = zeroPoint;
		data->measData.valueCurrentFilt = 0;
		data->filterInitDone = true;
	}
}

/*!
 *  \brief Calculate the current value from the ad value.
 *
 *  This function calculates the current value from the ad value.
 *  \param adValue AD value of the current
 *  \param zeroPnt Zeropoint of the AD value
 *  \param limitReached Bool to check if the limit was reached
 *  \return ret Current in 1e-4 A
 */
static int32_t IoMod_CalcCurrent(uint16_t adValue, uint16_t zeroPnt, bool* limitReached){

	/// Calculate the current value from the ad value, 1 AD digit --> 26,5 mA
	int32_t ret = (int32_t)(((int32_t)adValue - (int32_t)zeroPnt) * 264);

	*limitReached = false;

	/// Check if the limit is reached
	if (ret < -50000){
		ret = -50000;
		*limitReached = true;
	}

	if (ret > 50000){
		ret = 50000;
		*limitReached = true;
	}

	return ret;
}
/*!
 *  \brief Detect the HW variant.
 *
 *  This function detects the Hardware variant of the board.
 */
static void IoMod_VariantDetection(void){
	uint16_t adValue = 0;
	static uint8_t cnt = 3;

	if ((cnt > 0) && (cnt != 0xFF)){
		/** Switch detection pin to GND for some time as HW V1.0 has no variant detection resistors on-board
		 * So the AD pin is floating. Not a nice solution, I know!!!
		 */
		pinMode(PIN_VARIANT_DETECTION, OUTPUT);
		IoMod_SetPin(PIN_VARIANT_DETECTION, false);
		cnt--;
	}
	else if (0 == cnt){
		pinMode(PIN_VARIANT_DETECTION, INPUT);
		adValue = analogRead(PIN_VARIANT_DETECTION);

		/// HW2.0 detected
		if ((adValue >= 920) && (adValue <= 940)){
			/// 1k - 10k
			IoMod_hwVariant = IoMod_HWVariant_V2_0;
		}
		/// HW3.0 detected
		else if ((adValue >= 880) && (adValue <= 900)){
			/// 1k5 - 10k
			IoMod_hwVariant = IoMod_HWVariant_V3_0;
		}
		/// HW1.0 detected
		else if (adValue < 500){
			IoMod_hwVariant = IoMod_HWVariant_V1_0;
		}
		/// If no condition matches, then the default value is active and the default value 'IoMod_HWVariant_UnDef' will stay active

		///  Do some HW specific stuff, as HW variant is now available
		IoMod_InitPortsHwVar();

		/// Do it only once
		cnt = 0xFF;
	}
}

/// Get the HW variant
IoMod_TEHWVariant IoMod_GetHWVariant(void){

	return IoMod_hwVariant;
}

/// Check if the power supply is connected
bool IoMod_IsPowerSupplyConnected(void){

	return IoMod_powerSupply;
}

/*!
 *  \brief Get the current measurement data.
 *
 *  This function returns the current measurement data.
 *  \param channel Current measurement channel
 *  \return IoMod_currentMeasData[channel].measData Current measurement data of the given current channel
 */
IoMod_TSCurrMeasData IoMod_GetCurrentMeasData(uint8_t channel){

	if (channel > IOMOD_CURRMEAS_CHANNEL_CNT - 1){
		channel = IOMOD_CURRMEAS_CHANNEL_CNT - 1;
	}

	return IoMod_currMeasData[channel].measData;
}

/*!
 *  \brief Set all outputs to false.
 *
 *  This function sets all output pins to false.
 *  \return ret E_OK
 */
Std_ReturnType IoMod_AllOutputsOff(void){

	IoMod_SetPin(PIN_DEBUG1_DEBUG2_ENABLE, false);
	IoMod_SetPin(PIN_DEBUG1_DEBUG3_ENABLE, false);
	IoMod_SetPin(PIN_WATCHDOG_SUPPR, false);
	IoMod_SetPin(PIN_DEBUGGER_SUPPLY, false);
	IoMod_SetPin(PIN_RELAIS_01, false);
	IoMod_SetPin(PIN_RELAIS_02, false);
	IoMod_SetPin(PIN_RELAIS_EXT, false);
	IoMod_SetPin(PIN_MULTIPLEX_ENABLE, true);    /* low active */
	IoMod_SetPin(PIN_MULTIPLEX_OUTP_SELECT, false);
	IoMod_SetPin(PIN_DTMBOARD_SELECT, false);

	return E_OK;
}

/*!
 *  \brief Set the given pin to the value of on
 *
 *  This function sets the given pin to the value of on.
 *  \param pinId Id of the pin to set
 *  \param on Wanted state of the pin
 *  \return ret E_OK
 */
Std_ReturnType IoMod_SetPin(uint8_t pinId, bool on){

	/// Multiplexer pins are only available on HW variant V3
	if ((IoMod_HWVariant_V3_0 == IoMod_hwVariant) ||
			((pinId != PIN_MULTIPLEX_ENABLE) && (pinId != PIN_MULTIPLEX_OUTP_SELECT))){
		digitalWrite(pinId, on);
	}

	return E_OK;
}

/*!
 *  \brief Returns the state of the given pin
 *
 *  This function returns the state of the given pin
 *  \param pinId Id of the pin to get the state of
 *  \return ret State of the pin
 */
bool IoMod_GetPin(uint8_t pinId){

	int read = digitalRead(pinId);
	bool ret = false;

	if (read > 0){
		ret = true;
	}

	return ret;
}
