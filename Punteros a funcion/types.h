/* types.h */

#ifndef TYPES__H
#define TYPES__H

typedef enum 
{
	ERROR_NULL_POINTER = 0,
	ERROR_INPUT_NUMBER_ARGUMENTS = 1,
	ERROR_FORMAT_FLAG = 2,
	ERROR_UNDEFINED_FORMAT = 3,
	OK
} status_t;

typedef status_t (*printer_date_t)(void *);


#endif
