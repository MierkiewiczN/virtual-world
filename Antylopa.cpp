#include "Antylopa.h"
Antylopa::Antylopa(Swiat* swiat, int x, int y)
{
	symbol = 'a';
	nazwa = "Antylopa";
	this->swiat = swiat;
	sila = 4;
	inicjatywa = 4;
	polozenie[PX] = x;
	polozenie[PY] = y;
	wczesniejsze_polozenie[PX] = polozenie[PX];
	wczesniejsze_polozenie[PY] = polozenie[PY];
	wiek = 0;
}


void Antylopa::akcja()
{
	
	wczesniejsze_polozenie[PX] = polozenie[PX];
	wczesniejsze_polozenie[PY] = polozenie[PY];
	int ile_pol = rand() % 2 + 1;
	int liczbaWolnychKierunkow = 0;
	if (swiat->czyWolneMiejsce(polozenie[PX], polozenie[PY] - 1) || (polozenie[PY] - 1 >= 0 && sila > swiat->getSilaOrganizmuNaPolu(polozenie[PX], polozenie[PY] - 1))) {
		liczbaWolnychKierunkow++;
	}
	if (swiat->czyWolneMiejsce(polozenie[PX], polozenie[PY] + 1) || (polozenie[PY] + 1 >= 0 && sila > swiat->getSilaOrganizmuNaPolu(polozenie[PX], polozenie[PY] + 1))) {
		liczbaWolnychKierunkow++;
	}
	if (swiat->czyWolneMiejsce(polozenie[PX] - 1, polozenie[PY]) || (polozenie[PX] - 1 >= 0 && sila > swiat->getSilaOrganizmuNaPolu(polozenie[PX] - 1, polozenie[PY]))) {
		liczbaWolnychKierunkow++;
	}
	if (swiat->czyWolneMiejsce(polozenie[PX] + 1, polozenie[PY]) || (polozenie[PX] + 1 >= 0 && sila > swiat->getSilaOrganizmuNaPolu(polozenie[PX] + 1, polozenie[PY]))) {
		liczbaWolnychKierunkow++;
	}

	bool moved = false;
	if (liczbaWolnychKierunkow) {
		while (!moved) {
			switch (rand() % 4)
			{
			case GORA:
				if (polozenie[PY] - ile_pol >= 0) {
					moved = true;
					polozenie[PY] -= ile_pol;
				}
				break;
			case DOL:
				if (polozenie[PY] + ile_pol <= swiat->getWysokosc() - 1) {
					moved = true;
					polozenie[PY] += ile_pol;
				}
				break;
			case LEWO:
				if (polozenie[PX] - ile_pol >= 0) {
					moved = true;
					polozenie[PX] -= ile_pol;
				}
				break;
			case PRAWO:
				if (polozenie[PX] + ile_pol <= swiat->getSzerokosc() - 1) {
					moved = true;
					polozenie[PX] += ile_pol;
				}
				break;
			}
		}
		cout << endl << nazwa << " przeskoczyla z " << "(" << wczesniejsze_polozenie[PX] << ", " << wczesniejsze_polozenie[PY] << ")";
		cout << " na (" << polozenie[PX] << ", " << polozenie[PY] << ")" << endl;
		swiat->przesunZwierze(this, wczesniejsze_polozenie[PX], wczesniejsze_polozenie[PY], polozenie[PX], polozenie[PY]);
	}
	else cout << endl << nazwa << " nie ma mozliwosci ruchu"<<endl;
}


Organizm* Antylopa::kolizja()
{
	// TODO: 50% szans na ucieczkê
	if (uciekla) {
		cout << endl << endl << nazwa << " przeskoczyla z " << "(" << polozenie[PX] << ", " << polozenie[PY] << ")";
		wczesniejsze_polozenie[PX] = polozenie[PX];
		wczesniejsze_polozenie[PY] = polozenie[PY];
		bool moved = false;
		int ile_pol = 1;
		while (!moved) {
			switch (rand() % 4)
			{
			case GORA:
				if (polozenie[PY] - ile_pol >= 0 && swiat->czyWolneMiejsce(polozenie[PX], polozenie[PY] - 1)) {
					moved = true;
					polozenie[PY] -= ile_pol;
				}
				break;
			case DOL:
				if (polozenie[PY] + ile_pol <= swiat->getWysokosc() - 1 && swiat->czyWolneMiejsce(polozenie[PX], polozenie[PY] + 1)) {
					moved = true;
					polozenie[PY] += ile_pol;
				}
				break;
			case LEWO:
				if (polozenie[PX] - ile_pol >= 0 && swiat->czyWolneMiejsce(polozenie[PX] - 1, polozenie[PY])) {
					moved = true;
					polozenie[PX] -= ile_pol;
				}
				break;
			case PRAWO:
				if (polozenie[PX] + ile_pol <= swiat->getSzerokosc() - 1 && swiat->czyWolneMiejsce(polozenie[PX] + 1, polozenie[PY])) {
					moved = true;
					polozenie[PX] += ile_pol;
				}
				break;
			}
		}

		cout << " na (" << polozenie[PX] << ", " << polozenie[PY] << "),";
		swiat->przesunZwierze(this, wczesniejsze_polozenie[PX], wczesniejsze_polozenie[PY], polozenie[PX], polozenie[PY]);
	}
	else { // rozmnazanie
		cout << endl << "Powstaje nowa Antylopa" << endl;
		return new Antylopa(swiat, this->getX(), this->getY());
	}
	return this;
}

bool Antylopa::czyOdparlAtak(Organizm* organizm)
{
	uciekla = rand() % 2;
	if (uciekla) {
		this->kolizja();
		cout << " uciekajac od " << organizm->getNazwa() << endl;
		return true;
	}
	bool odparlAtak = false;
	if (this->sila > organizm->getSila())
		odparlAtak = true;

	if (this->sila < organizm->getSila())
		odparlAtak = false;

	if (this->sila == organizm->getSila())
	{
		if (this->wiek > organizm->getWiek())
			odparlAtak = true;

		if (this->wiek < organizm->getWiek())
			odparlAtak = false;
	}

	if (odparlAtak) cout << endl << this->getNazwa() << " odparla atak, pokonuj¹c " << organizm->getNazwa() << endl;
	else cout << endl << organizm->getNazwa() << " pokona³ " << this->getNazwa() << endl;
	return odparlAtak;

}

bool Antylopa::czyUciekla()
{
	return uciekla;
}

void Antylopa::resetujUciekla()
{
	uciekla = false;
}
