/*
 * GPIO.c
 *
 * Created: 02/03/2026 9:58:29
 *  Author: DCE
 */ 
#include "GPIO.h"

void GPIO_Init(volatile uint8_t * port, uint8_t pin, GPIO_direction_t direction){
	if(direction == INPUT) *port &= ~(1<<pin);
	else if(direction == OUTPUT) *port |= (1<<pin);
}

void GPIO_pullup(volatile uint8_t * port, uint8_t pin,PullState pulls){
	 if(pulls == ON)
		*port |= (1<<pin);
	 else 
		*port &= ~(1<<pin);
		
}
uint8_t GPIO_read(volatile uint8_t * port, uint8_t pin){
	 return (*port & (1 << pin));
	 
}
void GPIO_write(volatile uint8_t * port, uint8_t pin, State state){
	if(state == HIGH)
		*port |=(1<<pin);
	else *port &= ~(1<<pin);
}

void GPIO_toggle(volatile uint8_t * port, uint8_t pin){
	*port ^=(1<<pin);
	
}