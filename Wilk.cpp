#include "Wilk.h"
class Swiat;
Wilk::Wilk(Swiat* swiat, int x, int y)
{
	symbol = 'w';
	nazwa = "wilk";
	this->swiat = swiat;
	sila = 9;
	inicjatywa = 5;
	polozenie[PX] = x;
	polozenie[PY] = y;
	wczesniejsze_polozenie[PX] = polozenie[PX];
	wczesniejsze_polozenie[PY] = polozenie[PY];
	wiek = 0;
}
