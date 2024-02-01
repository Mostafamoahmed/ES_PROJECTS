/*
 * BIT_MATH.h
 *
 *  Created on: Dec 9, 2023
 *      Author: mosta
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SetBit(reg,bit)				reg|=(1<<bit)
#define ClrBit(reg,bit)				reg&=(~(1<<bit))
#define ToggleBit(reg,bit)			reg^=(1<<bit)
#define GetBit(reg,bit)				(reg&(1<<bit))>>bit

#endif /* BIT_MATH_H_ */
