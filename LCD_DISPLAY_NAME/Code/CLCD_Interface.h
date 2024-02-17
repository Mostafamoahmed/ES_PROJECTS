#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

#include "STD_TYPES.h"

#include "CLCD_Config.h"

#if CLCD_MODE == 8
#define EIGHT_BITS_MODE 0X38 //2 Number of lines , 5x8 Font

#elif CLCD_MODE == 4    
#define FOUR_BITS_MODE 0x28
#endif

//////////////////////////////////////// Commands /////////////////////////////////////////////////////
#define CLCD_SET_CURSOR             0x80






/////////////////////////////////////// Positions /////////////////////////////////////////////////////

//ROWS
#define  CLCD_ROW_1                 0
#define  CLCD_ROW_2                 1

//COLUMNS 
#define CLCD_COL_1                  0
#define CLCD_COL_2                  1
#define CLCD_COL_3                  2
#define CLCD_COL_4                  3
#define CLCD_COL_5                  4
#define CLCD_COL_6                  5
#define CLCD_COL_7                  6
#define CLCD_COL_8                  7
#define CLCD_COL_9                  8
#define CLCD_COL_10                 9
#define CLCD_COL_11                 10
#define CLCD_COL_12                 11
#define CLCD_COL_13                 12
#define CLCD_COL_14                 13
#define CLCD_COL_15                 14
#define CLCD_COL_16                 15


//functions 
void Void_Init                      (void);
void Void_SendCommand               (u8 Command);
void Void_SendData                  (u8 Data);
void Void_ClearScreen               (void);
void Void_SendString                ( const u8 *String);
void Void_SetPosition               (u8 ROW, u8 COL);

#endif