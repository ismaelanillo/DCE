/*
 * main_b.c
 *
 * Created: 23/03/2026 13:45:06
 *  Author: DCE
 */ 
#include <avr/io.h>
#include "USART.h"
#include "PORTS.h"
#include "EXT_INT.h"


volatile const char msg[]= "Hello World\r\n";
volatile const char *msg_ptr;
ISR(INT0_vect){
	msg_ptr= &msg[0];
	USART0_enaINT_TX();
	
}
ISR(USART_UDRE_vect){
	if(*msg_ptr != '\0'){
		UDR0=*msg_ptr;
		msg_ptr++;
	}else
		USART0_disaINT_TX();
}
int main(void)
{
	USART0_init(BAUD);
	GPIO_init();
	INT0_config(FALLING);
	INT0_enable();
	sei();
	while (1)
	{
	}
}