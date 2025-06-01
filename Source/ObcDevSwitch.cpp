/*!
 *  \author Benjamin Stahl
 *  \author stahl04
 *  \version 1.0
 *  \date 22.07.2020
 */

/*!
 *  \file ObcDevSwitch.cpp
 *  \brief Main file of the software.
 *
 *  This is the main file of the software.
 */
#include "ObcDevSwitch.h"
#include "IoModule.h"
#include "SerialCommunication.h"
#include "ControlModule.h"
#include "Calibration.h"
#include "InterBoardComm.h"
#include "ProtocolHandler.h"
#include "OperationModeDetection.h"
#include "ErrorHandler.h"

#define MS10_THRESHOLD   (10000)

static void Mainloop(void);

/// The setup function is called once at startup of the sketch
void setup()
{
	SerCom_Init();
	/// To be called prior to all other modules
	IoMod_Init();
	/// To be called direct after IoMod
	OpModeDet_Init();
	ErrHdl_Init();
	CtrlMod_Init();
	Calib_Init();
	IntBrdComm_Init();
	ProtHdl_Init();
}

/// The loop function is called in an endless loop
void loop()
{
	SerCom_Main();
	IoMod_Main();
	OpModeDet_Main();
	ErrHdl_Main();
	CtrlMod_Main();
	Calib_Main();
	IntBrdComm_Main();
	ProtHdl_Main();

	/// Last call in the loop
	Mainloop();
}

/// Time management
static void Mainloop(){

	static uint32_t timeOld = 0;
	uint32_t time = 0;

	do{
		time = micros();
	}
	while (time - timeOld < MS10_THRESHOLD);
	timeOld = time;
}
