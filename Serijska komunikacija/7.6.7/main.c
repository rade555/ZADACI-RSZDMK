/*U okviru biblioteke za serijsku komunikaciju usart implementirati funkciju koja kao povratnu vrednost vraća naredni validan broj u nadolazećem
nizu karaktera. Prototip funkcije je dat u nastavku. Kod je potrebno detaljno komentarisati.
• int16_t usartParseInt()
- Opis: Funkcija koja pretražuje niz karaktera prosleđen od strane korisnika
i kao povratnu vrednost vraća prvi validan, ceo broj. Pri tome, uzeti u obzir
da se izvršavanje funkcije okončava u slučaju da nije moguće locirati broj u
datom nizu nakon isteka vremenskog intervala od 2s (eng. time-out).
- Povratna vrednost: Naredni validan broj ili vrednost 0, ukoliko on nije
pronađen.
U nastavku su dati primeri unosa, očekivane povratne vrednosti i sadržaj serijskog
bafera nakon poziva funkcije usartParseInt().

ULAZ: 123
Povratna vrednost: 123
Serijski bafer: prazan
ULAZ: -123
Povratna vrednost: -123
Serijski bafer: prazan
ULAZ: abc123

Povratna vrednost: 123
Serijski bafer: prazan
ULAZ: abc123def
Povratna vrednost: 123
Serijski bafer: def
ULAZ: abcdef
Povratna vrednost: 0
Serijski bafer: prazan*/



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
		ispis(n);
		usartPutString("\r");

		usartPutString("Praznjenje ostatka bafera... ");
		usartPutString(ostatak);
		usartPutString("\r\r");
	}
}
