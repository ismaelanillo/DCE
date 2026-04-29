/*
 * main_b.c
 *
 * Created: 23/02/2026 12:12:16
 *  Author: DCE
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
  
   GPIO0_MODE  |= (1<<LED0) | (1<<LED1) | (1<<LED2) | (1<<LED3);
   //---------------------------------------------------------------
   // 2. Enable the Pull-up resistor for the input PUSHBUTTON
   //-----------------------------------------------------------------
   GPIO0_OUT |= (1<<BUTTON);
   // --------------------- LOOP ----------------------------------------
   /*Read the state of the pushbutton and if pressed the LED is ON
   Keep in mind that when the PUSHBUTTON is released
   the reading in that pin is '1' due to the pull-up resistor.*/
   while (1){
	   //-----------------------------------------------------------------
	   // 1. If PUSHBUTTON is pressed
	   if (! (GPIO0_IN & (1 << BUTTON))) { // (1<<PIND2) <-> “0000 0100”
		   //--------------------------------------------------------------------
		   // Not Zero is TRUE and Zero is FALSE
		   //--------------------------------------------------------------------
		   // 2. Switch ON the LED
		   
		   GPIO0_OUT |=  0x78;
		   _delay_ms(200);
		   GPIO0_OUT &= ~0x78;
		   //-------------------------------------------------------------------
		   }else{
		   //-------------------------------------------------------------------
		   // 3. else switch OFF the LED
		   GPIO0_OUT = (GPIO0_OUT & ~0x78)| 0x28;
		   //-------------------------------------------------------------------
	   }
	   _delay_ms(1000);
   }
}


