/*
 * P3_Exercice4.c
 *
 * Created: 16/03/2026 11:12:24
 * Author : DCE
 */ 

#include <avr/io.h>
#include "PORTS.h"
#include "MACROS.h"
#include "EXT_INT.h"

typedef enum{
	ST_allON,
	ST_oddON,
	ST_evenON,
	ST_AllOFF
	}FSM_States_t;
volatile FSM_States_t currentState=ST_allON;
volatile FSM_States_t nextState=ST_allON;
	
ISR(INT0_vect){
	nextState=ST_allON;
}
int main(void)
{
  
   GPIO_init();
   
   INT0_config(FALLING);
   INT0_enable();
   
   sei();
    while (1) 
    {
		switch(currentState){
			case ST_allON:
				nextState=ST_oddON;break;
			case ST_oddON:
				nextState=ST_evenON;break;
			case ST_evenON:
				nextState=ST_AllOFF;break;
			case ST_AllOFF:
				nextState= ST_allON;break;
			default: 
				nextState=ST_allON;
				break;
    }
	
	switch(currentState){
		case ST_allON:
			GPIO0_OUT |= 0xF0;
			
		break;
		case ST_oddON:
			GPIO0_OUT &= ~(0xF0);
			GPIO0_OUT |= 0xA0;
			
		break;
		case ST_evenON:
			GPIO0_OUT &= ~(0xF0);
			GPIO0_OUT |= 0x50;
			_delay_ms(1000);
		break;
		case ST_AllOFF:
			GPIO0_OUT &= ~(0xFF);
			
		break;
		default:break;
	}
	_delay_ms(1000);
	currentState=nextState;
	}
}

