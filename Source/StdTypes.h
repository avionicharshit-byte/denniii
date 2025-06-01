/*!
 *  \author    	Benjamin Stahl
 *  \author    	stahl04
 *  \version   	1.0
 *  \date      	14.10.2019
 */

/*!
 *  \file StdTypes.h
 *  \brief Defines some standard data types.
 *
 *  This header file defines some standard data types.
 */

/// Define symbolic constant
#ifndef SOURCE_STDTYPES_H_
#define SOURCE_STDTYPES_H_

/// Include the arduino library
#include "Arduino.h"

/*!
 *  \brief Enum of the standard return types.
 *
 *  Std_ReturnTypes is an enum type with the different return types.
 */
typedef enum{

	E_OK = 0,			///< Process is finished
	E_NOT_OK = 1,		///< Process is not finished
	E_PENDING = 10		///< Process is still running
} Std_ReturnType;

/// Define standard ON/OFF
#define STD_OFF (0)
#define STD_ON  (1)


#endif /* SOURCE_STDTYPES_H_ */
