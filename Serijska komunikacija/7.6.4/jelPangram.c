/*Napisati program koji proverava da li je niz karaktera unet putem
serijskog terminala – pangram. Pangram je reč koja sadrži sva slova abecede (bez
ponavljanja). Za potrebe ovog zadatka, potrebno je koristiti englesku abecedu.
Rezultat provere ispisati putem serijskog terminala. Primer unosa je dat u nastavku.
ULAZ: The quick brown fox jumps over a lazy dog.
IZLAZ: Uneti string jeste pangram.
ULAZ: abcd
IZLAZ: Uneti string nije pangram.
ULAZ: Watch "Jeopardy!", Alex Trebek’s fun TV quiz game.
IZLAZ: Uneti string jeste pangram.*/

#include "usart.h"
#include "jelPangram.h"

bool jelPangram(int8_t *s)
{
	int8_t tmp[26];
	int8_t p = 1;

	for (int8_t i = 0; i != 26; i++)
		tmp[i] = 0;

	while (*s != 0)
	{
		for (int8_t i = 0; i != 26; i++)
		{
			if (*s == 97 + i || *s == 65 + i)
				tmp[i] = 1;
		}

		s++;
	}

	for (int8_t i = 0; i != 26; i++)
		p &= tmp[i];

	if (p)
		return true;
	else
		return false;
}

