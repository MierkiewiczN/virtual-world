#include "Guarana.h"

Guarana::Guarana(Swiat* swiat, int x, int y)
{
	this->swiat = swiat;
	polozenie[PX] = x;
	polozenie[PY] = y;
	prawdopodobienstwo = .1;
	nazwa = "Guarana";
	symbol = char(254);
}
