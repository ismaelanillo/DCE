/*
 * main_c.c
 *
 * Created: 16/03/2026 10:52:02
 *  Author: DCE
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "PORTS.h"
#include "MACROS.h"
#include "EXT_INT.h"


//-------- Interrupt Service Routines --------------------------
// If INT0 interrupt is enabled, each time the pushbutton is
// pressed, the int interrupt is triggered. Then all the actions
// written into the ISR are executed. When it finishes, the flag is
// cleared and the main program continues.
volatile uint8_t incr=1;
volatile uint8_t count=0;
ISR(INT0_vect) {
	//--------------------------------------------------------
	// 1.- Toggle the red LED
	//--------------------------------------------------------
	incr++;
	if(incr >= MAX_INCREMENT+1) incr=1;
	_delay_ms (300); // Not recommended!!
	
}


int main(void) {
	// ------------ SETUP ----------------------------------------
	// -----------------------------------------------------------
	// 1.- Configure ports
	// -----------------------------------------------------------
	GPIO_init();
	
	
	// -----------------------------------------------------------
	// 2.-  Configure external interrupt
	// -----------------------------------------------------------
	INT0_config(FALLING);
	
	INT0_enable();
	// -----------------------------------------------------------
	// 3.- Enable global interrupts
	// -----------------------------------------------------------
	sei();    // Equivalent to SREG |=(1<<I);
	
	//------------ SUPER LOOP ----------------------------------------
	while (1) {
		count+=incr;
		if(count > 15) count=0;
		GPIO0_OUT = (GPIO0_OUT & 0x0F) | (count<<4);
		_delay_ms(1000);
		
		
	}
}
