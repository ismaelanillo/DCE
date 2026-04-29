/*
 * main_b.c
 *
 * Created: 02/03/2026 12:39:28
 *  Author: DCE
 */ 

#include "PORTS.h"
#include "MACROS.h"




int main(void)
{
		GPIO_init();
		while (1)
		{
			if(READ_PIN(GPIO0_IN,BUTTON) == PRESSED ){
				TOGGLEBIT(GPIO0_OUT,LED);
				_delay_ms(300);
			}
	}
}