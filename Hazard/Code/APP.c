/*
 * APP.c
 *
 *  Created on: Feb 26, 2024
 *      Author: mosta
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "avr/delay.h"

#include "SW_Interface.h"
#include "CLCD_Interface.h"
#include "SSD_Interface.h"

#include "APP.h"

SSD_Type SSD_RIGHT 	 	= 		{ SSD_COMMON_CATHODE , SSD_PORTA, SSD_PORTC , SSD_PIN6 };
SSD_Type SSD_LEFT 		= 		{ SSD_COMMON_CATHODE , SSD_PORTB , SSD_PORTC , SSD_PIN7 };
SW_Type SW_RIGHT 		= 		{SW_PORTC , SW_PIN0 , SW_INT_PULL_UP };
SW_Type SW_LEFT 		= 		{SW_PORTC , SW_PIN1 , SW_INT_PULL_UP };
SW_Type SW_HAZARD 		=		{SW_PORTC , SW_PIN2 , SW_INT_PULL_UP };

ModeState Mode  ;
ModeState Previous_State;

void  Void_App_Init(void)
{
	 SSD_Init						(SSD_RIGHT);
	 SSD_Init						(SSD_LEFT);
	 SW_Init						(SW_RIGHT);
	 SW_Init						(SW_LEFT);
	 SW_Init						(SW_HAZARD);
	 Void_Clcd_Init                 ( );
	 Void_ClearScreen               ( );
	 Void_SetMode					(Idle);
}

void Void_SetMode(ModeState Mode)
{
	switch (Mode)
	{

	case Idle :

		Void_ClearScreen               	( );
		SSD_Disable						(SSD_RIGHT);
		SSD_Disable						(SSD_LEFT);
		Void_ClearScreen               	( );
		Void_SendString                	((u8*)"Idle Mode");
		break;

	case RIGHT_BLINK :

		SSD_Disable						(SSD_LEFT);
		Void_ClearScreen               	( );
		Void_SendString                	((u8*)"Right Led Blink");
		SSD_Enable						(SSD_RIGHT );
		SSD_SendNumber					( SSD_RIGHT, 0);
		break;

	case lEFT_BLINK :

		SSD_Disable						(SSD_RIGHT);
		Void_ClearScreen               	( );
		Void_SendString                	((u8*)"Left Led Blink");
		SSD_Enable						(SSD_LEFT );
		SSD_SendNumber					( SSD_LEFT, 0);
	break;

	case HAZZARD_BLINK :

		Void_ClearScreen               	( );
		Void_SendString                	((u8*)"Hazard Mode");
		SSD_Enable						( SSD_LEFT );
		SSD_Enable						( SSD_RIGHT );
		SSD_SendNumber					( SSD_LEFT, 0);
		SSD_SendNumber					( SSD_RIGHT, 0);
		break;

	}
}


void MODE_vidIdle (void)
{
	Void_SetMode(Idle);
	if(SW_GetPressed(SW_LEFT))
	{
		Mode = lEFT_BLINK;
	}
	else if(SW_GetPressed(SW_RIGHT))
	{
		Mode = RIGHT_BLINK;
	}
	else if(SW_GetPressed(SW_HAZARD))
	{
		Previous_State = Idle;
		Mode = HAZZARD_BLINK;
	}
}
void MODE_vidRightBlink (void)
{
	Void_SetMode(RIGHT_BLINK);
	if(SW_GetPressed(SW_LEFT))
	{
		Mode = Idle;
	}
	else if(SW_GetPressed(SW_RIGHT))
	{
		Mode = RIGHT_BLINK;
	}
	else if(SW_GetPressed(SW_HAZARD))
	{
		Previous_State = RIGHT_BLINK;
		Mode = HAZZARD_BLINK;
	}
}
void MODE_vIdleftBlink (void)
{
	Void_SetMode(lEFT_BLINK);
	if(SW_GetPressed(SW_LEFT))
	{
		Mode = lEFT_BLINK;
	}
	else if(SW_GetPressed(SW_RIGHT))
	{
		Mode = Idle;
	}
	else if(SW_GetPressed(SW_HAZARD))
	{
		Previous_State = lEFT_BLINK;
		Mode = HAZZARD_BLINK;
	}
}
void MODE_vidHazardBlink (void)
{
	Void_SetMode(HAZZARD_BLINK);
	if(SW_GetPressed(SW_LEFT))
	{
		Mode = HAZZARD_BLINK;
	}
	else if(SW_GetPressed(SW_RIGHT))
	{
		Mode = HAZZARD_BLINK;
	}
	else if(SW_GetPressed(SW_HAZARD))
	{
		Mode = Previous_State;
	}
}


void Void_Mode_Task(void)
{
	if(Mode == Idle)
	{
		MODE_vidIdle();
	}
	else if(Mode == RIGHT_BLINK)
	{
		MODE_vidRightBlink();
	}
	else if(Mode == lEFT_BLINK)
	{
		MODE_vIdleftBlink();
	}
	else if(Mode == HAZZARD_BLINK)
	{
		MODE_vidHazardBlink();
	}
}





