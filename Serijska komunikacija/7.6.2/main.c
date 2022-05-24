/*Napisati program koji ispisuje broj samoglasnika u datoj reči,
koja je uneta putem serijskog terminala. Podrazumevati da se reč unosi isključivo
malim slovima. Primer unosa je dat u nastavku.
IZLAZ: Unesite rec:
ULAZ: australopithecus
IZLAZ: Rec ima 7 samoglasnika*/




#include <stdlib.h>
#include <util/delay.h>
#include "usart.h"

#include "ispis.h"

int16_t main()
{
	usartInit(9600);
	int8_t br = 0;
	int8_t tmp = 0;/*Duzina niza karaktera koji unosimo*/

	while (1)
	{
		usartPutString("Unesite rec:\r");

		while (!usartAvailable())
		;
		_delay_ms(100);

		while (usartAvailable())
		{
			tmp = usartGetChar();/*Funkcija cita karakter po karakter pokazujuci na svaki sledeci*/
                        /*Tmp Predstavlja memorijske lokacije stringova koji su samoglasnici i mi prolazimo kroz tu memoriju i povecavamo broj samoglasnika svaki put kada naidjemo na memorijsku lokaciju tog samoglasnika*/
			
                           if (tmp == 97 ||
			    tmp == 101 ||
				tmp == 105 ||
				tmp == 111 ||
				tmp == 117)
				br++;
		}

		usartPutString("Rec ima ");
		ispis(br);
		usartPutString(" samoglasnika.\r");

		br = 0;
	}
}
