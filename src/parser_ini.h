/*
 * parser_ini.h
 *
 *  Created on: 08.02.2018.
 *      Author: Digital Logic
 */

#ifndef PARSER_INI_H_
#define PARSER_INI_H_

/**
 * Parse INI file and get string values of provided key
 *
 * @param ini_file_name
 * @param setting_key
 * @param setting_value
 * @param def_value
 * @return
 */
int get_ini_str(const char *ini_file_name, const char *setting_key,
		char *setting_value, const char *def_value);

#endif /* PARSER_INI_H_ */
