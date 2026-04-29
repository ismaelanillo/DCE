/*
 * CFile.c
 *
 * Created: 02/03/2026 11:33:12
 *  Author: DCE
 */ 
/*
 * P2_exercice6.c
 *
 * Created: 02/03/2026 9:46:25
 * Author : DCE
 */ 


#define F_CPU  16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "PORTS.h"
#include "GPIO.h"
#include "LED.h"
#include "PushButton.h"


int main(void)
{
   // --------------------- SETUP ---------------------------------------
   // 1. Set LED pin as output. All the I/O pins are inputs by default.
   //-----------------------------------------------------------------
 while(1){
  if(PUSHBUTTON_read()== PRESSED){
	  LED_Toggle();
	  _delay_ms(300);
  }
 
  }
  
}



