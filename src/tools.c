/*
 * tools.c
 *
 *  Created on: 08.02.2018.
 *      Author: srkos
 */

#include <string.h>
#include <stdio.h>
#include "tools.h"

#define BYTE_TO_HEXSTR_RATIO		3

int hex2str(unsigned char *in_data, size_t in_data_size, char *out_str,
		size_t *out_str_len)
{
	// 1 data byte expand to 3 bytes in hex-string format

	size_t i;
	char *out_p = out_str;

	// FIXME: protect output buffer
//	if (in_data_size * BYTE_TO_HEXSTR_RATIO > *out_str_len)
//	{
//		// output buffer is too small
//		return -1;
//	}

	for (i = 0; i < in_data_size; ++i)
	{
		sprintf(out_p, "%02X:", in_data[i]);
		out_p += BYTE_TO_HEXSTR_RATIO;
	}

	if (i)
	{
		// remove trailing ':'
		out_p--;
	}

	*out_p = 0; // null termination

	*out_str_len = out_p - out_str;

	return 0;
}

//------------------------------------------------------------------
