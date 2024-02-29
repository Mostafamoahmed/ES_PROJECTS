#include "DIO_interface.h"

#include "SSD_Interface.h"
#include "SSD_Private.h"

#include "STD_TYPES.h"
#include "BIT_MATH.h"

static u8 Local_SSD_NUMBERS[10] = SSD_Number_ARR ;

//This function set the port connected to the SSD to OUTPUT PORT
void SSD_Init(SSD_Type SSD_Configuration)
{
	 DIO_enumSetPortDirection    ( SSD_Configuration.DataPort ,DIO_PORT_OUTPUT );
}

//This function enable the ssd by enabling the common pin 
void SSD_Enable(SSD_Type SSD_Configuration)
{
	if ( SSD_Configuration.Type == SSD_COMMON_CATHODE )
	{
		 DIO_enumSetPinDirection ( SSD_Configuration.EnablePort, SSD_Configuration.EnablePin , DIO_PIN_OUTPUT );
		 DIO_enumSetPinValue		( SSD_Configuration.EnablePort , SSD_Configuration.EnablePin , DIO_PIN_LOW	);
	}
	else if ( SSD_Configuration.Type == SSD_COMMON_ANODE )
	{
		 DIO_enumSetPinDirection ( SSD_Configuration.EnablePort, SSD_Configuration.EnablePin , DIO_PIN_OUTPUT );
		 DIO_enumSetPinValue		( SSD_Configuration.EnablePort , SSD_Configuration.EnablePin , DIO_PIN_HIGH	);
	}
}

//This Function disable the ssd by disabling the common pin
void SSD_Disable(SSD_Type SSD_Configuration)
{
	if ( SSD_Configuration.Type == SSD_COMMON_CATHODE )
	{
		 DIO_enumSetPinDirection ( SSD_Configuration.EnablePort, SSD_Configuration.EnablePin , DIO_PIN_OUTPUT );
		 DIO_enumSetPinValue		( SSD_Configuration.EnablePort , SSD_Configuration.EnablePin , DIO_PIN_HIGH	);
	}
	else if ( SSD_Configuration.Type == SSD_COMMON_ANODE )
	{
		 DIO_enumSetPinDirection ( SSD_Configuration.EnablePort, SSD_Configuration.EnablePin , DIO_PIN_OUTPUT );
		 DIO_enumSetPinValue		( SSD_Configuration.EnablePort , SSD_Configuration.EnablePin , DIO_PIN_LOW	);
	}
}

//This function sends a number to the SSD
void SSD_SendNumber(SSD_Type SSD_Configuration , u8 Number)
{
	if (SSD_Configuration.Type == SSD_COMMON_CATHODE)
	{
		 DIO_enumSetPortValue         	(SSD_Configuration.DataPort, Local_SSD_NUMBERS[Number]);
	}
	else if (SSD_Configuration.Type == SSD_COMMON_ANODE)
	{
		 DIO_enumSetPortValue         	(SSD_Configuration.DataPort, ~(Local_SSD_NUMBERS[Number]));

	}
}
