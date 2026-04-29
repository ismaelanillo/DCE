/*
 * ADC.h
 *
 * Created: 06/04/2026 10:57:50
 *  Author: DCE
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>
#include <stdlib.h>

#define VREF_AREF 0 //REFS1-0= '00'
#define VREF_VCC 1 //REFS1-0= "01"
#define ALIGN_RIGHT 0 //ADLAR=0
#define ALIGN_LEFT 1 //ADLAR=1
#define ADC_PRE_2 1 //001
#define ADC_PRE_4 2 //010
#define ADC_PRE_8 3 //011
#define ADC_PRE_16 4 //100
#define ADC_PRE_32 5 //101
#define ADC_PRE_64 6 //110
#define ADC_PRE_128 7 //111
static inline void ADC_Init_Single(uint8_t V_ref, uint8_t align_format, uint8_t prescaler){
	// Delete a previous configuration in ADMUX and ADCSRA
	ADMUX= 0x00;
	ADCSRA= 0x00;
	//Select Vref
	ADMUX |= (V_ref << REFS0);
	//Select align
	ADMUX |= (align_format << ADLAR);
	//Select pre-scaler
	ADCSRA |= (prescaler & 0x07);
	//Enable ADC (ADEN= '1')
	ADCSRA |= (1<<ADEN);
	//Single mode is activate for default
}



#endif /* ADC_H_ */