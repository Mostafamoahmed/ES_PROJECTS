/*
 * DIO_program.c

 *
 *  Created on: Dec 23, 2023
 *      Author: mostafa
 */
#include "BIT_MATH.H"
#include "STD_TYPES.H"
#include "DIO_interface.h"
#include "DIO_private.h"


/*This Function set the direction of the pin either the direction is input or output */
DIO_ErrorStatus DIO_enumSetPinDirection 		(u8 PORT,u8 PIN,u8 Direction)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;

	if((PORT <= DIO_PORTD) &&( PIN <= DIO_PIN7))
	{
		if( Direction == DIO_PIN_OUTPUT)
		{
			switch(PORT)
			{
			case DIO_PORTA : SetBit(DDRA_Register,PIN);break;
			case DIO_PORTB : SetBit(DDRB_Register,PIN);break;
			case DIO_PORTC : SetBit(DDRC_Register,PIN);break;
			case DIO_PORTD : SetBit(DDRD_Register,PIN);break;
			}
		}

		else if(Direction == DIO_PIN_INPUT)
		{
			switch(PORT)
			{
			case DIO_PORTA : ClrBit(DDRA_Register,PIN);break;
			case DIO_PORTB : ClrBit(DDRB_Register,PIN);break;
			case DIO_PORTC : ClrBit(DDRC_Register,PIN);break;
			case DIO_PORTD : ClrBit(DDRD_Register,PIN);break;
			}
		}

		else
			LOC_enumState = DIO_NOK;
	}
	else
		LOC_enumState = DIO_NOK;

	return LOC_enumState;

}

/*This function set the value of the pin if it is output pin either HIGH  or LOW */
DIO_ErrorStatus DIO_enumSetPinValue				(u8  PORT,u8  PIN,u8  Value)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	if((PORT <= DIO_PORTD) && PIN <= DIO_PIN7)
	{
		if(Value == DIO_PIN_HIGH)
		{
			switch(PORT)
			{
			case DIO_PORTA : SetBit(PORTA_Register,PIN);break;
			case DIO_PORTB : SetBit(PORTB_Register,PIN);break;
			case DIO_PORTC : SetBit(PORTC_Register,PIN);break;
			case DIO_PORTD : SetBit(PORTD_Register,PIN);break;
			}
		}
		else if (Value == DIO_PIN_LOW)
		{
			switch(PORT)
			{
			case DIO_PORTA : ClrBit(PORTA_Register,PIN);break;
			case DIO_PORTB : ClrBit(PORTB_Register,PIN);break;
			case DIO_PORTC : ClrBit(PORTC_Register,PIN);break;
			case DIO_PORTD : ClrBit(PORTD_Register,PIN);break;
			}
		}
		else
			LOC_enumState = DIO_NOK;
	}
	else
		LOC_enumState = DIO_NOK;

	return LOC_enumState;
}

/*This function takes the value of the input PIN in a derefrence pointer */
DIO_ErrorStatus DIO_enumGetPinValue				(u8 PORT,u8 PIN,u8 * PtrData)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	if((PORT <= DIO_PORTD) &&(PIN <=DIO_PIN7))
	{
		switch(PORT)
		{
		case DIO_PORTA : *PtrData = GetBit(PINA_Register,PIN);break;
		case DIO_PORTB : *PtrData = GetBit(PINB_Register,PIN);break;
		case DIO_PORTC : *PtrData = GetBit(PINC_Register,PIN);break;
		case DIO_PORTD : *PtrData = GetBit(PIND_Register,PIN);break;
		}
	}
	else
		LOC_enumState = DIO_NOK;

	return LOC_enumState;
}

/*This function toggle the pin value in case it is an output PIN */
DIO_ErrorStatus DIO_enumTogglePinValue				(u8  PORT,u8  PIN)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	if((PORT <= DIO_PORTD) &&(PIN <=DIO_PIN7))
		{
			switch(PORT)
			{
			case DIO_PORTA : ToggleBit(PORTA_Register,PIN);break;
			case DIO_PORTB : ToggleBit(PORTB_Register,PIN);break;
			case DIO_PORTC : ToggleBit(PORTC_Register,PIN);break;
			case DIO_PORTD : ToggleBit(PORTD_Register,PIN);break;
			}
		}
		else
			LOC_enumState = DIO_NOK;

		return LOC_enumState;
}

