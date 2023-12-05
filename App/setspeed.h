#ifndef SETSPEED_H
#define SETSPEED_H

#include "stm32f1xx_hal.h"
#include "stdint.h"

typedef enum
{
	SLOW = 0,
	MEDIUM,
	HIGH
}fan_speed_typedef;

typedef enum
{
	NOT_ACT = 0,
	ACTIVE
}fan_state;

void fan_state_excute(char **argv, uint8_t len);
void fan_speed_excute(char **argv, uint8_t len);

#endif
