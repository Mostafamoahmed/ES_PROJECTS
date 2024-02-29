#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SW_private.h"
#include "SW_config.h"
#include "SW_Interface.h"

//This function set the the pin connected to the switch to be input pin 
void SW_Init(SW_Type SW_Config)
{
	DIO_enumSetPinDirection 		(SW_Config.PORT,SW_Config.PIN,DIO_PIN_INPUT	);
	
	//Enable the Internal PullUp
	if(SW_Config.PULLup_STATE == SW_INT_PULL_UP)
	{
		//DIO_enumSetPinValue    ( SW_Config.PORT , SW_Config.PIN , DIO_PIN_HIGH  );
		 DIO_enumConnect_Disconnect_Pullup			(SW_Config.PORT , SW_Config.PIN, DIO_PIN_PULLUP_YES);
	}
}

u8 SW_GetPressed(SW_Type SW_Config)
{
	u8 Data;
	u8 Result = SW_NotPressed;
	if((SW_Config.PULLup_STATE == SW_EXT_PULL_UP) || (SW_Config.PULLup_STATE == SW_INT_PULL_UP))
	{
		DIO_enumGetPinValue				(SW_Config.PORT,SW_Config.PIN, &Data	);
		if((Data)==1)
		{
			Result = SW_NotPressed ;
		}
		else
		{
			Result = SW_Pressed ;
		}
	}
	else if (SW_Config.PULLup_STATE == SW_EXT_PULL_DOWN)
	{
		DIO_enumGetPinValue				(SW_Config.PORT,SW_Config.PIN, &Data	);
		if((Data)==1)
		{
			Result = SW_Pressed ;
		}
		else
		{
			Result = SW_NotPressed ;
		}
	}


	return Result;
}
