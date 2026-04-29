/*
 * AVR_PORTS.h
 *
 * Created: 23/02/2026 12:29:02
 *  Author: DCE
 */ 


#ifndef AVR_PORTS_H_
#define AVR_PORTS_H_


#define GPIO0_MODE (*((volatile uint8_t*)0x2A))
#define GPIO0_OUT (*((volatile uint8_t*)0x2B))
#define GPIO0_IN (*((volatile uint8_t*)0x29))

#define BUTTON 2
#define LED0 3

#endif /* AVR_PORTS_H_ */