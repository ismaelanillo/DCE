/*
 * USART.c
 *
 * Created: 23/03/2026 10:30:06
 *  Author: DCE
 */ 
#include "USART.h"

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


char USART0_getchar_NoBlocking(void){
	if(!(UCSR0A & (1<<RXC0))){
		return -1;
	}
	return UDR0;
}