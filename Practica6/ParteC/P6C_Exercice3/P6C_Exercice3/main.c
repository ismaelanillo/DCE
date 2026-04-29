/*
 * P6C_Exercice3.c
 *
 * Created: 27/04/2026 13:03:03
 * Author : DCE
 */ 

#include <avr/io.h>
#include "MACROS.h"
#include "PORTS.h"
#include "functionsADC.h"
#include "TMR0.h"
ISR(ADC_vect){
	// 1. Leer el valor de 10 bits del ADC
	uint16_t valorADC = ADC;
	
	// 2. Convertir 10 bits (0-1023) a 8 bits (0-255) para el PWM
	// Simplemente desplazando 2 bits a la derecha o dividiendo entre 4
	uint8_t valorPWM = (uint8_t)(valorADC >> 2);
	
	// 3. Actualizar el ciclo de trabajo del PWM
	OCR0A = valorPWM;
	ADCSRA |= (1 << ADSC);
}
int main(void)
{
	GPIO_init();
	TMR0_PWM_Phase_Init();
	TMR0_PWM_Phase_Start(DIV_CLK_64);
	
	ADC_Init_Single(VREF_VCC,ALIGN_RIGHT,ADC_PRE_128);
    
	ADC_enable_Int();
	sei();
	ADC_Start_Conversion(CHANNEL1);
    while (1) 
    {
		
    }
}

