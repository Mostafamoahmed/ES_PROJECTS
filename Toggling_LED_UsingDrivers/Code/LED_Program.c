/*
 * LED_Program.c
 *
 *  Created on: Jan 25, 2024
 *      Author: mosta
 */
#include "LED_Interface.h"
#include "DIO_interface.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

//This Function Initialize the pin which connected to the LED to Output Pin
void LED_VoidInit(LED_Type LED_Configuration)
{
	DIO_enumSetPinDirection ( LED_Configuration.Port, LED_Configuration.Pin, DIO_PIN_OUTPUT	);
}

//This Function Set the Led to ON based on the Active_Status of the Led
void LED_VoidOn(LED_Type LED_Configuration)
{
	if (LED_Configuration.Active_State == ACTIVE_HIGH)
	{
		DIO_enumSetPinValue	(LED_Configuration.Port , LED_Configuration.Pin ,  DIO_PIN_HIGH);
	}
	else if (LED_Configuration.Active_State == ACTIVE_LOW)
	{
		DIO_enumSetPinValue	(LED_Configuration.Port , LED_Configuration.Pin ,  DIO_PIN_LOW);
	}

}

//This Function Set the Led to ON based on the Active_Status of the Led
void LED_VoidOff(LED_Type LED_Configuration)
{
	if (LED_Configuration.Active_State == ACTIVE_HIGH)
	{
		DIO_enumSetPinValue	(LED_Configuration.Port , LED_Configuration.Pin ,  DIO_PIN_LOW);
	}
	else if (LED_Configuration.Active_State == ACTIVE_LOW)
	{
		DIO_enumSetPinValue	(LED_Configuration.Port , LED_Configuration.Pin ,  DIO_PIN_HIGH);
	}
}

//This Function Toggle The Pin
void LED_VoidToggle(LED_Type LED_Configuration)
{
	DIO_enumTogglePinValue (LED_Configuration.Port, LED_Configuration.Pin);
}
