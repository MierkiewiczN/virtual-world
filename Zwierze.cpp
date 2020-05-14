#include "Zwierze.h"
#include "Wilk.h"
#include "Owca.h"
#include "Lis.h"
void Zwierze::akcja()
{
	bool moved = false;
	wczesniejsze_polozenie[PX] = polozenie[PX];
	wczesniejsze_polozenie[PY] = polozenie[PY];
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
	
	if (liczbaWolnychKierunkow) {
		cout << endl << nazwa;
		if (nazwa.back() == 'a') cout << " poruszyla sie";
		else cout << " poruszyl sie";
		cout << " z pola (" << polozenie[PX] << ", " << polozenie[PY] << ")";
		while (!moved) {
			switch (rand() % 4)
			{
			case GORA:
				if (polozenie[PY] > 0) {
					moved = true;
					polozenie[PY]--;
				}
				break;
			case DOL:
				if (polozenie[PY] < swiat->getWysokosc() - 1) {
					moved = true;
					polozenie[PY]++;
				}
				break;
			case LEWO:
				if (polozenie[PX] > 0) {
					moved = true;
					polozenie[PX]--;
				}
				break;
			case PRAWO:
				if (polozenie[PX] < swiat->getSzerokosc() - 1) {
					moved = true;
					polozenie[PX]++;
				}
				break;
			}
		}

		cout << " na pole (" << polozenie[PX] << ", " << polozenie[PY] << ")" << endl;
		swiat->przesunZwierze(this, wczesniejsze_polozenie[PX], wczesniejsze_polozenie[PY], polozenie[PX], polozenie[PY]);
	}
	else cout << endl << this->getNazwa() << " nie ma mozliwosci ruchu " << endl;
}
Organizm* Zwierze::kolizja()
{
	Organizm* nowy;
	
	if (dynamic_cast<Wilk*>(this)) {
		cout << endl << "Powstaje nowy Wilk" << endl;
		return new Wilk(swiat, this->getX(), this->getY());
	}
	else if (dynamic_cast<Owca*>(this)) {
		cout << endl << "Powstaje nowa Owca" << endl;
		return new Owca(swiat, this->getX(), this->getY());
	}
	else if (dynamic_cast<Lis*>(this)) {
		cout << endl << "Powstaje nowy Lis" << endl;
		return new Lis(swiat, this->getX(), this->getY());
	}

}



bool Zwierze::czyOdparlAtak(Organizm* organizm)
{
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

	if (odparlAtak) cout << endl << this->getNazwa() << " odparl atak, pokonuj¹c " << organizm->getNazwa() << endl;
	else cout << endl << organizm->getNazwa() << " pokonal " << this->getNazwa() << endl;
	return odparlAtak;
}

void Zwierze::przesunNaWolneMiejsce()
{
	int x = 0;
	int y = 0;
	if (swiat->czyWolneMiejsce(polozenie[PX] - 1, polozenie[PY])) {
		x = -1;
	}
	else if (swiat->czyWolneMiejsce(polozenie[PX] + 1, polozenie[PY])) {
		x = 1;
	}
	else if (swiat->czyWolneMiejsce(polozenie[PX], polozenie[PY] - 1)) {
		y = -1;
	}
	else if (swiat->czyWolneMiejsce(polozenie[PX], polozenie[PY] + 1)) {
		y = 1;
	}
	else if (swiat->czyWolneMiejsce(polozenie[PX] + 1, polozenie[PY] + 1)) {
		x++;
		y++;
	}
	else if (swiat->czyWolneMiejsce(polozenie[PX] - 1, polozenie[PY] + 1)) {
		x--;
		y++;
	}
	else if (swiat->czyWolneMiejsce(polozenie[PX] - 1, polozenie[PY] - 1)) {
		x--;
		y--;
	}
	else if (swiat->czyWolneMiejsce(polozenie[PX] + 1, polozenie[PY] - 1)) {
		x++;
		y--;
	}
	polozenie[PX] += x;
	polozenie[PY] += y;
	if (x != 0 || y != 0) {
		cout <<this->getNazwa() << " jest na polu (" << polozenie[PX] << ", " << polozenie[PY] << ")" << endl;
	}
	else cout << endl << "Brak wolnego miejsca." << endl;
}

string Zwierze::getNazwa()
{
	return nazwa;
}

void Zwierze::wrocNaOstatnieMiejsce()
{
	polozenie[PX] = wczesniejsze_polozenie[PX];
	polozenie[PY] = wczesniejsze_polozenie[PY];
}

void Zwierze::zwiekszSile()
{
	sila += 3;
	cout << nazwa << " zjadl Guarane i ma teraz " << sila << " sily." << endl;
}

