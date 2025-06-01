/*!
 *  \author 	Benjamin Stahl
 *  \author 	stahl04
 *  \version 	1.0
 *  \date 		20.08.2021
 */

/*!
 *  \file OperationModeDetection.cpp
 *  \brief Handle the detection of the active operation mode
 *
 *  This file handles the detection of the active operation mode of the board.
 */

#include "OperationModeDetection.h"
#include "IoModule.h"
#include "PinAssign.h"

/// Initialize operation mode with NotAvailable
static OpModeDet_TEOpModeType OpModeDet_opMode = OpModeDet_TEOpModeType_NotAvailable;

static void OpModeDet_DetectOpMode(void);

/// Get the operation mode for initialization
void OpModeDet_Init(void){

	OpModeDet_DetectOpMode();
}

/// Main function. It refreshes the active operation mode
void OpModeDet_Main(void){

	/// Operation mode detection shall be done all the time
	OpModeDet_DetectOpMode();
}

/// Returns the active operation mode
OpModeDet_TEOpModeType OpModeDet_GetOpMode(void){

	return OpModeDet_opMode;
}

/*!
 *  \brief Detection of the active operation mode
 *
 *  This function detects the active operation mode
 */
static void OpModeDet_DetectOpMode(void){

	/// Previous operation mode
	static OpModeDet_TEOpModeType opModeOld = OpModeDet_TEOpModeType_NotAvailable;

	/// Check if DTM Board is detected
	if (IoMod_GetPin(PIN_DTMBOARD_DETECTION) == false){
		/// PIN is set to GND if DTM Board is connected
		OpModeDet_opMode = OpModeDet_TEOpModeType_Slave;
		/// Check if DTM Board is connected to the master port
		if (IoMod_GetPin(PIN_INTERBOARD_MASTER_DETECTION) == false){
			/// PIN is set to GND if DTM Board is connected to master port
			OpModeDet_opMode = OpModeDet_TEOpModeType_Master;
		}
	}
	else{
		OpModeDet_opMode = OpModeDet_TEOpModeType_Standalone;
	}

	/// Check if operation mode has changed
	if (opModeOld != OpModeDet_opMode){
		/// Send detected operation mode on serial line for debugging purposes
		Serial.print("Operation mode: ");
		Serial.println(OpModeDet_opMode);
	}
	/// Update the previous operating mode
	opModeOld = OpModeDet_opMode;
}
