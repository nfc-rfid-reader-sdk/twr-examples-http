/*
 * twr-uid-comm.h
 *
 *  Created on: 30.01.2018.
 *      Author: Digital Logic
 */

#ifndef TWR_COMM_H_
#define TWR_COMM_H_

#include "twr-error-codes.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// Calling convention
///
#ifdef __cplusplus
#	define EXTC_	extern "C"
#else
#	define EXTC_
#endif

#ifdef __WIN32
#	ifdef TWR_STATIC_LIB
#		define TWR_API EXTC_
#	else
#		ifdef TWR_EXPORTS
#			define TWR_API EXTC_ __declspec(dllexport) __stdcall
#		else
#			define TWR_API EXTC_ /*__declspec(dllimport) */ __stdcall
#		endif
#	endif
#else
#	define TWR_API EXTC_
#endif
//##############################################################################

////////////////////////////////////////////////////////////////////
/// Additional data types
///
/**
 * Type for representing null terminated char array ( aka C-String )
 * Array is always one byte longer ( for null character ) then string.
 */
typedef const char * c_string;

/**
 * Type for representing a byte information (8 bits long)
 */
typedef unsigned char u8;

////////////////////////////////////////////////////////////////////

/**
 * Return library version in format "4.0.0"
 *
 * @return pointer to the statically allocated c-string
 * 			(no need to allocate in the application)
 */
TWR_API
c_string TWR_GetLibraryVersionStr(void);

//##############################################################################

/**
 * Convert TWR_STATUS value to c-string representation
 *
 * @param twr_status
 * @return pointer to the statically allocated c-string
 * 			(no need to allocate in the application)
 */
TWR_API
c_string TWR_Status2Str(TWR_STATUS twr_status);

////////////////////////////////////////////////////////////////////
//// SN-UID only
////////////////////////////////////////////////////////////////////

/**
 * Register call back function for errors
 *
 * prototype:
 * 	int fCB_Error(int err_id, c_string err_msg);
 *
 * @param CB_F pointer to function with prototype like above
 * @return registration status
 */
TWR_API
TWR_STATUS TWR_registerCB_Error(void *CB_F);

/**
 * Register call back function for getting UID events
 *
 * prototype:
 * 	int fCB_UID(c_string sn, u8 uid[], int uid_len, int control_info);
 *
 * @param CB_F pointer to function with prototype like above
 * @return registration status
 */
TWR_API
TWR_STATUS TWR_registerCB_UID(void *CB_F);

/**
 * Send RF packet with acknowledge to reader with specific SN
 *
 * @param sn target reader serial number
 * @param uid ACK for specific card UID
 * @param uid_len UID length
 * @param control_info the control information - precisely determined right card event,
 * 						provide (given) control_info from UID events
 * @param r_status return status to TWR : 0= OK, 1= failed
 * @return
 */
TWR_API
TWR_STATUS TWR_Packet_Ack(c_string sn, u8 uid[], int uid_len, int control_info,
		int r_status);

/**
 * Constantly execute TWR manager to make call back functions to work
 *
 * @return
 */
TWR_API
TWR_STATUS TWR_Manager(void);

////////////////////////////////////////////////////////////////////
#endif /* TWR_COMM_H_ */
