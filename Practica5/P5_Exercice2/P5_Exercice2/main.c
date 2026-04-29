/*
 * P5_Exercice2.c
 *
 * Created: 06/04/2026 13:19:30
 * Author : DCE
 */ 

#include <avr/io.h>
#include "PARAMETERS.h"
#include "functionsADC.h"
#include "PORTS.h"
#include "MACROS.h"
#include "USART.h"
#include <avr/interrupt.h>

volatile uint16_t adc_val=0;
ISR(ADC_vect) {
	adc_val = ADC;
	
	if(adc_val < SETPOINT)
		SETBIT(GPIO0_OUT, LED0);
	else
		CLEARBIT(GPIO0_OUT, LED0);
}
int main(void)
{
   GPIO_init();
   USART0_init(9600);
   
   
   //Enable ADC
   ADC_Init_Single(VREF_VCC,ALIGN_RIGHT,ADC_PRE_128);
   
   ADC_Start_Conversion(CHANNEL1);
   
     
   //Enable interrupts
   ADC_enable_Int();
   sei();
   
   char buffer[10];
    while (1) 
    {
		
		ADCSRA |= (1 << ADSC);
			
		//USART	
		utoa(adc_val,buffer,10);
		USART0_putString("Lectura: ");
		USART0_putString(buffer);
		USART0_putString("\r\n");
		_delay_ms(SAMPLE_TIME);
    }
}

