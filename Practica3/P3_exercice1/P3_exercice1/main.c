/*
 * P3_exercice1.c
 *
 * Created: 09/03/2026 12:20:23
 * Author : DCE
 */ 

 
 
 #define F_CPU 16000000UL
 #include <avr/io.h>
 #include <avr/interrupt.h>
 #include <util/delay.h>
 #include "PORTS.h"
 #include "MACROS.h"
 
 
 //-------- Interrupt Service Routines --------------------------
 // If INT0 interrupt is enabled, each time the pushbutton is
 // pressed, the int interrupt is triggered. Then all the actions
 // written into the ISR are executed. When it finishes, the flag is
 // cleared and the main program continues.
 
 ISR(INT0_vect) {
	 //--------------------------------------------------------
	 // 1.- Toggle the red LED
	 //--------------------------------------------------------
	 TOGGLEBIT (GPIO0_OUT, RED_LED);  // Toggle the RED_LED
	 //--------------------------------------------------------------------
	 // 2. To avoid a new interrupt due to a falling edge caused by bouncing
	 //--------------------------------------------------------------------
	 _delay_ms (100); // Not recommended!!
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
	 // 2.1. Disable INT0 interrupts (safety to avoid spurious interrupt during
	 // the change of the bits, in the case INT0 and SREG was already enabled)
	 EIMSK &= ~(1 << INT0);
	 // 2.2. Setup the falling edge as interrupt trigger (mask & set)
	 // Clear the bits related to INTO setup (previous setup) --MASK
	 EICRA &= ~((1 << ISC01) | (1 << ISC00));
	 // Setup the falling edge (INT0 trigger) --SET
	 EICRA |= (1<<ISC01);
	 // 2.3. Clear the flag of a previous interrupt (writing '1')
	 EIFR |= (1 << INTF0);
	 // 2.4. Enable the INT0 interrupts
	 EIMSK |= (1<<INT0);
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

