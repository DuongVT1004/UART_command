#include "cli_command.h"
#include "dht11.h"
#include "gettemp.h"
#include "setspeed.h"
#include "cli_command_table.h"
#include "response_ci.h"

extern cli_command_entry_t cli_table[];

static cli_command_info_t* find_cli_name(char *cmd)
{
	cli_command_entry_t *cmd_entry = cli_table;
	while(cmd_entry->name != NULL)
	{
		if(strcmp(cmd_entry->name, cmd) == 0)
		{
			return cmd_entry->info;
		}
		cmd_entry++;
	}
	return NULL;
}


void cli_command_excute(char *uart_buff, uint8_t len)
{
	(void)len;
	char **argv = NULL;
		argv = (char**)malloc(10 * sizeof(char*));
		uint8_t arg_num = 0;
		char *pch;
		pch = strtok(uart_buff, " ");
		while(pch != NULL)
		{
			argv[arg_num++] = pch;
			pch = strtok(NULL, " ");
		}
		cli_command_info_t *cmd_info = find_cli_name(argv[0]);
    if(cmd_info != NULL)
    {
			cmd_info->function(argv, arg_num);
		}
		else
		{
			response_print("Don't find this cli name. Please check again and enter right cli");
		}
//		if(strcmp(argv[0], "gettemp") == 0)
//		{
//			get_temperature(argv, arg_num);
//	  }
//		else if(strcmp(argv[0], "setstate") == 0)
//		{
//			fan_state_excute(argv, arg_num);
//		}
//		else if(strcmp(argv[0], "setspeed") == 0)
//		{
//			fan_speed_excute(argv, arg_num);
//		}
		free(argv);
}
