/*
 * DIO_interface.h
 *
 *  Created on: Dec 23, 2023
 *      Author: mosta
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "STD_TYPES.h"

typedef enum
{
	DIO_NOK,
	DIO_OK

}DIO_ErrorStatus;

//PORT DEFINES
#define DIO_PORTA 				0
#define DIO_PORTB				1
#define DIO_PORTC				2
#define DIO_PORTD				3

//PIN DEFINES
#define DIO_PIN0				0
#define DIO_PIN1				1
#define DIO_PIN2				2
#define DIO_PIN3				3
#define DIO_PIN4				4
#define DIO_PIN5				5
#define DIO_PIN6				6
#define DIO_PIN7				7

//PIN DIRECTION
#define DIO_PIN_OUTPUT 			1
#define DIO_PIN_INPUT 			0

//PIN VALUE
#define DIO_PIN_HIGH			1
#define DIO_PIN_LOW				0

//PORT DIRECTION
#define DIO_PORT_OUTPUT			0XFF
#define DIO_PORT_INPUT			0

//Pull UP
#define DIO_PIN_PULLUP_YES 		1	
#define PUD   					2

//PIN FUNCTIONS
DIO_ErrorStatus DIO_enumSetPinDirection 		(u8  PORT,u8  PIN,u8  Direction	);
DIO_ErrorStatus DIO_enumSetPinValue				(u8  PORT,u8  PIN,u8  Value		);
DIO_ErrorStatus DIO_enumGetPinValue				(u8  PORT,u8  PIN,u8 * PtrData	);
DIO_ErrorStatus DIO_enumTogglePinValue			(u8  PORT,u8  PIN);

//INTERNAL PULL-UP
DIO_ErrorStatus DIO_enumConnect_Disconnect_Pullup			(u8 PORT , u8 PIN,u8 Connect_PullUP);
void DIO_Disable_Internal_PullUp_AllPins	(void);

//PORT FUNCTIONS
DIO_ErrorStatus DIO_enumSetPortDirection     	(u8  PORT, u8  Direction  	);
DIO_ErrorStatus DIO_enumSetPortValue         	(u8  PORT, u8  Value      	);
DIO_ErrorStatus DIO_enumGetPortValue         	(u8  PORT, u8 *  PtrData    	);
DIO_ErrorStatus DIO_enumTogglePortValue      	(u8  PORT                   	);

#endif /* DIO_INTERFACE_H_ */
