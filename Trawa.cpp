#include "Trawa.h"

Trawa::Trawa(Swiat* swiat, int x, int y)
{
	this->swiat = swiat;
	polozenie[PX] = x;
	polozenie[PY] = y;
	prawdopodobienstwo = .1;
	nazwa = "Trawa";
	symbol = char(176);
}
