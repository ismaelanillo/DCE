/*
 * main_b.c
 *
 * Created: 16/03/2026 12:45:57
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

ISR(PCINT2_vect) {
	if(!(GPIO0_IN & (1 << BUTTON))){
	//--------------------------------------------------------
	// 1.- Toggle the red LED
	//--------------------------------------------------------
		TOGGLEBIT (GPIO0_OUT, RED_LED);  // Toggle the RED_LED
	}
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
	
	PCINT2_config(PCINT18);
	PCINT2_init();
	// -----------------------------------------------------------
	// 3.- Enable global interrupts
	// -----------------------------------------------------------
	sei();    // Equivalent to SREG |=(1<<I);
	
	//------------ SUPER LOOP ----------------------------------------
	while (1) {
		// -----------------------------------------------------------
		// 1.- Toggle the green LD
		// -----------------------------------------------------------
		TOGGLEBIT (GPIO0_OUT, GREEN_LED);
		_delay_ms(BLINK_TIME);
	}
}
