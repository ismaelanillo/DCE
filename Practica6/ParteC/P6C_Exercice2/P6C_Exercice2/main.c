/*
 * P6C_Exercice2.c
 *
 * Created: 27/04/2026 13:22:14
 * Author : DCE
 */ 

#include <avr/io.h>
#include "TMR0.h"
#include "PORTS.h"
#include "MACROS.h"

int main(void)
{
	TMR0_PWM_Phase_Init();
	TMR0_PWM_Phase_Start(DIV_CLK_64);
	
	// Usamos int16_t para la variable 'duty' para evitar problemas al comparar
	// con valores negativos o límites estrictos de 8 bits (0-255).
	int16_t duty = 51;
	int8_t paso = 5;

	while (1)
	{
		TMR0_PWM_Phase_Duty((uint8_t)duty, 0);
		
		// Actualizamos el valor
		duty += paso;
		
		// Lógica de rebote: 230 (90%) y 51 (20%)
		if (duty >= 230) {
			duty = 230; // Aseguramos que no pase del límite
			paso = -5;  // Invertimos la dirección (decremento)
			} else if (duty <= 51) {
			duty = 51;  // Aseguramos que no baje del límite
			paso = 5;   // Invertimos la dirección (incremento)
		}
		
		_delay_ms(30);
	}
}
