/*
 * P2_exercice6.c
 *
 * Created: 02/03/2026 9:46:25
 * Author : DCE
 */ 

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
#include "GPIO.h"


int main(void)
{
   // --------------------- SETUP ---------------------------------------
   // 1. Set LED pin as output. All the I/O pins are inputs by default.
   //-----------------------------------------------------------------
  
   GPIO_Init(&GPIO0_MODE,LED0,OUTPUT);
   GPIO_Init(&GPIO0_MODE,BUTTON,INPUT);
   //---------------------------------------------------------------
   // 2. Enable the Pull-up resistor for the input PUSHBUTTON
   //-----------------------------------------------------------------
   GPIO_pullup(&GPIO0_OUT,BUTTON,ON);
   // --------------------- LOOP ----------------------------------------
   /*Read the state of the pushbutton and if pressed the LED is ON
   Keep in mind that when the PUSHBUTTON is released
   the reading in that pin is '1' due to the pull-up resistor.*/
   while (1){
	   //-----------------------------------------------------------------
	   // 1. If PUSHBUTTON is pressed
	   if (! GPIO_read(&GPIO0_IN,BUTTON)) { // (1<<PIND2) <-> “0000 0100”
		   //--------------------------------------------------------------------
		   // Not Zero is TRUE and Zero is FALSE
		   //--------------------------------------------------------------------
		   // 2. Switch ON the LED
		/* GPIO_write(&GPIO0_OUT,LED0,HIGH);
		    	   
   }else GPIO_write(&GPIO0_OUT,LED0,LOW);*/
		GPIO_toggle(&GPIO0_OUT,LED0);
		_delay_ms(300);
		}
  
   }
}



