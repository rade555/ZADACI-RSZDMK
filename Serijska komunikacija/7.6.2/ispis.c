#include <stdio.h>
#include <avr/io.h>
#include "usart.h"


#include "ispis.h"/*Moramo ukjluciti heder fajl ne sme se to zaboraviti*/

void ispis(int8_t c) /*Konkretno definisanje funkcije za ispis samoglasnika*/
{
	int8_t str[64];
	int8_t tmp = 0;
	sprintf(str, "%d", c);
	while(str[tmp] != 0)				// Petlja se izvrsava do nailaska na nul-terminator
	{
		usartPutChar(str[tmp]);		// Slanje tekuceg karaktera
		tmp++;					// Azuriranje pokazivaca na tekuci karakter
	}
}


