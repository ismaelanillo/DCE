/*
 * P4_Exercice4.c
 *
 * Created: 23/03/2026 12:33:19
 * Author : DCE
 */ 

#include <avr/io.h>
#include "USART.h"
#include "PORTS.h"
#include "MACROS.h"
#include "EXT_INT.h"

volatile unsigned char tx_char= 0x20;
volatile unsigned char rx_char= 0x00;

ISR(INT0_vect){
	USART0_putchar(tx_char);
	
	tx_char++;
	
	if(tx_char > 0x7E){tx_char=0x20;} //0x7E
	_delay_ms(200);
		
}

ISR(USART_RX_vect){
	rx_char= UDR0;
	USART0_putchar(rx_char);
}
int main(void)
{
   GPIO_init();
   USART0_init(BAUD);
   INT0_config(FALLING);
   INT0_enable();
   USART0_enaINT_RX();
   sei();
   USART0_putString("Bienvenido\r\n");
    while (1) 
    {
		GPIO0_OUT = (GPIO0_OUT & 0x0F) | ((rx_char & 0x0F) << 4);
    }
}

