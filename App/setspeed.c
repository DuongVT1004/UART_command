#include "setspeed.h"
#include "string.h"
#include "response_ci.h"

extern TIM_HandleTypeDef htim2;
static uint8_t speed_flag = 0;

static void set_fan_speed(fan_speed_typedef speed)
{
	if(speed == SLOW)
	{
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 70);
	}
	if(speed == MEDIUM)
	{
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 40);
	}
	if(speed == HIGH)
	{
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 10);
	}
}


static void set_fan_state(fan_state state)
{
	if(state == NOT_ACT)
	{
		HAL_TIM_PWM_Stop(&htim2,TIM_CHANNEL_1);
		speed_flag = 0;
	}
	else
	{
		HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
		speed_flag = 1;
	}
}

void fan_state_excute(char **argv, uint8_t len)
{
	if(strcmp(argv[1], "0") == 0)
	{
		set_fan_state(NOT_ACT);
		response_print("The fan state is OFF");
	}
	else if(strcmp(argv[1], "1") == 0)
	{
		set_fan_state(ACTIVE);
		response_print("The fan state is ON");
	}
	else
	{
		response_print("The state argument is not right. Please choose again");
	}
}

void fan_speed_excute(char **argv, uint8_t len)
{
	if(speed_flag)
	{
		if(strcmp(argv[1], "0") == 0)
		{
			set_fan_speed(SLOW);
			response_print("Successfully. The fan speed is SLOW");
		}
		else if(strcmp(argv[1], "1") == 0)
		{
			set_fan_speed(MEDIUM);
			response_print("Successfully. The fan speed is MEDIUM");
		}
		else if(strcmp(argv[1], "2") == 0)
		{
			set_fan_speed(HIGH);
			response_print("Successfully. The fan speed is HIGH");
		}
		else
		{
			response_print("The speed is from 0 to 2, please set speed again");
		}
	}
	else
	{
		response_print("the fan is not active, firstly you need to open your fan");
	}
}
