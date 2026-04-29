/*
 * P5_Exercice1.c
 *
 * Created: 06/04/2026 10:56:49
 * Author : DCE
 */ 

#include <avr/io.h>
#include "functionsADC.h"
#include "PORTS.h"
int main(void)
{
	GPIO_init();
	ADC_Init_Single(VREF_VCC,ALIGN_RIGHT,ADC_PRE_128);
	uint16_t result;
	result=ADC_read(1);
    while (1) 
    {
		GPIO0_OUT &= ~((1<<LED0) | (1<<LED1) | (1<<LED2) | (1<<LED3));
		result=ADC_read(1);
		if(result <= 255)
			GPIO0_OUT|=(1<<LED0);
		else if(result <= 512)
			GPIO0_OUT |=(1<<LED1);
		else if(result <= 768)
			GPIO0_OUT |= (1<<LED2);
		else GPIO0_OUT |= (1<<LED3);
		_delay_ms(100);
    }
	
	
}

