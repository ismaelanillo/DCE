/*
 * TMR1.h
 *
 * Created: 13/04/2026 12:56:23
 *  Author: DCE
 */ 


#ifndef TMR1_H_
#define TMR1_H_
#include <avr/io.h>
#include "PORTS.h"
#define DIV_CLK_1 1
#define DIV_CLK_8 2
#define DIV_CLK_64   3  
#define DIV_CLK_256  4
#define DIV_CLK_1024 5 
#define PRESCALER 256

static inline void TMR1_CTC_Init(){
	// Limpiar TCCR1A y TCCR1B (Modo Normal por defecto)
	TCCR1A = 0;
	TCCR1B = 0;
	
	// Configurar modo CTC: WGM12 es el bit 3 de TCCR1B
	TCCR1B |= (1 << WGM12);
}
static inline void TMR1_CTC_enaInterrupt(){
	TIMSK1 |=  (1<<OCIE1A);
}
static inline void TMR1_CTC_disInterrupt(){
	TIMSK1 &=~(1<<OCIE1A);
}

static inline void TMR1_CTC_Start(uint8_t divClock){
	// Limpiamos primero los bits del prescaler (CS12, CS11, CS10)
	// para evitar conflictos si se llama varias veces.
	TCCR1B &= ~((1 << CS12) | (1 << CS11) | (1 << CS10));
	
	// Aplicamos el nuevo divisor recibido en el argumento
	TCCR1B |= (divClock & 0x07);
}
static inline void TMR1_CTC_Stop() {
	TCCR1B &= ~((1 << CS12) | (1 << CS11) | (1 << CS10));
}
static inline void TMR1_CTC_Set(uint16_t valueCounterA) { //valor counter s
	/* * CALCULO DEL VALOR DE COMPARACIÓN PARA EL TIMER1 (Mode CTC)
 * ---------------------------------------------------------
 * Objetivo: 500ms (0.5 segundos) para lograr parpadeo de 1Hz. 
 * Frecuencia CPU (F_CPU): 16,000,000 Hz (Arduino UNO) 
 * Prescaler (N): 256 
 * * Fórmula: Ticks = (Tiempo * F_CPU) / N
 * Ticks = (0.5 s * 16,000,000 Hz) / 256
 * Ticks = 8,000,000 / 256 = 31,250
 */
	uint32_t ticks = ((uint32_t)valueCounterA * (F_CPU / 1000)) / PRESCALER;
	OCR1A = (uint16_t)(ticks - 1);
}

static inline void TMR1_HW_toogleOC1A() {
	// 1. Configurar PB1 (OC1A) como salida
	DDRB |= (1 << DDB1);

	// 2. Configurar el modo de comparación para Togle OC1A en Compare Match
	// COM1A1=0, COM1A0=1
	TCCR1A &= ~(1 << COM1A1);
	TCCR1A |= (1 << COM1A0);
}


#endif /* TMR1_H_ */