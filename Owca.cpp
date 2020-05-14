#include "Owca.h"
Owca::Owca(Swiat* swiat, int x, int y)
{
	symbol = 'o';
	nazwa = "Owca";
	this->swiat = swiat;
	sila = 4;
	inicjatywa = 4;
	polozenie[PX] = x;
	polozenie[PY] = y;
	wczesniejsze_polozenie[PX] = polozenie[PX];
	wczesniejsze_polozenie[PY] = polozenie[PY];
	wiek = 0;
}

