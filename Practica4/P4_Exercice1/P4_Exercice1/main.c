/*
 * P4_Exercice1.c
 *
 * Created: 23/03/2026 9:33:43
 * Author : DCE
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include<util/delay.h>

#define BAUD 9600
#define UBRR_VALUE ((F_CPU/ (16UL * BAUD)) -1)

void USART0_init(void);
void USART0_putchar (char data );
char USART0_getchar( void );
void USART0_putString(char *strPointer);


int main(void)
{
   USART0_init();
   
   while(!(UCSR0A & (1<<UDRE0)));
   UDR0= '0';
   _delay_ms(1000);
   
    while (1) 
    {
		USART0_putString("Hola Mundo\r\n");
		_delay_ms(2000);
    }
}

void USART0_init(void){
	//Set the BAUDRATE
	UBRR0H= (unsigned char)(UBRR_VALUE >> 8);
	UBRR0L= (unsigned char)UBRR_VALUE;
	
	//Enable receiver and transmitter(UCSR0B)
	UCSR0B= (1<< TXEN0) | (1 << RXEN0);
	
	UCSR0C= (1<<UCSZ01) | (1 << UCSZ00);
}

void USART0_putchar (char data ){
	while(!(UCSR0A & (1 << UDRE0)));
	UDR0=data;
}

void USART0_putString(char *strPointer){
	while(*strPointer){
		USART0_putchar(*strPointer);
		strPointer++;
	}
}

char USART0_getchar(void){
	while(!(UCSR0A & (1<<RXC0)));
	return UDR0;
}

