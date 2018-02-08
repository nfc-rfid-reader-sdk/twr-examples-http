/*
 * parser_ini.c
 *
 *  Created on: 08.02.2018.
 *      Author: Digital Logic
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

//==================================================================

char * trim_val(char *in)
{
	if (!in)
		return 0;

	char *n;
	char *start = 0;
	int eq_skipped = 0;

	for (n = in; *n != '\r'; ++n)
	{
		if (isspace(*n))
		{
			if (start)
			{
				// end > stop
				*n = 0;

				break;
			}
		}
		else if (*n == '=')
		{
			if (eq_skipped)
			{
				return 0;
			}
			else
			{
				eq_skipped = 1;
			}
		}
//		else if (isalnum(*n))
		else if (isascii(*n))
		{
			if (start)
			{
				// continue
			}
			else
			{
				if (eq_skipped)
				{
					start = n;
				}
				else
				{
					// error in format: no '='
					return 0;
				}
			}
		}
		else
		{
			// not valid data
			return 0;
		}
	}

	return start;
}

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
		while (fgets(line, sizeof(line) - 1, fini))
		{
			f = strstr(line, setting_key);

			if (f)
			{
				f += strlen(setting_key);

				f = trim_val(f);

				break;
			}
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
		strcpy(setting_out_value, f);

		r = 0;
	}
	else
	{
		strcpy(setting_out_value, set_def);
	}

	return r;
}
