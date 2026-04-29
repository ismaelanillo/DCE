/*
 * P2_exercice9.c
 *
 * Created: 09/03/2026 9:53:51
 * Author : DCE
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

#include "PORTS.h"
#include "MACROS.h"

typedef enum {
	ST_INITIAL,			// A setup state
	ST_GREEN_LED,	
	ST_RED_LED,
	ST_ALL_LED,	
	ST_OFF_LED			
} FSM_States_t;

int main(void)
{
	FSM_States_t currentState	=	ST_INITIAL;
	FSM_States_t nextState		=	ST_INITIAL;
	uint8_t statePushbutton		=	!PRESSED;
	
	//===============  SETUP ==============================
	GPIO_init();
	//-----------------------------------------------------
	
	//============  SUPER-LOOP =============================
	while (1)
	{
		//------------------------------------------------
		// 1.- Check the events (input)
		statePushbutton = READ_PIN(GPIO0_IN,BUTTON);
		//---------------------------------------------------
		// 2.- Set the TRANSITIONS based upon events:
		//------------------------------------------------
		switch (currentState) {
			case ST_INITIAL:
			if (statePushbutton==PRESSED)
			{
				nextState = ST_GREEN_LED;
			}
			break;
			
			case ST_GREEN_LED:
			if(statePushbutton==PRESSED)
				nextState = ST_RED_LED;
			break;
			
			case ST_RED_LED:
			if (statePushbutton==PRESSED)
			{
				nextState = ST_ALL_LED;
			}
			break;
			case ST_ALL_LED:
			if (statePushbutton==PRESSED)
			{
				nextState = ST_OFF_LED;
			} break;
			case ST_OFF_LED:
				nextState=ST_INITIAL; break;
			
			default:
			// Whatever unknown state/value take the system to the initial state.
			nextState = ST_INITIAL;
			break;
		}
		
		//-----------------------------------------------
		// 3.- Set the outputs of the states
		//------------------------------------------------
		switch (currentState) {
			case ST_INITIAL:
			GPIO_init();	// Redundant for safety
			// System starts in a low-power state.
			CLEARBIT(GPIO0_OUT,GLED);
			CLEARBIT(GPIO0_OUT,RLED);
			break;
			
			case ST_GREEN_LED:
			SETBIT(GPIO0_OUT,GLED);
			break;
			
			case ST_RED_LED:
			CLEARBIT(GPIO0_OUT,GLED);
			SETBIT(GPIO0_OUT,RLED);
			break;
			
			case ST_ALL_LED:
			SETBIT(GPIO0_OUT,GLED);
			SETBIT(GPIO0_OUT,RLED);
			break;
			case ST_OFF_LED:
			CLEARBIT(GPIO0_OUT,GLED);
			CLEARBIT(GPIO0_OUT,RLED);
			break;
			
			
			
			default:
			break;
		}
		
		//-----------------------------------------------
		// 4.- Update the current state
		//-----------------------------------------------
		currentState = nextState;
		//-----------------------------------------------

		_delay_ms(300);
	}
}


