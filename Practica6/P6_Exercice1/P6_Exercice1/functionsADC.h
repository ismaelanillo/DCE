/*
 * functionsADC.h
 *
 * Created: 06/04/2026 11:35:33
 *  Author: DCE
 */ 


#ifndef FUNCTIONSADC_H_
#define FUNCTIONSADC_H_

#include "ADC.h"
#include<avr/interrupt.h>

uint16_t ADC_read(uint8_t channel);

static inline void ADC_enable_Int(void){
	ADCSRA |= (1 << ADIE);
}

static inline void ADC_disable_Int(void){
	ADCSRA &= ~(1<<ADIE);
}
void ADC_Start_Conversion(uint8_t channel);
uint16_t get_ADC_Average(uint8_t channel, uint8_t num_samples);
#endif /* FUNCTIONSADC_H_ */