/*
 * P2_exercice2.c
 *
 * Created: 16/02/2026 12:01:58
 * Author : DCE
 */ 

#include <avr/io.h>
#include <stdint.h>
#define  F_CPU 16000000UL
#include <util/delay.h>



int main(void)
{
	DDRD|= (1<<DDD0) | (1<<DDD1) | (1<<DDD2) | (1<<DDD3);
    /* Replace with your application code */
    while (1) 
    {
		
		for(uint8_t i=0; i<16;i++){
			PORTD +=1;
			_delay_ms(1000);
			
		}
		
		
    }
}

