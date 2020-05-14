#include "Mlecz.h"

Mlecz::Mlecz(Swiat* swiat, int x, int y)
{
	this->swiat = swiat;
	polozenie[PX] = x;
	polozenie[PY] = y;
	prawdopodobienstwo = .1;
	nazwa = "Mlecz";
	symbol = char(207);
}

void Mlecz::akcja()
{
	int x = ceil(1 / prawdopodobienstwo);
	for (int i = 0; i < 3; i++) {
		bool nieZasiejeRosliny = rand() % x;
		if (!nieZasiejeRosliny) {
			stworzNowaRosline();
		}
	}
}
