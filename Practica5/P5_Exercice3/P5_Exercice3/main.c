/*
 * P5_Exercice3.c
 *
 * Created: 13/04/2026 11:24:00
 * Author : DCE
 */ 

#include <avr/io.h>
#include "USART.h"
#include "functionsADC.h"
#include "PORTS.h"
#include "PARAMETERS.h"
#include "MACROS.h"

void Show_Menu();
void optionsMenu(char);
int main(void)
{	
	USART0_init(9600);
	ADC_Init_Single(VREF_VCC, ALIGN_RIGHT, ADC_PRE_128);
	Show_Menu();
	unsigned char key;
    while (1) 
    {
		key=USART0_getchar();
		optionsMenu(key);
    }
}

void Show_Menu(){
	USART0_putString("--------------------------------------------\r\n");
	USART0_putString("This is the main menu. Select one choise: \r\n");
	USART0_putString("--------------------------------------------\r\n");
	USART0_putString("1.-Measurement of the LDR \r\n");
	USART0_putString("2.-Measurement of the potentiometer \r\n");
	USART0_putString("--------------------------------------------\r\n");
}

void optionsMenu(char key){
	uint16_t value;    // Declaramos la variable UNA sola vez aquí
	char buffer[10];   // Necesario para convertir el número a texto

	switch(key){
		case '1':
		USART0_putString("LDR value: ");
		value = get_ADC_Average(1, 8); // Canal 1 (LDR), 8 muestras
		
		utoa(value, buffer, 10);      // Convertimos el número a string
		USART0_putString(buffer);
		USART0_putString("\r\n");
		break;
		
		case '2':
		USART0_putString("Potentiometer value: ");
		value = get_ADC_Average(0, 8); // Canal 0 (POT), 8 muestras
		
		utoa(value, buffer, 10);
		USART0_putString(buffer);
		USART0_putString("\r\n");
		break;
		
		default:
		USART0_putString("Invalid choice. Please select again.\r\n");
		_delay_ms(500);
		break;
	}
	Show_Menu(); // Volvemos a mostrar el menú para que el usuario sepa que puede elegir otra vez
}

