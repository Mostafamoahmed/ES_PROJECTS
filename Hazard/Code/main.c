/*
 * main.c
 *
 *  Created on: Feb 28, 2024
 *      Author: mosta
 */
#include "APP.h"
#include "CLCD_Interface.h"
#include <avr/delay.h>



void main(void)
{
	Void_App_Init();
	while(1)
	{
		Void_ClearScreen();
		Void_Mode_Task();
		_delay_ms(100);
	}

}

