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

void ADC_Start_Conversion(uint8_t channel){
	// 1. Seleccionar el canal (limpiando los 4 bits bajos)
	ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);
	// 2. Hacer una lectura de descarte para estabilizar el ADC
	ADCSRA |= (1 << ADSC);
	while(ADCSRA & (1 << ADSC)); // Esperar a que termine
	// 3. LIMPIEZA CLAVE: Escribir un 1 en ADIF borra cualquier interrupción pendiente
	// Esto asegura que la próxima vez que se use el ADSC, la ISR se dispare limpia.
	ADCSRA |= (1 << ADIF);
}

