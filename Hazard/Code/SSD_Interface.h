#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#include "STD_TYPES.h"

//SSD TYPES
#define SSD_COMMON_CATHODE 			0
#define SSD_COMMON_ANODE 			1

//PORTS DEFINES
#define SSD_PORTA					0
#define SSD_PORTB					1
#define SSD_PORTC					2
#define SSD_PORTD					3

//PINS DEFINES
#define SSD_PIN0					0
#define SSD_PIN1					1
#define SSD_PIN2					2
#define SSD_PIN3					3
#define SSD_PIN4					4
#define SSD_PIN5					5
#define SSD_PIN6					6
#define SSD_PIN7					7

typedef struct {
	
	u8 Type ;
	u8 DataPort ;
	u8 EnablePort;
	u8 EnablePin;
	
}SSD_Type;

//functions Prototype
void SSD_Init(SSD_Type SSD_Configuration);
void SSD_Enable(SSD_Type SSD_Configuration);
void SSD_SendNumber(SSD_Type SSD_Configuration, u8 Number);
void SSD_Disable(SSD_Type SSD_Configuration);

#endif