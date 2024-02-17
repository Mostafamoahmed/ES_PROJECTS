#ifndef CLCLD_CONFIG_H_
#define CLCLD_CONFIG_H_

/*Choose either 8 Bites Mode or 4 Bites Mode
 1- 4
 2- 8
*/
#define CLCD_MODE                              8

/*Choose from the options below The Dtata Port D0---->D7
1-DIO_PORTA
2-DIO_PORTB
3-DIO_PORTC
4-DIO_PORTD
*/
#define CLCD_DATA_PORT                      DIO_PORTA 

/*Choose from the options below the Control Port RS,RW,EN
1-DIO_PORTA
2-DIO_PORTB
3-DIO_PORTC
4-DIO_PORTD
*/
#define CLCD_CONTROLE_PORT                  DIO_PORTB

/*Choose from the options below the controle Pins 
1-DIO_PIN0
2-DIO_PIN1
3-DIO_PIN2
4-DIO_PIN3
5-DIO_PIN4
6-DIO_PIN5
7-DIO_PIN6
8-DIO_PIN7
*/
#define CLCD_RS                            DIO_PIN0
#define CLCD_RW                            DIO_PIN1
#define CLCD_EN                            DIO_PIN2

#endif