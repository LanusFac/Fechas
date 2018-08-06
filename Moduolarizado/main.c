/* main.c */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "main.h"
#include "errors.h"
#include "date.h"

#define MAX_INPUT_ARGUMENTS 3
#define CMD_ARG_FORMAT_FLAG 1
#define CMD_ARG_FORMAT_DATA 2
#define FLAGS_NUMBER 5

#define FORMAT_FLAG "-fmt"

#define DDMMAAAA_FLAG "DDMMAAAA"
#define AAAAMMDD_FLAG "AAAAMMDD"
#define DDMMAAAAHHMMSS_FLAG "DDMMAAAAHHmmSS"
#define DDDAAAA_FLAG "DDDAAAA"
#define AAAADDD_FLAG "AAAADDD"

char *date_format_dictionary[] = {
	DDMMAAAA_FLAG,
	AAAAMMDD_FLAG,
	DDMMAAAAHHMMSS_FLAG,
	DDDAAAA_FLAG,
	AAAADDD_FLAG,
};

int main (int argc, char *argv[])
{
	time_t actual_time;
	status_t status;
	format_data_t input_format;

	if ((status = validate_arguments(argc, argv, date_format_dictionary, FLAGS_NUMBER, &input_format)) != OK)
	{
		errors_printr(status);
		return status;
	}

	time(&actual_time);

	if ((status = printer_selector(input_format, actual_time)) != OK)
	{
		errors_printr(status);
		return status;
	}


	return OK;
}

status_t validate_arguments (int argc, char *argv[], char *date_format_dictionary[], size_t size, format_data_t *input_format)
{
	size_t i;

	if (argv == NULL)
		return ERROR_NULL_POINTER;

	if (argc != MAX_INPUT_ARGUMENTS)
		return ERROR_INPUT_NUMBER_ARGUMENTS;

	if (strcmp(argv[CMD_ARG_FORMAT_FLAG], FORMAT_FLAG))
		return ERROR_FORMAT_FLAG;

	for (i = 0; i < size; i++)
	{
		if (!strcmp(argv[CMD_ARG_FORMAT_DATA], date_format_dictionary[i]))
		{
			*input_format = i;
			return OK;
		}
	}

	return ERROR_UNDEFINED_FORMAT;	
}
