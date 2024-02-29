/*
 * APP.h
 *
 *  Created on: Feb 26, 2024
 *      Author: mosta
 */

#ifndef APP_H_
#define APP_H_

typedef enum
{
   Idle =0,
   lEFT_BLINK,
   RIGHT_BLINK,
   HAZZARD_BLINK

}ModeState;

void Void_SetMode(ModeState Mode);
void Void_App_Init(void);
void Void_Mode_Task(void);


#endif /* APP_H_ */
