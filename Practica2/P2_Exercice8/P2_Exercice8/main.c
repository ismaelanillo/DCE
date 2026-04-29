/*
 * P2_Exercice8.c
 *
 * Created: 02/03/2026 13:31:27
 * Author : DCE
 */ 

#include "PORTS.h"
#include "MACROS.h"

typedef enum{
	ST_INITIAL, //A setup state
	ST_TOGGLE_LED, //Action
	ST_DELAY //Assure the right behavior of the 
	}FSM_States_t;
int main(void)
{
	FSM_States_t currentState=ST_INITIAL;
	FSM_States_t nextState= ST_INITIAL;
	uint8_t statePushbutton= !PRESSED;
	 //======================== SETUP ========================
	GPIO_init();
	//========================================================
   
    while (1) 
    {
		//1.- Check the events (input)
		statePushbutton = READ_PIN(GPIO0_IN,BUTTON);
		
		//2.- Set the Transitions based upon events:
		// * Pushbutton is pressed
		// * Delay time is expired
		switch(currentState){
			case ST_INITIAL:
				if(statePushbutton==PRESSED)
					nextState= ST_TOGGLE_LED;
			break;
			case ST_TOGGLE_LED:
				nextState=ST_DELAY;
			break;
			case ST_DELAY:
				if(statePushbutton==PRESSED)
					nextState=ST_TOGGLE_LED;
			break;
			default:
				nextState=ST_INITIAL;
				break;
		}
		//3.- Set the outputs of the states
		switch(currentState){
			case ST_INITIAL:
				GPIO_init();
				CLEARBIT(GPIO0_OUT,LED);
			break;
			case ST_TOGGLE_LED:
				TOGGLEBIT(GPIO0_OUT,LED);
			break;
			case ST_DELAY:
				_delay_ms(300);
			break;
			default:break;
				
		}
		//4.-Update the current state
		currentState=nextState;
    }
}

