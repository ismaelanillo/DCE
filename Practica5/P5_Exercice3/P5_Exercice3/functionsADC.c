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

uint16_t get_ADC_Average(uint8_t channel, uint8_t num_samples) {
	uint32_t sum = 0; // Usamos 32 bits para evitar desbordamiento al sumar muchas muestras
	uint8_t shift = 0;

	// Determinamos cuánto desplazar según el número de muestras (división por potencia de 2)
	switch (num_samples) {
		case 2:  shift = 1; break;
		case 4:  shift = 2; break;
		case 8:  shift = 3; break;
		case 16: shift = 4; break;
		case 32: shift = 5; break;
		case 64: shift = 6; break;
		default: shift = 0; break;
	}

	for (uint8_t i = 0; i < num_samples; i++) {
		sum += ADC_read(channel); // Reutilizamos tu función ADC_read que ya hace polling
	}

	return (uint16_t)(sum >> shift); // División ultra rápida
}

