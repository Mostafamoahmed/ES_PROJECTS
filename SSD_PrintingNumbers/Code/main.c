/*
 * main.c
 *
 *  Created on: Jan 31, 2024
 *      Author: mosta
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SSD_Interface.h"

#include "avr/delay.h"

SSD_Type SSD1={SSD_COMMON_CATHODE,SSD_PORTA,SSD_PORTA,SSD_PIN7};

void main()
{
	 SSD_Init(SSD1);
	while (1)
	{
		for (char i = 0 ;i<10;i++)
		{
			 SSD_SendNumber(SSD1, i);
			_delay_ms(250);
		}
	}

}
