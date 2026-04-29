/*
 * P2_exercice5.c
 *
 * Created: 23/02/2026 12:28:35
 * Author : DCE
 */ 

//168 bytes

#define F_CPU 16000000UL
#include "AVR_PORTS.h"
#include<util/delay.h>


int main(void)
{
   GPIO0_MODE |= (1<<LED0);
   GPIO0_OUT |= (1<<BUTTON);
    while (1) 
    {
		if(!(GPIO0_IN & (1<<BUTTON)))
			GPIO0_OUT ^=(1<<LED0);
		_delay_ms(200);
    }
}

