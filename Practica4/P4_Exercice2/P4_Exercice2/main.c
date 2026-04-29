/*
 * P4_Exercice2.c
 *
 * Created: 23/03/2026 10:26:44
 * Author : DCE
 */ 

#include <avr/io.h>
#include <stdio.h>
#include "USART.h"


int main(void)
{
	 uint16_t baudrate= 9600;
	 unsigned char string;
      USART0_init(baudrate);      
      while (1)
      {
		  
		  string= USART0_getchar();
		  
		  USART0_putchar(string);
	      _delay_ms(2000);
      }
}

