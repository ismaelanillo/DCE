/*
 * main_c.c
 *
 * Created: 16/02/2026 12:57:27
 *  Author: DCE
 */ 

#include <avr/io.h>
#include <stdint.h>
#define  F_CPU 16000000UL
#include <util/delay.h>
#define MASK 0x3C



int main(void)
{
	DDRD|= (1<<DDD4) | (1<<DDD5) | (1<<DDD2) | (1<<DDD3) | (1<<DDD7);
	/* Replace with your application code */
	while (1)
	{
		
		for(uint8_t i=0; i<=15;i++){
			uint8_t Red_led= (1<<PORTD7);
			PORTD=(PORTD & ~MASK) | ((i<<2)& MASK) | Red_led ;
			_delay_ms(500);
			
		}
	}
}