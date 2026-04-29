/*
 * P4_Exercice3.c
 *
 * Created: 23/03/2026 10:52:04
 * Author : DCE
 */ 

#include <avr/io.h>
#include "USART.h"

void mainMenu();
void optionsMenu(char key);
int main(void)
{
    USART0_init(BAUD);
	mainMenu();
	unsigned char key;
	uint8_t aux;
    while (1) 
    {
		aux=USART0_getchar_NoBlocking();
		if(aux != -1){
			key=(unsigned char)aux;
			_delay_ms(1000);
			optionsMenu(key);
		}	
		
		USART0_putString("Second Process \r\n");
    }
	_delay_ms(1000);
}

void mainMenu(){
	USART0_putString("--------------------------------------------\r\n");
	USART0_putString("This is the main menu. Select one choise: \r\n");
	USART0_putString("--------------------------------------------\r\n");
	USART0_putString("a.- Choise a \r\n");
	USART0_putString("b.- Choise b \r\n");
	USART0_putString("\nh.- Show the menu again \r\n");
	USART0_putString("--------------------------------------------\r\n");
}

void optionsMenu(char key){
	switch(key){
		case 'a':
		USART0_putString("You pressed a \r\n");
		break;
		case 'b':
		USART0_putString("You pressed b \r\n");
		break;
		case 'h':
		mainMenu();break;
		default: USART0_putString("Invalid choise. Please select other choise \r\n");_delay_ms(500);break;
	}
}

