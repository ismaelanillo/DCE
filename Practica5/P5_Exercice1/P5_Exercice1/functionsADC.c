/*
 * functionsADC.c
 *
 * Created: 06/04/2026 11:18:44
 *  Author: DCE
 */ 

#include "functionsADC.h"

uint16_t ADC_read(uint8_t channel){
	//Clear flag ADIF('1')
	ADCSRA |= (1<<ADIF);
	//Clear a previous selected channel
	ADMUX &= 0xF0;
	//Select A/D input channel
	ADMUX |= (channel & 0x0F);
	//Start new conversion, ADSC='1'
	ADCSRA |= (1<<ADSC);
	while(!(ADCSRA & (1<<ADIF)));
	return ADC;
}