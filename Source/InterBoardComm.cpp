/*!
 *  \author		Benjamin Stahl
 *  \author 	stahl04
 *  \version 	1.0
 *  \date		29.04.2021
 */

/*!
 *  \file InterBoardComm.cpp
 *  \brief Handles the communication between two boards.
 *
 *  This section of the program handles the communication between
 *  a master- and a slave-board.
 */

#include "InterBoardComm.h"
#include "OperationModeDetection.h"
#include <Wire.h>
#include "ProtocolHandler.h"

/// Slave address
#define INTBRDCOMM_SLAVE_ADDRESS  (1)
/// InterBordCom Clock
#define INTBRDCOMM_CLOCK    (400000)
/// Request status cycle 50ms
#define INTBRDCOMM_MASTERSLAVE_REQ_STATUS_CYCLE (5)
/// Request and Respond timeout for master and slave
#define INTBRDCOMM_MASTER_REQ_TIMEOUT    (5 * INTBRDCOMM_MASTERSLAVE_REQ_STATUS_CYCLE)
#define INTBRDCOMM_SLAVE_RESP_TIMEOUT    (5 * INTBRDCOMM_MASTERSLAVE_REQ_STATUS_CYCLE)

/// Slave TX-buffer
static char IntBrdComm_slaveTxBuffer[PROTHDL_SLAVETXDATASIZE] = { '\0' };
/// Timeout counter
static uint8_t IntBrdComm_i2cSlaveRespTimeoutCnt = INTBRDCOMM_SLAVE_RESP_TIMEOUT;
static uint8_t IntBrdComm_i2cMasterReqTimeoutCnt = INTBRDCOMM_MASTER_REQ_TIMEOUT;

/// function prototypes
static void IntBrdComm_I2cInit(void);
void IntBrdComm_I2cReceiveEvent(int byteCnt);
void IntBrdComm_I2cRequestEvent(void);
static void IntBrdComm_MasterSlaveCtrlDataHandler(void);
static void IntBrdComm_MasterSlaveStatusDataHandler(void);

/// Initialization of the inter board communication
void IntBrdComm_Init(void){

	IntBrdComm_I2cInit();
}

/// Main function of the inter board communication
void IntBrdComm_Main(void){

	/// Previous operation mode, initialized with OpModeDet_TEOpMode_Type_NotAvailable
	static OpModeDet_TEOpModeType opModeOld = OpModeDet_TEOpModeType_NotAvailable;
	/// Master request timeout
	static uint8_t masterReqTimeoutCntMin = INTBRDCOMM_MASTER_REQ_TIMEOUT;
	/// Slave response timeout
	static uint8_t slaveRespTimeoutCntmin = INTBRDCOMM_SLAVE_RESP_TIMEOUT;

	/// Get the current operation mode
	OpModeDet_TEOpModeType opMode = OpModeDet_GetOpMode();

	/// Initialize the I2C communication if the operation mode changed
	if ((opModeOld != OpModeDet_TEOpModeType_NotAvailable) && (opModeOld != opMode)){

		IntBrdComm_I2cInit();
	}

	/// Handle communication in operation mode master
	if ((OpModeDet_TEOpModeType_Master == opMode) && (IoMod_IsPowerSupplyConnected() == true)){

		//Serial.println("15");
		IntBrdComm_MasterSlaveCtrlDataHandler();
		//Serial.println("16");
		IntBrdComm_MasterSlaveStatusDataHandler();
		//Serial.println("17");

		/// Reset master request timeout count
		IntBrdComm_i2cMasterReqTimeoutCnt = INTBRDCOMM_MASTER_REQ_TIMEOUT;

		/// Count down the response timeout counter for the slave
		if (IntBrdComm_i2cSlaveRespTimeoutCnt > 0){
			IntBrdComm_i2cSlaveRespTimeoutCnt--;
		}
		/// Adjust the response timeout counter minimum for the slave
		if (IntBrdComm_i2cSlaveRespTimeoutCnt < slaveRespTimeoutCntmin){
			slaveRespTimeoutCntmin = IntBrdComm_i2cSlaveRespTimeoutCnt;
		}
	}
	/// Handle communication in operation mode slave
	if (OpModeDet_TEOpModeType_Slave == opMode){

		/// Reset the slave response timeout count
		IntBrdComm_i2cSlaveRespTimeoutCnt = INTBRDCOMM_SLAVE_RESP_TIMEOUT;

		/// Countdown master request timeout count for the master
		if (IntBrdComm_i2cMasterReqTimeoutCnt > 0){
			IntBrdComm_i2cMasterReqTimeoutCnt--;
		}

		/// Adjust the response timeout counter minimum for the master
		if (IntBrdComm_i2cMasterReqTimeoutCnt < masterReqTimeoutCntMin){
			masterReqTimeoutCntMin = IntBrdComm_i2cMasterReqTimeoutCnt;
		}
	}
	// Update the previous operating mode for the next iteration
	opModeOld = opMode;
}

