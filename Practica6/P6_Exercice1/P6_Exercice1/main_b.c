/*
 * main_b.c
 *
 * Created: 27/04/2026 10:37:10
 *  Author: DCE
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "TMR1.h"
#include "PORTS.h"
#include "MACROS.h"


int main(void)
{
	GPIO_init();
	//Set TIMMER1 in mote CTC
	TMR1_CTC_Init();

	TMR1_CTC_Set(500);
	TMR1_HW_toogleOC1A();
	
	//Start counter
	TMR1_CTC_Start(DIV_CLK_256);
	
	while (1)
	{
	}
}