/*Napisati program koji čeka da korisnik unese decimalni broj
preko serijskog porta, nakon čega vraća vrednost unetog broja u heksadecimalnom
formatu, sa prefiksom 0x. Primer unosa je dat u nastavku.
IZLAZ: Unesite decimalan broj:
ULAZ: 1000
IZLAZ: Uneli ste vrednost 0x3E8*/




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
		usartPutString("Unesite brojni izraz:\r");

		while (!usartAvailable())
		;
		_delay_ms(100);

		n = usartOperation();

		usartPutString("Vrednost izraza je ");
		usartPrintInteger(n);
		usartPutString("\r");

	}
}