/*!
 *  \brief Receive event for I2C communication.
 *
 *  This function is the event function for the I2C receive event. It reads the serial transmission.
 *  \param byteCnt Unused
 */
void IntBrdComm_I2cReceiveEvent(__attribute__((unused)) int byteCnt)
{
	char c;

	while(Wire.available())
	{
		c = Wire.read();
		ProtHdl_I2cDataFromMasterRcvd(c);
	}
}

/*!
 *  \brief Request event for I2C communication.
 *
 *  This function writes the slave txbuffer to the event function for I2C request event. It writes the slave txbuffer.
 */
void IntBrdComm_I2cRequestEvent(void){

	if (E_OK == ProtHdl_GetTxStatusData(IntBrdComm_slaveTxBuffer, PROTHDL_SLAVETXDATASIZE)){

		IntBrdComm_i2cMasterReqTimeoutCnt = INTBRDCOMM_MASTER_REQ_TIMEOUT;

		Wire.write(IntBrdComm_slaveTxBuffer);
	}
}

/*!
 *  \brief Handle the control data communication between master an slave.
 *
 *  This function handles the control data communication between master and slave board.
 */
static void IntBrdComm_MasterSlaveCtrlDataHandler(void){

	static uint8_t delayCnt = 2;
	static char txBuffer[PROTHDL_CTRLDATABUFFER_SIZE] = { '\0' };

	if (delayCnt == 0){

		/// Get the control data and write to the slave.
		if (E_OK == ProtHdl_GetTxCtrlData(txBuffer, PROTHDL_CTRLDATABUFFER_SIZE)){
			//Serial.println("15.1");
			Wire.beginTransmission(INTBRDCOMM_SLAVE_ADDRESS);
			//Serial.println("15.2");
			Wire.write(txBuffer);
			//Serial.println("15.3");
			Wire.endTransmission();
			//Serial.println("15.4");
		}
		delayCnt = 1;
	}
	else{

		delayCnt--;
	}
}

/*!
 *  \brief Handle the status data communication between master and slave.
 *
 *  This function handles the status data communication between master and slave board.
 */
static void IntBrdComm_MasterSlaveStatusDataHandler(void){

	static uint8_t delayCnt = INTBRDCOMM_MASTERSLAVE_REQ_STATUS_CYCLE;
	Std_ReturnType ret = E_PENDING;
	char c;

	if (0 == delayCnt){

		/// Request a data transmission from the slave board.
		Wire.requestFrom(INTBRDCOMM_SLAVE_ADDRESS, PROTHDL_SLAVETXDATASIZE);

		/// read all the data
		while (Wire.available()) {

			c = Wire.read();
			ret = ProtHdl_I2cDataFromSlaveRcvd(c);

			if (E_OK == ret){
				/// Full package detected, reset timeout counter
				IntBrdComm_i2cSlaveRespTimeoutCnt = INTBRDCOMM_SLAVE_RESP_TIMEOUT;
			}
		}

		/// Reset the request timeout counter for the master
		delayCnt = INTBRDCOMM_MASTERSLAVE_REQ_STATUS_CYCLE;
	}
	else{
		delayCnt--;
	}

}

/**
 * @brief Initialize the I2C communication
 *
 * This function initializes the I2C communication based on the operating mode.
 */
static void IntBrdComm_I2cInit(void){

	/// Get the current operation mode
	OpModeDet_TEOpModeType opMode = OpModeDet_GetOpMode();

	/// Check if the operation mode is master or slave
	if ((OpModeDet_TEOpModeType_Master == opMode) || (OpModeDet_TEOpModeType_Slave == opMode)){

		/// Init the I2C serial connection for master or slave
		if (OpModeDet_TEOpModeType_Master == opMode){

			Wire.begin();
			Wire.setClock(INTBRDCOMM_CLOCK);
		}
		else{
			Wire.begin(INTBRDCOMM_SLAVE_ADDRESS);
			Wire.onReceive(IntBrdComm_I2cReceiveEvent);
			Wire.onRequest(IntBrdComm_I2cRequestEvent);
		}
	}
	/// End the serial connection if the operation mode is standalone or none
	else{
		Wire.end();
	}
}

/// This function checks if the timeout should be active
bool IntBrdComm_CommTimeoutActive(void){

	/// Get the current operation mode
	OpModeDet_TEOpModeType opMode = OpModeDet_GetOpMode();
	bool ret = false;

	/// Check if timeout counter is at zero and the timeout should be activated
	if (((OpModeDet_TEOpModeType_Master == opMode) && (0 == IntBrdComm_i2cSlaveRespTimeoutCnt))
			|| ((OpModeDet_TEOpModeType_Slave == opMode) && (0 == IntBrdComm_i2cMasterReqTimeoutCnt))){

		ret = true;
	}

	return ret;
}
