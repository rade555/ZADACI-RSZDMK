#ifndef FJE_H_
#define FJE_H_

#include "usart.h"

void ucitajDragulje(int8_t *s);/*Deklarisanje pokazivaca na funkciju ucitaj dragulje*/

int8_t prebrojDragulje(int8_t *dra, int8_t *kam); /*Deklarisanje pokazivaca na dva stringa*/

void ispis(int8_t c); /*Deklarisanje funkcije koja prebrojava broj dragulja*/

#endif /* FJE_H_ */
