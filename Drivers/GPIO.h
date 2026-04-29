/*
 * IncFile1.h
 *
 * Created: 02/03/2026 9:55:30
 *  Author: DCE
 */ 


#ifndef GPIO_H_
#define GPIO_H_
#include <stdint.h>
#include <avr/io.h>
#include "PORTS.h"
typedef enum{INPUT,OUTPUT} GPIO_direction_t;
typedef enum{HIGH,LOW} State;
typedef enum{ON,OFF}PullState;

void GPIO_Init(volatile uint8_t * port, uint8_t pin, GPIO_direction_t direction);
void GPIO_pullup(volatile uint8_t * port, uint8_t pin, PullState pulls);
uint8_t GPIO_read(volatile uint8_t * port, uint8_t pin);
void GPIO_write(volatile uint8_t * port, uint8_t pin,State state);
void GPIO_toggle(volatile uint8_t * port, uint8_t pin);



#endif /* GPIO_H_ */