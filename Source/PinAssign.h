/*!
 *  \author		Benjamin Stahl
 *  \author    	stahl04
 *  \version   	1.0
 *  \date      	15.10.2019
 */

/*!
 *  \file PinAssign.h
 * 	\brief Header file for PinAssign.cpp
 *
 * 	This is the header file for assigning the pins
 */

/// Define symbolic constants
#ifndef SOURCE_PINASSIGN_H_
#define SOURCE_PINASSIGN_H_

#include "StdTypes.h"

/// Assign macros to the pins of the arduino
#define PIN_CURRENT_MEAS_01		   ((uint8_t) A1)
#define PIN_CURRENT_MEAS_02		   ((uint8_t) A0)
#define PIN_POWER_SUPPLY_DETECTION ((uint8_t) A6)
#define PIN_VARIANT_DETECTION      ((uint8_t) A2)
#define PIN_DEBUG1_DEBUG2_ENABLE   (5)
#define PIN_DEBUG1_DEBUG3_ENABLE   (3)
#define PIN_WATCHDOG_SUPPR         (4)
#define PIN_DEBUGGER_SUPPLY        (6)
#define PIN_RELAIS_01              (8)
#define PIN_RELAIS_02              (7)
#define PIN_RELAIS_EXT             (2)
#define PIN_MULTIPLEX_OUTP_SELECT  (9)
#define PIN_MULTIPLEX_ENABLE       (10)
#define PIN_DTMBOARD_DETECTION     (12)
#define PIN_INTERBOARD_MASTER_DETECTION (11)
#define PIN_DTMBOARD_SELECT        (13)

#endif /* SOURCE_PINASSIGN_H_ */
