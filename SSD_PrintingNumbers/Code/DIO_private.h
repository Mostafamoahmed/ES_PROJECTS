/*
 * DIO_private.h
 *
 *  Created on: Dec 23, 2023
 *      Author: mosta
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#define PORTA_Register  *((volatile u8*) 0x3B)
#define PINA_Register 	*((volatile u8*) 0x39)
#define DDRA_Register 	*((volatile u8*) 0x3A)

#define PORTB_Register 	*((volatile u8*) 0x38)
#define PINB_Register 	*((volatile u8*) 0x36)
#define DDRB_Register 	*((volatile u8*) 0x37)

#define PORTC_Register  *((volatile u8*) 0x35)
#define PINC_Register   *((volatile u8*) 0x33)
#define DDRC_Register   *((volatile u8*) 0x34)

#define PORTD_Register 	*((volatile u8*) 0x32)
#define PIND_Register	*((volatile u8*) 0x30)
#define DDRD_Register	*((volatile u8*) 0x31)


#endif /* DIO_PRIVATE_H_ */
