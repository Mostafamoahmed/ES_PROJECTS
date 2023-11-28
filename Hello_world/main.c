# include  <avr/io.h>

void main()
{
	DDRA = 0X01 ; //Ob00000001 , set pin 0 of port A to output
	PORTA = 0X01; // set pin 0 of port A to high

}
