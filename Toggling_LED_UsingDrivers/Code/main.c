/*
 * main.c
 *
 *  Created on: Jan 26, 2024
 *      Author: mosta
 */
#include "LED_Interface.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "avr/delay.h"

LED_Type LED1 ={LED_PORTA,LED_PIN0,ACTIVE_HIGH};

void main()
{
	LED_VoidInit(LED1);
	while(1)
	{
		LED_VoidToggle(LED1);
		_delay_ms(1000);
	}
}
