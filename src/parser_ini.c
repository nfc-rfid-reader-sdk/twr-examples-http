/*
 * parser_ini.c
 *
 *  Created on: 08.02.2018.
 *      Author: srkos
 */

#include <stdio.h>
#include <string.h>

//==================================================================
int get_ini_str(const char *ini_file_name, const char *setting_key,
		char *setting_out_value, const char *set_def)
{
	int r = 1;
	FILE *fini;
	char line[512];
	char *f = 0;

	fini = fopen(ini_file_name, "r");
	if (fini)
	{
		// read line by line
		while (fgets(line, 511, fini))
		{
			f = strstr(line, setting_key);

			if (f)
				break;
		}

		fclose(fini);
	}
	else
	{
		fprintf(stderr, "Error on opening settings file: %s\n", ini_file_name);
		r = -1;
	}

	if (f)
	{
		f += strlen(setting_key);

		// white char

		f++; // skip '='

		strcpy(setting_out_value, f);

		r = 0;
	}
	else
	{
		strcpy(setting_out_value, set_def);
	}

	return r;
}
