/*
 * main_b.c
 *
 * Created: 06/04/2026 12:43:58
 *  Author: DCE
 */ 

#include "USART.h"
#include "functionsADC.h"
#include "PORTS.h"

int main(void){
	USART0_init(9600);
	ADC_Init_Single(VREF_VCC,ALIGN_RIGHT,ADC_PRE_128);
	uint16_t adc_val;
	adc_val=ADC_read(1);
	char buffer[7];
	while(1){
		adc_val=ADC_read(1);
		utoa(adc_val,buffer,10);
		
		USART0_putString("Valor ADC: ");
		USART0_putString(buffer);
		USART0_putString("\r\n");
		_delay_ms(500);
	}
}