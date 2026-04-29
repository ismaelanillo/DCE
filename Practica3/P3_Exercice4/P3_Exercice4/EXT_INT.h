/*
 * EXT_INT.h
 *
 * Created: 16/03/2026 10:35:33
 *  Author: DCE
 */ 


#ifndef EXT_INT_H_
#define EXT_INT_H_
#include<avr/interrupt.h>

#define LOW_LEVEL 0
#define CHANGE 1
#define FALLING 2
#define RISING 3


static inline void INT0_config (uint8_t typeTrigger)
{
	
	// 1. Disable INT0 interrupts (safety to avoid spurious interrupt during
	//the change of the bits, in the case INT0 and SREG was already enabled)
	EIMSK &= ~(1 << INT0);
	// 2. Setup the falling edge as interrupt trigger (mask & set)
	// Clear the bits related to INTO setup (of a previous setup) --MASK
	EICRA &= ~((1 << ISC01) | (1 << ISC00));
	// Setup the falling edge (INT0 trigger) --SET
	EICRA |= typeTrigger;
}

static inline void INT0_enable(){
	//Clean flag
	EIFR |= (1<< INTF0);
	//Activate bit
	EIMSK |= (1<<INT0);
}

static inline void INT0_disable(){
	EIMSK &= ~(1<<INT0);
}

static inline void INT1_config (uint8_t typeTrigger)
{
	
	// 1. Disable INT1 interrupts (safety to avoid spurious interrupt during
	//the change of the bits, in the case INT0 and SREG was already enabled)
	EIMSK &= ~(1 << INT1);
	// 2. Setup the falling edge as interrupt trigger (mask & set)
	// Clear the bits related to INT1 setup (of a previous setup) --MASK
	EICRA &= ~((1 << ISC11) | (1 << ISC10));
	// Setup the falling edge (INT1 trigger) --SET
	EICRA |= typeTrigger;
}

static inline void INT1_enable(){
	//Clean flag
	EIFR |= (1<< INTF1);
	//Activate bit
	EIMSK |= (1<<INT1);
}

static inline void INT1_disable(){
	EIMSK &= ~(1<<INT1);
}


#endif /* EXT_INT_H_ */