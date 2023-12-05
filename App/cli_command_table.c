#include "cli_command_table.h"
#include "gettemp.h"
#include "setspeed.h"

cli_command_info_t cli_gettemp = 
{
	get_temperature,
	"get temp from dht11"
};

cli_command_info_t cli_set_fan_state = 
{
	fan_state_excute,
	"set state of fan"
};

cli_command_info_t cli_set_fan_speed = 
{
	fan_speed_excute,
	"set speed of fan"
};

cli_command_entry_t cli_table[] = 
{
	{&cli_gettemp, "gettemp"},
	{&cli_set_fan_state, "setstate"},
	{&cli_set_fan_speed, "setspeed"},
	{NULL, NULL}
};
