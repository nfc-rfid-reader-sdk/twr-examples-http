/*
 ============================================================================
 Name        : twr-lib-tester.c
 Author      : Digital Logic
 Description : Tester for twr-comm library
               Tester for easy SN/ID
 ============================================================================
 */

#include "../lib/include/twr-comm.h"
//-----------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//-----------------------------
// OS specific
#include <windows.h>
//-----------------------------

static int polling = TRUE;

// UID for stop polling - exit from application
u8 stop_uid[4] = { 0x16, 0x78, 0x58, 0x56 };

int fCB_UID(c_string sn, u8 uid[], int uid_len, int control_info)
{
	TWR_STATUS e;
	int i;

	puts("");
	puts("Application CB_OK is called ...");

	printf("Arrived packet from TWR SN=[%8s] with UID[len: %d]=", sn, uid_len);
	// hex to string
	for (i = 0; i < uid_len; ++i)
		printf("%02X:", uid[i]);
	printf(" | control_info= %d\n\n", control_info);

	puts("Application send ACK...");

	int r_status = 0; // OK

	e = TWR_Packet_Ack(sn, uid, uid_len, control_info, r_status);

	printf("TWR_Packet_Ack() : %s\n", TWR_Status2Str(e));
	puts("");
	puts("");

	//--------------------------------------------------------------
	// stop polling on specific UID
	if (!memcmp(uid, stop_uid, sizeof(stop_uid)))
	{
		puts("--> STOP POLLING UID detected <--");
		polling = FALSE;
	}
	//--------------------------------------------------------------

	return 0;
}

int fCB_Error(int err_id, const char *err_msg)
{
	printf("ERROR happens: id= %d | msg= %s\n", err_id, err_msg);

	return 0;
}

int main(void)
{
	TWR_STATUS e;

	printf("Tester for TWR-comm library version: ");
	puts(TWR_GetLibraryVersionStr());

	e = TWR_registerCB_Error(fCB_Error);
	printf("TWR_registerCB_Error(fCB_Error) : %s\n", TWR_Status2Str(e));

	e = TWR_registerCB_UID(fCB_UID);
	printf("TWR_registerCB_OK(fCB_UID) : %s\n", TWR_Status2Str(e));

	//---
	puts("Wait for SN/UID events...");
	puts("");

	while (polling)
	{
		e = TWR_Manager();
		if (e)
		{
			printf("TWR_Manager() : %s\n", TWR_Status2Str(e));

			break;
		}

		Sleep(1);
		fflush(stdout);
	}

	puts("Done.");
	puts("Tester exit!");

	return EXIT_SUCCESS;
}
