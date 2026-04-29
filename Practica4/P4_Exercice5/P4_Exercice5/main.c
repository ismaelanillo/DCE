/*
 * P4_Exercice5.c
 *
 * Created: 23/03/2026 13:32:55
 * Author : DCE
 */ 

#include <avr/io.h>
#include "USART.h"
#include "PORTS.h"
#include "EXT_INT.h"


ISR(INT0_vect){
	USART0_putString("Hello world\r\n");
	
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

