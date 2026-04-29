/*
 * P2_exercice7.c
 *
 * Created: 02/03/2026 12:25:58
 * Author : DCE
 */ 

#include "PORTS.h"




int main(void)
{
	{
		GPIO_init();
		while (1)
		{
			if(!(GPIO0_IN & (1<<BUTTON)))
			GPIO0_OUT ^=(1<<LED);
			_delay_ms(200);
		}
	}
}

