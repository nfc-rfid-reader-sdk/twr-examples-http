/*
 * tools.h
 *
 *  Created on: 08.02.2018.
 *      Author: Digital Logic
 */

#ifndef TOOLS_H_
#define TOOLS_H_

/**
 * Convert data array into hex representation string delimited with ':'
 *
 * @param in_data input data array, pointer to array
 * @param in_data_size input data array size
 * @param out_str output C-string, pointer to reserved memory
 * @param out_str_len output C-string length, without null terminator, pointer to reserved size_t variable
 * @return
 */
int hex2str(unsigned char *in_data, size_t in_data_size, //
		char *out_str, size_t *out_str_len);

#endif /* TOOLS_H_ */
