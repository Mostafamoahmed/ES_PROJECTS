/*
 * main.c
 *
 *  Created on: Feb 16, 2024
 *      Author: mosta
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "CLCD_Interface.h"

#include "avr/delay.h"

void main(void)
{
	Void_Init                      ( );
	Void_SendString                ("Mostafa");
	while(1);

}


