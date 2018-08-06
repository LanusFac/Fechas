/* date.h */

#ifndef FORMAT__H
#define FORMAT__H

#include "types.h"

typedef enum {
	DDMMAAAA_FORMAT = 0,
	AAAAMMDD_FORMAT = 1,
	DDMMAAAAHHMMSS_FORMAT = 2,
	DDDAAAA_FORMAT = 3,
	AAAADDD_FORMAT = 4
} format_data_t;

status_t print_date (time_t actual_time, status_t (*printer_function)(void *));

status_t print_ddmmaaaa_format_date (void *actual_time);
status_t print_aaaammdd_format_date (void *actual_time);
status_t print_ddmmaaaahhmmss_format_date (void *actual_time);
status_t print_dddaaaa_format_date (void *actual_time);
status_t print_aaaaddd_format_date (void *actual_time);

#endif
