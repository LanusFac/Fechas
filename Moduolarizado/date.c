/* date.c */

#include <stdio.h>
#include <time.h>
#include "types.h"
#include "date.h"

status_t printer_selector (format_data_t input_format, time_t actual_time)
{
	status_t status;

	switch (input_format) 
	{
		case DDMMAAAA_FORMAT:
		if ((status = print_ddmmaaaa_format_date (actual_time)) != OK)
			return status;
		break;

		case AAAAMMDD_FORMAT:
		if ((status = print_aaaammdd_format_date (actual_time)) != OK)
			return status;
		break;

		case DDMMAAAAHHMMSS_FORMAT:
		if ((status = print_ddmmaaaahhmmss_format_date (actual_time)) != OK)
			return status;
		break;

		case DDDAAAA_FORMAT:
		if ((status = print_dddaaaa_format_date (actual_time)) != OK)
			return status;
		break;

		case AAAADDD_FORMAT:
		if ((status = print_aaaaddd_format_date (actual_time)) != OK)
			return status;
		break;

		default:
		status = ERROR_UNDEFINED_FORMAT;
	}

	return OK;
}
