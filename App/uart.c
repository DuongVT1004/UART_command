#include "uart.h"
//#include <string.h>
//#include <stdlib.h>
//#include "dht11.h"
//#include "response_ci.h"
#include "cli_command.h"

#define MAX_DATA_SIZE 100
static char uart_buff[MAX_DATA_SIZE];
static uint8_t uart_len = 0;
uint8_t flag = 0;


void receive_data(uint8_t data)
{
	if(data == '\n')
	{
		uart_buff[uart_len] = '\0';
		flag = 1;
	}
	else
	{
		uart_buff[uart_len++] = data;
	}
}

void uart_handle()
{
	if(flag)
	{
		cli_command_excute(uart_buff, uart_len);
		flag = 0;
		uart_len = 0;
	}
}
