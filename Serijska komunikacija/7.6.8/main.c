/*U okviru biblioteke za serijsku komunikaciju usart implementirati funkciju koja kao povratnu vrednost vraća naredni validan realan broj u
nadolazećem nizu karaktera. Prototip funkcije je dat u nastavku. Kod je potrebno
detaljno komentarisati.
• float_t usartParseFloat()
- Opis: Funkcija koja pretražuje niz karaktera prosleđen od strane korisnika
i kao povratnu vrednost vraća prvi validan, realan broj. Pri tome, uzeti u
obzir da se izvršavanje funkcije okončava u slučaju da nije moguće locirati
broj u datom nizu nakon isteka vremenskog intervala od 2s (eng. time-out).
- Povratna vrednost: Naredni validan broj ili vrednost 0, ukoliko on nije
pronađen.
U nastavku su dati primeri unosa, očekivane povratne vrednosti i sadržaj serijskog
bafera nakon poziva funkcije usartParseInt().
ULAZ: 1.23
Povratna vrednost: 1.23
Serijski bafer: prazan
ULAZ: -1.23
Povratna vrednost: -1.23
Serijski bafer: prazan
ULAZ: abc1.23
Povratna vrednost: 1.23
Serijski bafer: prazan
ULAZ: abc1.23def
Povratna vrednost: 1.23
Serijski bafer: def
ULAZ: abcdef
Povratna vrednost: 0.0
Serijski bafer: prazan*/



#include <stdlib.h>
#include <util/delay.h>
#include "usart.h"
#include "ispis.h"

int16_t main()
{
	usartInit(9600);
	float n = 25.04;
	int8_t ostatak[64];

	while (1)
	{
		usartPutString("Unesite neki realan broj:\r");

		while (!usartAvailable())
		;
		_delay_ms(100);

		usartGetString(ostatak);

		usartPutString("Unet je broj ");
		ispis(n);
		usartPutString("\r");

		usartPutString("Praznjenje ostatka bafera... ");
		usartPutString(ostatak);
		usartPutString("\r\r");
	}
}
