#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "CLCD_Interface.h"
#include "CLCD_Config.h"
#include "CLCD_Private.h"

#include <avr/delay.h>

//This Function Initialize the LCD according to the 8 Bits Mode 
void Void_Clcd_Init                      (void)
{
    _delay_ms(50);
    DIO_enumSetPortDirection     	( CLCD_DATA_PORT     , DIO_PORT_OUTPUT  	);
    DIO_enumSetPinDirection         ( CLCD_CONTROLE_PORT , CLCD_RS , DIO_PIN_OUTPUT  );
	DIO_enumSetPinDirection         ( CLCD_CONTROLE_PORT , CLCD_RW , DIO_PIN_OUTPUT  );
	DIO_enumSetPinDirection         ( CLCD_CONTROLE_PORT , CLCD_EN , DIO_PIN_OUTPUT  );
    _delay_ms(2);
    Void_SendCommand(0x0f);
    _delay_ms(2);
    Void_SendCommand(0x01);
    _delay_ms(10);
    Void_SendCommand(0x06);


}

//This Function send commnad to the LCD 
void Void_SendCommand(u8 Command)
{
    /////////////////////////// 8 Bits Mode ///////////////////////////////////
    DIO_enumSetPortValue         	( CLCD_DATA_PORT, Command     	);
    DIO_enumSetPinValue				( CLCD_CONTROLE_PORT,CLCD_RS,DIO_PIN_LOW );
    DIO_enumSetPinValue				( CLCD_CONTROLE_PORT,CLCD_RW,DIO_PIN_LOW );
    CLCD_Void_SendFallingEdge       ( );

}

//This Function sends data to the LCD 
void Void_SendData(u8 Data)
{
    /////////////////////// 8 Bits Mode ////////////////
    DIO_enumSetPortValue         	( CLCD_DATA_PORT, Data     	);
    DIO_enumSetPinValue				( CLCD_CONTROLE_PORT,CLCD_RS,DIO_PIN_HIGH );
    DIO_enumSetPinValue				( CLCD_CONTROLE_PORT,CLCD_RW,DIO_PIN_LOW );
    CLCD_Void_SendFallingEdge       ( );

}

//This Function Sends falling Edge to the Enable Pin 
static void CLCD_Void_SendFallingEdge       (void)
{
    DIO_enumSetPinValue				( CLCD_CONTROLE_PORT,CLCD_EN,DIO_PIN_HIGH );
    _delay_ms(1);
    DIO_enumSetPinValue				( CLCD_CONTROLE_PORT,CLCD_EN,DIO_PIN_LOW );
    _delay_ms(1);

}

//This Function Clear The Screen of the LCD
void Void_ClearScreen               (void)
{
     Void_SendCommand(0X01);
    _delay_ms(10);
}

//This Function Sends String to the LCD 
void Void_SendString( const u8 *String)
{
    u16 Iterator = 0 ;
    while (String[Iterator] !='\0')
    {
        Void_SendData(String[Iterator]);
        Iterator ++;
    }
}

//This Function Set the position of the Cursor 
void Void_SetPosition               (u8 ROW, u8 COL)
{
    u8 position ;
    if (ROW != CLCD_ROW_1 || ROW != CLCD_ROW_2 || COL > CLCD_COL_16 || COL < CLCD_COL_1 )
    {
        position = CLCD_SET_CURSOR;
    }
    else if (ROW == CLCD_ROW_1)
    {
        position = CLCD_SET_CURSOR + COL;
    }
    else if (ROW == CLCD_ROW_2)
    {
        position = (CLCD_SET_CURSOR + 64) + COL;
    }
    Void_SendCommand(position);
    _delay_ms(1);
}
