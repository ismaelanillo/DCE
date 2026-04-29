/*
 * P6_Exercice1.c
 *
 * Created: 13/04/2026 12:55:48
 * Author : DCE
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "TMR1.h"
#include "PORTS.h"
#include "MACROS.h"

ISR(TIMER1_COMPA_vect) {
	TOGGLEBIT(GPIO0_OUT,LED0);
}
int main(void)
{
    GPIO_init();
	//Set TIMMER1 in mote CTC
	TMR1_CTC_Init();

	TMR1_CTC_Set(500);
	
	//Interrupts enable
	TMR1_CTC_enaInterrupt();
	sei();
	//Start counter
	TMR1_CTC_Start(DIV_CLK_256);
	
    while (1) 
    {
    }
}

