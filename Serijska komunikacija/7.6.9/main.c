/*U okviru biblioteke za serijsku komunikaciju usart implementirati funkciju koja putem serijskog porta šalje ceo broj. Prototip funkcije je dat u
nastavku. Kod je potrebno detaljno komentarisati.
95
Razvoj softvera za embeded sisteme
• void usartPrintInteger(int32_t value)
- Opis: Funkcija koja pretvara ceo broj value u niz karaktera i šalje ga
putem serijskog porta.
- Povratna vrednost: Nema.
*/



#include <stdlib.h>
#include <util/delay.h>
#include "usart.h"

int16_t main()
{
	usartInit(9600);
	int32_t n;
	int8_t ostatak[64];

	while (1)
	{
		usartPutString("Unesite neki ceo broj:\r");

		while (!usartAvailable())
		;
		_delay_ms(100);

		n = usartParseInt();
		usartGetString(ostatak);

		usartPutString("Unet je broj ");
		usartPrintInteger(n);
		usartPutString("\r");

		usartPutString("Praznjenje ostatka bafera... ");
		usartPutString(ostatak);
		usartPutString("\r\r");
	}
}
