/* main.h */

#ifndef MAIN__H
#define MAIN__H

#include "types.h"
#include "date.h"

status_t validate_arguments (int argc, char *argv[], char *date_format_dictionary[], size_t size, format_data_t *input_format);
status_t printer_selector (format_data_t input_format, time_t actual_time);

#endif
