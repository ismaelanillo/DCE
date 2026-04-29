/*
 * PushButton.c
 *
 * Created: 02/03/2026 11:30:39
 *  Author: DCE
 */ 
#include "PushButton.h"

uint8_t PUSHBUTTON_read(){
	GPIO_Init(&GPIO0_MODE,BUTTON,INPUT);
	GPIO_pullup(&GPIO0_OUT,BUTTON,ON);
	return GPIO_read(&GPIO0_IN,BUTTON);
}