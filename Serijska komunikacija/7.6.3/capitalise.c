/*Napisati program koji čeka da korisnik unese string putem serijskog terminala, a zatim ga vraća u kapitalizovanom obliku (pretvara mala slova
u velika). Primer unosa je dat u nastavku.
ULAZ: OvajTekstJePotrebnoKapitalizovati
IZLAZ: OVAJTEKSTJEPOTREBNOKAPITALIZOVATI
*/



#include "capitalise.h"

void capitalise(int8_t *s)
{
	while (*s != 0) /*Sve dok pokazivac na poslednji karakter stringa nije jednak nuli*/
	{
		if (*s >= 97 && *s <= 122) /*Proveravamo da li memorijska lokacija pokazivaca na dati karakter stringa pokazuje na mali ili veliko slovo*/
			*s -= 32;
		s++;
	}
}
