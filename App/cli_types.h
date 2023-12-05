#ifndef CLI_TYPES_H
#define CLI_TYPES_H

#include "stdint.h"

typedef void (*cli_function)(char **argv, uint8_t len);

typedef struct
{
	cli_function function;
	char         *help;
}cli_command_info_t;

typedef struct
{
	cli_command_info_t *info;
	char               *name;
}cli_command_entry_t;

#endif
