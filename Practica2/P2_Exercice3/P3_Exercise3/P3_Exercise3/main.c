/*
 * P3_Exercise3.c
 *
 * Created: 23/02/2026 10:26:27
 * Author : DCE
 */ 

#define F_CPU  16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
   // --------------------- SETUP ---------------------------------------
   // 1. Set LED pin as output. All the I/O pins are inputs by default.
   //-----------------------------------------------------------------
   DDRD  |= (1<<DDD3);
   //---------------------------------------------------------------
   // 2. Enable the Pull-up resistor for the input PUSHBUTTON
   //-----------------------------------------------------------------
   PORTD |= (1<<PORTD2);
   // --------------------- LOOP ----------------------------------------
   /*Read the state of the pushbutton and if pressed the LED is ON
   Keep in mind that when the PUSHBUTTON is released
   the reading in that pin is '1' due to the pull-up resistor.*/
   while (1){
	   //-----------------------------------------------------------------
	   // 1. If PUSHBUTTON is pressed
	   if (! (PIND & (1 << PIND2))) { // (1<<PIND2) <-> “0000 0100”
		   // ------------------------------------------------------------------
		   // PIND	|	MASK	|
		   //-------------------------------------------------------------------
		   // If (XXXX X1XX & 0000 0100 = 0000 0100) ? Result is not Zero because
		   //
		   // PIND2=’1’ (Pushbutton released, not pressed)
		   // If (XXXX X0XX & 0000 0100 = 0000 0000) ? Result is Zero because
		   // PIND2=’0’ (Pushbutton pressed)
		   //--------------------------------------------------------------------
		   // Not Zero is TRUE and Zero is FALSE
		   //--------------------------------------------------------------------
		   // 2. Switch ON the LED
		   PORTD |= (1<<PORTD3);
		   //-------------------------------------------------------------------
		   }else{
		   //-------------------------------------------------------------------
		   // 3. else switch OFF the LED
		   PORTD &= (~(1<<PORTD3));
		   //-------------------------------------------------------------------
	   }
   }
}

