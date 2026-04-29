/*
 * TMR0.h
 *
 * Created: 27/04/2026 12:36:24
 *  Author: DCE
 */ 


/*
 * TMR0.h
 */ 

#ifndef TMR0_H_
#define TMR0_H_
#include <avr/io.h>
#include "PORTS.h"

// Los divisores del Timer0 son diferentes a los del Timer1. 
// Consulta el datasheet (Tabla del registro TCCR0B)
#define DIV_CLK_1    1
#define DIV_CLK_8    2
#define DIV_CLK_64   3
#define DIV_CLK_256  4
#define DIV_CLK_1024 5
#define PRESCALER 256

static inline void TMR0_CTC_Init(){
    // Limpiar registros
    TCCR0A = 0;
    TCCR0B = 0;
    
    // Configurar modo CTC: WGM01 es el bit 1 de TCCR0A
    TCCR0A |= (1 << WGM01);
}

static inline void TMR0_CTC_enaInterrupt(){
    TIMSK0 |= (1 << OCIE0A);
}

static inline void TMR0_CTC_disInterrupt(){
    TIMSK0 &= ~(1 << OCIE0A);
}

static inline void TMR0_CTC_Start(uint8_t divClock){
    TCCR0B &= ~((1 << CS02) | (1 << CS01) | (1 << CS00));
    TCCR0B |= (divClock & 0x07);
}

static inline void TMR0_CTC_Stop() {
    TCCR0B &= ~((1 << CS02) | (1 << CS01) | (1 << CS00));
}

static inline void TMR0_CTC_Set(uint16_t ms) {
    /* * ¡CUIDADO! El Timer0 es de 8 bits (máximo 255).
     * Si el resultado del cálculo > 255, no funcionará.
     */
    uint32_t ticks = ((uint32_t)ms * (F_CPU / 1000)) / PRESCALER;
    OCR0A = (uint8_t)(ticks - 1);
}

static inline void TMR0_HW_toogleOC0A() {
    // Configurar PD6 (OC0A en Arduino UNO) como salida
    DDRD |= (1 << DDD6);

    // Configurar modo Toggle: COM0A0 = 1
    TCCR0A &= ~(1 << COM0A1);
    TCCR0A |= (1 << COM0A0);
}

static inline void TMR0_PWM_Phase_Init(){
	// 1. Configurar los pines PD6 (OC0A) y PD5 (OC0B) como salidas
	DDRD |= (1 << DDD6) | (1 << DDD5);
	
	// 2. Seleccionar modo PWM Phase Correct (Modo 1)
	// Para modo 1: WGM00 = 1, WGM01 = 0, WGM02 = 0
	TCCR0A |= (1 << WGM00);
	
	// 3. Configurar salidas PWM para OC0A y OC0B
	// "Set OCxA/OCxB on Compare Match when up-counting,
	// Clear OCxA/OCxB on Compare Match when down-counting"
	// Esto es lo estándar para PWM Phase Correct (COM0A1=1, COM0B1=1)
	TCCR0A |= (1 << COM0A1) | (1 << COM0B1);
}

static inline void TMR0_PWM_Phase_Start(uint8_t divClock){
	// 1. Resetear el contador (opcional pero recomendado al iniciar)
	TCNT0 = 0x00;
	
	// 2. Limpiar los bits del prescaler antes de aplicar el nuevo valor
	TCCR0B &= ~((1 << CS02) | (1 << CS01) | (1 << CS00));
	
	// 3. Aplicar el prescaler recibido en el argumento
	// Los valores de divClock deben corresponder a los CS0x definidos en el datasheet
	TCCR0B |= (divClock & 0x07);
}
static inline void TMR0_PWM_Phase_Duty(uint8_t valueOCR0A, uint8_t valueOCR0B) {
	// Asignar el valor para el canal A (pin PD6/OC0A)
	OCR0A = valueOCR0A;
	
	// Asignar el valor para el canal B (pin PD5/OC0B)
	OCR0B = valueOCR0B;
}

#endif /* TMR0_H_ */