/*This Function enables the internal pull-up of the pin*/
DIO_ErrorStatus DIO_enumConnect_Disconnect_Pullup			(u8 PORT , u8 PIN,u8 Connect_PullUP)
{	
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	
	if((PORT<=DIO_PORTD)&&(PIN<=DIO_PIN7))
	{
		switch(PORT)
		{
			case DIO_PORTA:
				if(Connect_PullUP == DIO_PIN_PULLUP_YES)
				{
					/*Active the Internal Pull-up of the Pin*/
					ClrBit(SFIOR,PUD);
					ClrBit(DDRA_Register,PIN);
					SetBit(PORTA_Register,PIN);
				}
				else 
				{
					//Disable the Internal Pull-up of the PIN
					ClrBit(PORTA_Register,PIN);
				}
				break;
				
			case DIO_PORTB:
				if(Connect_PullUP == DIO_PIN_PULLUP_YES)
				{
					/*Active the Internal Pull-up of the Pin*/
					ClrBit(SFIOR,PUD);
					ClrBit(DDRB_Register,PIN);
					SetBit(PORTB_Register,PIN);
				}
				else 
				{
					//Disable the Internal Pull-up of the PIN
					ClrBit(PORTB_Register,PIN);
				}
				break;
				
			case DIO_PORTC:
				if(Connect_PullUP == DIO_PIN_PULLUP_YES)
				{
					/*Active the Internal Pull-up of the Pin*/
					ClrBit(SFIOR,PUD);
					ClrBit(DDRC_Register,PIN);
					SetBit(PORTC_Register,PIN);
				}
				else 
				{
					//Disable the Internal Pull-up of the PIN
					ClrBit(PORTC_Register,PIN);
				}
				break;
					
			case DIO_PORTD:
				if(Connect_PullUP == DIO_PIN_PULLUP_YES)
				{
					/*Active the Internal Pull-up of the Pin*/
					ClrBit(SFIOR,PUD);
					ClrBit(DDRD_Register,PIN);
					SetBit(PORTD_Register,PIN);
				}
				else 
				{
					//Disable the Internal Pull-up of the PIN
					ClrBit(PORTA_Register,PIN);
				}
				break;
				
		}
	}		
	else
	{
		LOC_enumState = DIO_NOK;
	}
	return LOC_enumState;
}

/*Disable The Internal Pullup of all pins*/
void DIO_Disable_Internal_PullUp_AllPins	(void)
{
	SetBit(SFIOR,PUD);
}

/*This Function set the Direction of the full PORT */
DIO_ErrorStatus DIO_enumSetPortDirection     	(u8  PORT, u8  Direction  	)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	if(PORT <=DIO_PORTD)
	{
		switch(PORT)
		{
		case DIO_PORTA : DDRA_Register = Direction ;break;
		case DIO_PORTB : DDRB_Register = Direction ;break;
		case DIO_PORTC : DDRC_Register = Direction ;break;
		case DIO_PORTD : DDRD_Register = Direction ;break;
		}

	}
	else
		LOC_enumState = DIO_NOK;
	return LOC_enumState ;
}

/*This Function set the Value of the full PORT in case it is an output PORT */
DIO_ErrorStatus DIO_enumSetPortValue         	(u8  PORT, u8 Value      	)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;

	if(PORT <=DIO_PORTD)
	{
		switch(PORT)
		{
		case DIO_PORTA : PORTA_Register = Value ;break;
		case DIO_PORTB : PORTB_Register = Value ;break;
		case DIO_PORTC : PORTC_Register = Value ;break;
		case DIO_PORTD : PORTD_Register = Value ;break;
		}

	}
	else
		LOC_enumState = DIO_NOK;

	return LOC_enumState ;
}

/*This function get the value of the full PORT*/
DIO_ErrorStatus DIO_enumGetPortValue         	(u8  PORT, u8 *  PtrData    	)
{

	DIO_ErrorStatus LOC_enumState = DIO_OK;

	if(PORT <=DIO_PORTD)
	{
		switch(PORT)
		{
		case DIO_PORTA : *PtrData = PINA_Register;break;
		case DIO_PORTB : *PtrData = PINB_Register;break;
		case DIO_PORTC : *PtrData = PINC_Register;break;
		case DIO_PORTD : *PtrData = PIND_Register;break;
		}

	}
	else
		LOC_enumState = DIO_NOK;

	return LOC_enumState ;
}

/*This function toggle the full PORT value in case if the PORT is output PORT  */
DIO_ErrorStatus DIO_enumTogglePortValue      	(u8  PORT                   	)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;

	if(PORT <=DIO_PORTD)
	{
		switch(PORT)
		{
		case DIO_PORTA : PORTA_Register = ~PORTA_Register;break;
		case DIO_PORTB : PORTB_Register = ~PORTA_Register;break;
		case DIO_PORTC : PORTC_Register = ~PORTA_Register;break;
		case DIO_PORTD : PORTD_Register = ~PORTA_Register;break;
		}

	}
	else
		LOC_enumState = DIO_NOK;

	return LOC_enumState ;
}
