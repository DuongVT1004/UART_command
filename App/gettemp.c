#include "gettemp.h"
#include "dht11.h"
#include "response_ci.h"

DHT_DataTypedef dht11;
float temp,hum;

void get_temperature(char **argv,uint8_t arg_num)
{
	(void)argv;
	if(arg_num != 1)
	{
		response_print("This get temperature command need only one argument");
		return;
	}
	DHT_GetData(&dht11);
	temp = dht11.Temperature;
	hum = dht11.Humidity;
	response_print("tem: %.2f", temp);
	response_print("hum: %.2f", hum);
}
