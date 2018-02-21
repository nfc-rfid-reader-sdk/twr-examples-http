/*
 * twr-error-codes.h
 *
 *  Created on: 01.02.2018.
 *      Author: Digital Logic
 */

#ifndef TWR_ERROR_CODES_H_
#define TWR_ERROR_CODES_H_

enum E_TWR_ERROR_CODES
{
	TWR_OK = 0x00,

	TIMEOUT_ERROR,

	// State Machine for parsing command
	SM_NOT_IDLE,
	SM_IDLE__NO_RESPONSE,
	SM_COMMAND_IN_PROGRESS,
	FILE_OVERSIZE,
	FILE_EMPTY,

	FILE_LOCKED, // when file is fill, and not read yet
	LOG_EMPTY,
	NO_RF_PACKET_DATA, // no data for retry RF packet

	TRANSFER_WRITING_ERROR, // error while transfer file

	EVENT_WAKEUP_BUSY, // still wake-up

	UART_READ_FTDI_ERROR,
	UART_READ_LESS_DATA, // less data read from UART

	UART_WRITE_FTDI_ERROR,
	UART_WRITE_LESS_DATA,

	NO_USB_RF_DEVICES,
	NO_TWR_DEVICES,

	CRC_ERROR,

	PARAMETERS_ERROR,
	TIMESTAMP_INVALID,

	LOG_BUFFER_OVERFLOW,

	// response
	CMD_RESPONSE_UNSUCCESS,
	CMD_RESPONSE_WRONG_RF_ADR,
	CMD_RESPONSE_WRONG_CMD,
	CMD_RESPONSE_SIZE_OVERFLOW,

	UART_BAD_DATA,

	MEMORY_ALLOCATION_ERROR,
	BUFFER_OVERFLOW,

	RFCMD_SUCCESS_REPORT_FAILED, // when try to change password with wrong old password too !
	RFCMD_PASSWORD_WRONG,
	RFCMD_LOG_NODATA,

	NULL_POINTER,

	USB_CLOSE_ERROR,

	USB_RF_ACK_FAILED, // bad acknowledgment form USB_RF
	USB_RF_ACK_OERR_TIMEOUT,
	// resource busy
	RESOURCE_BUSY,

	MAIN_LOOP_ERROR = 40,
	MAIN_LOOP_TIMEOUT,

	LAST_ERROR = 0xFFFFFFFF
};

typedef enum E_TWR_ERROR_CODES TWR_STATUS;

#define TWR_SUCCESS(status) ((status) == TWR_OK)
#define TWR_FAILURE(status) ((status) != TWR_OK)
#define TWR_TIME_OUT(status)((status) == TIMEOUT_ERROR)

// Convert TWR_STATUS to c_string with TWR_Status2Str()
//TWR_API
//c_string TWR_Status2Str(TWR_STATUS twr_status);

#endif /* TWR_ERROR_CODES_H_ */
