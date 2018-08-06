/* printers.c */

#include <stdio.h>
#include <time.h>

#include "errors.h"
#include "main.h"
#include "date.h"
#include "types.h"

#define DATE_MAX_SIZE 20

status_t errors_printr (status_t status)
{
	char *errors[] = {
		MSG_ERROR_NULL_POINTER,
		MSG_ERROR_INPUT_NUMBER_ARGUMENTS,
		MSG_ERROR_FORMAT_FLAG,
		MSG_ERROR_UNDEFINED_FORMAT
	};

	fprintf(stderr, "%s\n", errors[status]);

	return OK;
}

status_t print_ddmmaaaa_format_date (time_t actual_time)
{
	struct tm *time_structure;
	char str_date[DATE_MAX_SIZE + 1];

	time_structure = localtime(&actual_time);

	strftime(str_date, DATE_MAX_SIZE + 1, "%d/%m/%Y", time_structure);

	puts(str_date);

	return OK;
}

status_t print_aaaammdd_format_date (time_t actual_time)
{
	struct tm *time_structure;
	char str_date[DATE_MAX_SIZE + 1];

	time_structure = localtime(&actual_time);

	strftime(str_date, DATE_MAX_SIZE + 1, "%Y/%m/%d", time_structure);

	puts(str_date);

	return OK;
}

status_t print_ddmmaaaahhmmss_format_date (time_t actual_time)
{
	struct tm *time_structure;
	char str_date[DATE_MAX_SIZE + 1];

	time_structure = localtime(&actual_time);

	strftime(str_date, DATE_MAX_SIZE + 1, "%d/%m/%Y %H:%M:%S", time_structure);

	puts(str_date);

	return OK;
}

status_t print_dddaaaa_format_date (time_t actual_time)
{
	struct tm *time_structure;
	char str_date[DATE_MAX_SIZE + 1];

	time_structure = localtime(&actual_time);

	strftime(str_date, DATE_MAX_SIZE + 1, "%j/%Y", time_structure);

	puts(str_date);

	return OK;
}

status_t print_aaaaddd_format_date (time_t actual_time)
{
	struct tm *time_structure;
	char str_date[DATE_MAX_SIZE + 1];

	time_structure = localtime(&actual_time);

	strftime(str_date, DATE_MAX_SIZE + 1, "%Y/%j", time_structure);

	puts(str_date);

	return OK;
}

