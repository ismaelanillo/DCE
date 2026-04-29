/*
 * main_c.c
 *
 * Created: 27/04/2026 10:58:26
 *  Author: DCE
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "TMR1.h"
#include "PORTS.h"
#include "MACROS.h"
#include "functionsADC.h"


ISR(TIMER1_COMPA_vect) {
	// 1. Test: Toggle PB0 para osciloscopio (Apartado c)
	TOGGLEBIT(GPIO0_OUT, PB0);
	
	// 2. Seleccionar canal (sin la espera bloqueante)
	ADMUX = (ADMUX & 0xF0) | (CHANNEL1 & 0x0F);
	
	// 3. Habilitar interrupción y DISPARAR (sin esperar)
	ADC_enable_Int();
	ADCSRA |= (1 << ADSC);
}
ISR(ADC_vect){
	uint16_t valor=ADC;
	
	if(valor>512){
		SETBIT(GPIO0_OUT,LED2);
	}else
		CLEARBIT(GPIO0_OUT,LED2);
	ADC_disable_Int();
}
int main(void) {
	GPIO_init();
	// Solo inicializa, no inicies conversión aquí
	ADC_Init_Single(VREF_VCC, ALIGN_RIGHT, ADC_PRE_128);

	TMR1_CTC_Init();
	TMR1_CTC_Set(500);
	TMR1_CTC_enaInterrupt();
	
	sei();
	
	TMR1_CTC_Start(DIV_CLK_256);
	
	while (1) {
		// Nada aquí
	}
}