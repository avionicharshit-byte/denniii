/*!
 *  \author    	Benjamin Stahl
 *  \author    	stahl04
 *  \version   	1.0
 *  \date      	16.10.2019
 */

/*!
 *  \file SerialCommunication.cpp
 *  \brief Handle the serial communication with the GUI
 *
 *  This program section is about handling the serial communication
 *  with the control GUI.
 */

#include "SerialCommunication.h"
#include "ProtocolHandler.h"
#include "OperationModeDetection.h"

/// Buffer size for the received data
#define RXBUFFER_SIZE   (20)
/// Buffer size for the sent data
#define TXBUFFER_SIZE   (45)
/// Start character
#define START_CHAR      ('$')
/// End character
#define END_CHAR        ('#')
/// Size of the control data array
#define CTRLDATA_DATAFIELDS_CNT   (6)
/// Delay for the status-update (100 ms)
#define TX_SEND_INTERVAL  (10)

/// Define function prototypes
static void SerCom_RxQueueHandler(void);
static void SerCom_TxHandler(void);


/// Setup serial communication
void SerCom_Init(void){

	/// Set data rate in bits per second (Baud) and data|parity|stop bit
	Serial.begin(57600, SERIAL_8N1);
	/// Set maximum milliseconds to wait for serial data (default: 1000 milliseconds)
	Serial.setTimeout(0);
}

/// Main function for serial communication
void SerCom_Main(void){

	/// Get operation mode
	OpModeDet_TEOpModeType opMode = OpModeDet_GetOpMode();
	// Serial.println(opMode);

	/// Only communicate via serial port if board operation mode is standalone or master
	if ((opMode != OpModeDet_TEOpModeType_Slave) && (opMode != OpModeDet_TEOpModeType_NotAvailable)){

		/// Handle the receiving and sending of data
		SerCom_RxQueueHandler();
		SerCom_TxHandler();
	}
}

/// Receive data via serial port
static void SerCom_RxQueueHandler(void){

	/// Get the number of available bytes
	int byteCnt = Serial.available();
	uint8_t cnt = 0;
	char c;
	Std_ReturnType ret = E_NOT_OK;

	/// Read in each received byte and process the data
	for (cnt = 0; cnt < byteCnt; cnt++){

		c = Serial.read();
		ret = ProtHdl_Rs232DataRcvd(c);

		/// If a full control message is received, print "OK" to the serial port
		if (E_OK == ret){
			Serial.println("OK");
		}
		else if (E_NOT_OK == ret){
			Serial.println("FAIL");
		}
	}
}

/// Send data via serial port
static void SerCom_TxHandler(void){

	/// Set the send delay
	static uint8_t delayCnt = TX_SEND_INTERVAL;
	/// Send data buffer
	static char txBuffer[PROTHDL_RS232TXDATASIZE] = { '\0' };

	/// Send the status after given interval
	if (delayCnt == 0){

		if (E_OK == ProtHdl_GetTxStatusData(txBuffer, PROTHDL_RS232TXDATASIZE)){

			Serial.println(txBuffer);
			delayCnt = TX_SEND_INTERVAL;
		}
	}
	else{
		delayCnt--;
	}
}
