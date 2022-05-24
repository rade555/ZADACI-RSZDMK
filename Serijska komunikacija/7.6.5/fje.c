/*Napisati program koji rešava problem "Dragulja i kamenja" (eng.
Jewels and stones). Na početku, od korisnika se zahteva unos dva niza karaktera
koji predstavljaju "dragulje" i "kamenje", u narednom formatu:
<dragulji>:<kamenje>
Svaki od nizova može sadržati proizvoljan broj velikih, odnosno malih slova engleske abecede, pri čemu se u nizu dragulja ova slova ne smeju ponavaljati.
Cilj zadatka je prebrojati "dragulje" među "kamenjem", odnosno, prebrojati koliko
slova iz niza "dragulja" se nalazi u nizu "kamenja". Primer unosa je dat u nastavku.*/



#include "fje.h"

void ucitajDragulje(int8_t *s)
{
	int8_t len = 0; /*Duzina stringa dragulj*/
	do
	{
		s[len++] = usartGetChar();/*Citamo string koji smo uneli citajuci karakter po karakter*/
	} while (s[len - 1] != 58);

	s[len - 1] = 0;
}

int8_t prebrojDragulje(int8_t *dra, int8_t *kam)
{
	int8_t dlen = strlen(dra);
	int8_t klen = strlen(kam);
	int8_t br = 0;

	for (int8_t i = 0; i != dlen; i++)
	{
		for (int8_t j = 0; j != klen; j++)
			{
				if (kam[j] == dra[i])
					br++;
			}
	}

	return br;
}

void ispis(int8_t c)
{
	int8_t str[64];
	int8_t tmp = 0;
	sprintf(str, "%d", c);
	while(str[tmp] != 0)
	{
		usartPutChar(str[tmp]);
		tmp++;
	}
}
