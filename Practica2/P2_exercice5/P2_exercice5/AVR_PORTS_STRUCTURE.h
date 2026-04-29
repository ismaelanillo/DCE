/*
 * AVR_PORTS_STRUCTURE.h
 *
 * Created: 23/02/2026 12:49:34
 *  Author: DCE
 */ 


#ifndef AVR_PORTS_STRUCTURE_H_
#define AVR_PORTS_STRUCTURE_H_

#define F_CPU 16000000UL
#include <stdint.h>

typedef struct  
{
	volatile uint8_t IN;
	volatile uint8_t MODE;
	volatile uint8_t OUT;
}GPIO_Typedef;

#define GPIOB_BASE 0x23
#define GPIOB ((GPIO_Typedef *) GPIOB_BASE)

#define GPIOC_BASE 0x26
#define GPIOC ((GPIO_Typedef *) GPIOC_BASE)

#define GPIOD_BASE 0x29
#define GPIOD ((GPIO_Typedef *) GPIOD_BASE)

#define BUTTON 2
#define LED0 3




#endif /* AVR_PORTS_STRUCTURE_H_ */