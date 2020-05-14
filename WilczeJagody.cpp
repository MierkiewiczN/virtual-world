#include "WilczeJagody.h"

WilczeJagody::WilczeJagody(Swiat* swiat, int x, int y)
{
	this->swiat = swiat;
	polozenie[PX] = x;
	polozenie[PY] = y;
	prawdopodobienstwo = .1;
	nazwa = "Wilcze Jagody";
	symbol = char(158);
}

bool WilczeJagody::czyOdparlAtak(Organizm* organizm)
{
	cout << endl << organizm->getNazwa() << " zatrul sie Wilczymi Jagodami." << endl;
	return true;
}