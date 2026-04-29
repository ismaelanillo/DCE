/*
 * P2_exercice4.c
 *
 * Created: 23/02/2026 11:09:12
 * Author : DCE
 */ 

#define F_CPU  16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "PORTS.h"


int main(void)
{
   // --------------------- SETUP ---------------------------------------
   // 1. Set LED pin as output. All the I/O pins are inputs by default.
   //-----------------------------------------------------------------
    DDRD  |= (1<<DDD3) | (1<<DDD4) | (1<<DDD5) | (1<<DDD6);
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
		   //--------------------------------------------------------------------
		   // Not Zero is TRUE and Zero is FALSE
		   //--------------------------------------------------------------------
		   // 2. Switch ON the LED
		   
		   PORTD|=  0x78;
		   _delay_ms(200);
		   PORTD &= ~0x78;
		   //-------------------------------------------------------------------
		   }else{
		   //-------------------------------------------------------------------
		   // 3. else switch OFF the LED
		   PORTD = (PORTD & ~0x78)| 0x28;
		   //-------------------------------------------------------------------
	   }
	   _delay_ms(1000);
   }
}

