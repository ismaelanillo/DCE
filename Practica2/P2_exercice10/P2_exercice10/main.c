/*
 * P2_exercice10.c
 *
 * Created: 09/03/2026 10:32:11
 * Author : DCE
 */ 


#include "PORTS.h"
#include "LED.h"
#include "PushButton.h"
#include <avr/io.h>






typedef enum {
	ST_INITIAL,			// A setup state
	ST_LED_ON,		// Action
	ST_LED_BLINK,
	ST_DELAY			// Assure the right behavior of the pushbutton
} FSM_States_t;

int main(void)
{
	FSM_States_t currentState	=	ST_INITIAL;
	FSM_States_t nextState		=	ST_INITIAL;
	uint8_t statePushbutton		=	!PRESSED;
	
	//===============  SETUP ==============================
	//-----------------------------------------------------
	
	//============  SUPER-LOOP =============================
	while (1)
	{
		//------------------------------------------------
		// 1.- Check the events (input)
		statePushbutton = PUSHBUTTON_read();
		//---------------------------------------------------
		// 2.- Set the TRANSITIONS based upon events:
		// * Pushbutton is pressed
		// * Delay time is expired
		//------------------------------------------------
		switch (currentState) {
			case ST_INITIAL:
			if (statePushbutton==PRESSED)
			{
				nextState = ST_LED_ON;
			}
			break;
			
			case ST_LED_ON:
			if (statePushbutton==PRESSED)
			{
				nextState = ST_LED_BLINK;
			}
			break;
			
		
			
			case ST_LED_BLINK:
				nextState=ST_INITIAL;
			break;
			
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
			LED_OFF();
			break;
			
			case ST_LED_ON:
			LED_ON();
			break;
			
			case ST_LED_BLINK:
			LED_Blink_three();
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


