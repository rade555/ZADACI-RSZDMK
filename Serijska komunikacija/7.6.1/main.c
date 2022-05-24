Napisati program koji koriscenjem serijskog terminala trazi od korisnika da unese svoje ime,nakon cega ispisuje pozdravnu poruku.
Primer unosa je dat u nastavku.
IZLAZ:Unesite svoje ime i prezime:
ULAZ:Ime Prezime
IZLAZ:ZDRAVO,Ime Prezime.:)



#include <stdint.h>
#include <util/delay.h>
#include "usart.h"

int16_t main()
{
	int8_t imePrezime[64]; /*Definisanje stringa maksimalne duzine 64 karaktera*/
	usartInit(9600);/*Brzina serijske komunikacije*/

	while (1)
	{
		usartPutString("Unesite svoje ime i prezime:\r"); /*Bezuslovni ispis stringa*/

		while (!usartAvailable()) /*Sve dok je bafer prazan odlaze se vreme*/
		;
		_delay_ms(100);

		usartGetString(imePrezime); /*Ocitaj string koji se nalazi u serijskom baferu*/
		usartPutString("Zdravo, ");
		usartPutString(imePrezime);/*Ispisi ocitani string*/
		usartPutString(". :)\r");
	}
}
