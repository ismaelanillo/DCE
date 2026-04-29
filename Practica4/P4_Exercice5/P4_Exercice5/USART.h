/*
 * USART.h
 *
 * Created: 23/03/2026 10:27:04
 *  Author: DCE
 */ 


#ifndef USART_H_
#define USART_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include<util/delay.h>
#include<stdint.h>
#include<stdbool.h>

#define BAUD 9600
#define UBRR_VALUE ((F_CPU/ (16UL * BAUD)) -1)


static inline void USART0_init(uint16_t baudrate){
	//Set the BAUDRATE
	uint16_t ubrr_val= ((F_CPU / (16UL * baudrate)) -1);
	UBRR0H= (unsigned char)(ubrr_val >> 8);
	UBRR0L= (unsigned char)ubrr_val;
	
	//Enable receiver and transmitter(UCSR0B)
	UCSR0B= (1<< TXEN0) | (1 << RXEN0);
	
	UCSR0C= (1<<UCSZ01) | (1 << UCSZ00);
}

void USART0_putchar (char data );
void USART0_putString(char *strPointer);
char USART0_getchar(void);
char USART0_getchar_NoBlocking(void);

void USART0_enaINT_TX();
void USART0_disaINT_TX();
void USART0_enaINT_RX();



#endif /* USART_H_ */