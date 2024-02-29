#ifndef SW_INTERFACE_H_
#define SW_INTERFACE_H_

#include "STD_TYPES.h"

#define SW_PORTA			0
#define SW_PORTB			1
#define SW_PORTC			2
#define SW_PORTD			3

#define SW_PIN0				0
#define SW_PIN1				1
#define SW_PIN2				2
#define SW_PIN3				3
#define SW_PIN4				4
#define SW_PIN5				5
#define SW_PIN6				6
#define SW_PIN7				7

#define SW_Pressed 			1
#define SW_NotPressed		0

/*
	Options of the state:
	1-SW_INT_PULL_UP
	2-SW_EXT_PULL_UP
	3-SW_EXT_PULL_DOWN
	4-SW_FLOATING
*/

#define SW_INT_PULL_UP		0
#define SW_EXT_PULL_UP		1
#define SW_EXT_PULL_DOWN	2
#define SW_FLOATING			3


typedef struct
{
	u8 PORT;
	u8 PIN;
	u8 PULLup_STATE;
	
}SW_Type;

void SW_Init(SW_Type SW_Config);
u8 SW_GetPressed(SW_Type SW_Config);


#endif
