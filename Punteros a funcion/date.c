/* date.c */

#include <stdio.h>
#include <time.h>
#include "types.h"
#include "date.h"



status_t printer_selector (format_data_t input_format, time_t actual_time)
{
	status_t status;

	printer_date_t print_format[5] =
	{
		print_ddmmaaaa_format_date,
		print_aaaammdd_format_date,
		print_ddmmaaaahhmmss_format_date,
		print_dddaaaa_format_date,
		print_aaaaddd_format_date
	};

	if ((status = print_date (actual_time, print_format[input_format])) != OK)
		return status;

	return OK;
}

