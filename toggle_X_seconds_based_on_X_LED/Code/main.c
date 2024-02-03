/*
 * main.c
 *
 *  Created on: Feb 3, 2024
 *      Author: mosta
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LED_Interface.h"

#include "avr/delay.h"

LED_Type LED1 ={LED_PORTA,LED_PIN0,ACTIVE_HIGH };
LED_Type LED2 ={LED_PORTA,LED_PIN1,ACTIVE_HIGH };
LED_Type LED3 ={LED_PORTA,LED_PIN2,ACTIVE_HIGH };


void main()
{
	LED_VoidInit(LED1);
	LED_VoidInit(LED2);
	LED_VoidInit(LED3);
	while(1)
	{
		s8 counter = 1;

		while(1)
		{
			if (counter % 1 ==0)
			{
				LED_VoidToggle(LED1);
			}
			if (counter %2 == 0)
			{
				LED_VoidToggle(LED2);
			}
			if (counter %3 == 0)
			{
				LED_VoidToggle(LED3);
			}
			counter++;
			_delay_ms(200);
		}
	}
}
