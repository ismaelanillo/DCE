/*
 * PORTS.h
 *
 * Created: 23/02/2026 11:37:21
 *  Author: DCE
 */ 


#ifndef PORTS_H_
#define PORTS_H_
#include <avr/io.h>

#define  F_CPU 16000000UL
#include <util/delay.h>

#define GPIO0_MODE DDRB
#define GPIO0_OUT PORTB
#define GPIO0_IN PINB

#define LED0 0 //Pin 8
#define LED1 3
#define LED2 4
#define LED3 5
#define BUTTON 2
#define PRESSED 0
#define BLINK_TIME 300

#define CHANNEL1 1

static inline void GPIO_init(){
	//1.-Set output pins
	GPIO0_MODE |=(1<<LED0); 
	//| (0<<BUTTON) | (1<<LED1) | (1<<LED2) | (1<<LED3);
	
	
	//2.-Enable the Rpull-up for the button
	//GPIO0_OUT |= (1<<BUTTON);
	
}


#endif /* PORTS_H_ */