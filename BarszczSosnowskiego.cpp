#include "BarszczSosnowskiego.h"

BarszczSosnowskiego::BarszczSosnowskiego(Swiat* swiat, int x, int y)
{
	this->swiat = swiat;
	polozenie[PX] = x;
	polozenie[PY] = y;
	prawdopodobienstwo = .1;
	nazwa = "Barszcz Sosnowskiego";
	symbol = char(225);
	//if (swiat->czyWolneMiejsce(x, y + 1)) {
		swiat->usunOrganizm(x, y + 1);
	//}
	//if (swiat->czyWolneMiejsce(x + 1, y + 1)) {
		swiat->usunOrganizm(x + 1, y + 1);
	//}
	//if (swiat->czyWolneMiejsce(x - 1, y + 1)) {
		swiat->usunOrganizm(x - 1, y + 1);
	//}
	//if (swiat->czyWolneMiejsce(x + 1, y)) {
		swiat->usunOrganizm(x + 1, y);
	//}
	//if (swiat->czyWolneMiejsce(x + 1, y - 1)) {
		swiat->usunOrganizm(x + 1, y - 1);
	//}
	//if (swiat->czyWolneMiejsce(x, y - 1)) {
		swiat->usunOrganizm(x, y - 1);
	//}
	//if (swiat->czyWolneMiejsce(x, y + 1)) {
		swiat->usunOrganizm(x, y + 1);
	//}
	//if (swiat->czyWolneMiejsce(x - 1, y - 1)) {
		swiat->usunOrganizm(x - 1, y - 1);
	//}
	//if (swiat->czyWolneMiejsce(x, y)) {
		swiat->usunOrganizm(x, y);
	//}
}

bool BarszczSosnowskiego::czyOdparlAtak(Organizm* organizm)
{
	cout << endl << organizm->getNazwa() << " zatrul sie Barszczem Sosnowskiego." << endl;
	return true;
}
