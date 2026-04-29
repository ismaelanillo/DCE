/*
 * P6C_Exercice1.c
 *
 * Created: 27/04/2026 12:32:30
 * Author : DCE
 */ 

#include <avr/io.h>
#include "TMR0.h"
#include "PORTS.h"
#include "MACROS.h"


int main(void)
{
   TMR0_PWM_Phase_Init();
   // 179= 70% de 255 y 89= 35% de 89
   TMR0_PWM_Phase_Duty(179,89);
   TMR0_PWM_Phase_Start(DIV_CLK_64);
    while (1) 
    {
    }
}

