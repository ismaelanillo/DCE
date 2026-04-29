/*
 * LED.c
 *
 * Created: 02/03/2026 11:11:38
 *  Author: DCE
 */ 
#include "LED.h"
void LED_ON(){
	GPIO_Init(&GPIO0_MODE,LED0,OUTPUT);
	GPIO_write(&GPIO0_OUT,LED0,HIGH);
}

void LED_OFF(){
	GPIO_Init(&GPIO0_MODE,LED0,OUTPUT);
	GPIO_write(&GPIO0_OUT,LED0,LOW);
}

void LED_Toggle(){
	GPIO_Init(&GPIO0_MODE,LED0,OUTPUT);
	GPIO_toggle(&GPIO0_OUT,LED0);
}

void LED_Blink_three(){
	GPIO_Init(&GPIO0_MODE,LED0,OUTPUT);
	for(uint8_t i=0;i<3;i++){
		GPIO_write(&GPIO0_OUT,LED0,HIGH);
		_delay_ms(500);
		GPIO_write(&GPIO0_OUT,LED0,LOW);
		_delay_ms(500);
	}
}