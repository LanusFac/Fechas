/* printers.c */

#include <stdio.h>
#include <time.h>

#include "errors.h"
#include "main.h"
#include "date.h"
#include "types.h"

#define DATE_MAX_SIZE 20

typedef status_t (*printer_data_function)(time_t, const char*);

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

status_t print_ddmmaaaa_format_date (void *actual_time)
{
	struct tm *time_structure;
	char str_date[DATE_MAX_SIZE + 1];
	time_t time_tm;

	time_tm = *((time_t *)actual_time);

	time_structure = localtime(&time_tm);

	strftime (str_date, DATE_MAX_SIZE + 1, "%d/%m/%Y", time_structure);

	puts(str_date);

	return OK;
}

status_t print_aaaammdd_format_date (void *actual_time)
{
	struct tm *time_structure;
	char str_date[DATE_MAX_SIZE + 1];
	time_t time_tm;

	time_tm = *((time_t *)actual_time);

	time_structure = localtime(&time_tm);

	strftime (str_date, DATE_MAX_SIZE + 1, "%Y/%m/%d", time_structure);

	puts(str_date);

	return OK;
}

status_t print_ddmmaaaahhmmss_format_date (void *actual_time)
{
	struct tm *time_structure;
	char str_date[DATE_MAX_SIZE + 1];
	time_t time_tm;

	time_tm = *((time_t *)actual_time);

	time_structure = localtime(&time_tm);

	strftime (str_date, DATE_MAX_SIZE + 1, "%d/%m/%Y %H:%M:%S", time_structure);

	puts(str_date);

	return OK;
}

status_t print_dddaaaa_format_date (void *actual_time)
{
	struct tm *time_structure;
	char str_date[DATE_MAX_SIZE + 1];
	time_t time_tm;

	time_tm = *((time_t *)actual_time);

	time_structure = localtime(&time_tm);

	strftime (str_date, DATE_MAX_SIZE + 1, "%j/%Y", time_structure);

	puts(str_date);

	return OK;
}


status_t print_aaaaddd_format_date (void *actual_time)
{
	struct tm *time_structure;
	char str_date[DATE_MAX_SIZE + 1];
	time_t time_tm;

	time_tm = *((time_t *)actual_time);

	time_structure = localtime(&time_tm);

	strftime (str_date, DATE_MAX_SIZE + 1, "%Y/%j", time_structure);

	puts(str_date);

	return OK;
}

status_t print_date (time_t actual_time, printer_date_t printer_function)
{
	status_t status;

	if ((status = printer_function(&actual_time)) != OK)
		return status;

	return OK;
}


