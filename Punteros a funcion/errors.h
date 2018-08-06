/* errors.h */

#ifndef ERRORS__H
#define ERRORS__H

#include "types.h"

#define MSG_ERROR_NULL_POINTER "Puntero nulo."
#define MSG_ERROR_INPUT_NUMBER_ARGUMENTS "Numero de argumentos ingresados invalido."
#define MSG_ERROR_FORMAT_FLAG "Formato de bandera no reconocido."
#define MSG_ERROR_UNDEFINED_FORMAT "Tipo de fecha ingresada no reconocida."

status_t errors_printr (status_t status);

#endif
