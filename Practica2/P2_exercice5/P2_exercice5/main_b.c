/*
 * main_b.c
 *
 * Created: 23/02/2026 12:54:20
 *  Author: DCE
 */ 

#include "AVR_PORTS_STRUCTURE.h"
#include <util/delay.h>

int main(void)
{
	GPIOD->MODE |= (1<<LED0);
	GPIOD->OUT |= (1<<BUTTON);
	while (1)
	{
		if(!(GPIOD->IN & (1<<BUTTON)))
		GPIOD->OUT ^=(1<<LED0);
		_delay_ms(200);
	}
}

//168 bytes