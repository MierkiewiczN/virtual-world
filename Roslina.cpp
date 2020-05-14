#include "Roslina.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "Math.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"
void Roslina::akcja()
{
	int x = ceil(1 / prawdopodobienstwo);
	bool nieZasiejeRosliny = rand() %x;
	if (!nieZasiejeRosliny) {
		stworzNowaRosline();
	}

}

Organizm* Roslina::kolizja()
{
	return this;
}

void Roslina::stworzNowaRosline()
{
	Roslina* nowa = nullptr;
	if (dynamic_cast<Trawa*>(this))
		nowa = new Trawa(swiat, this->getX(), this->getY());
	if (dynamic_cast<Mlecz*>(this))
		nowa = new Mlecz(swiat, this->getX(), this->getY());
	if (dynamic_cast<Guarana*>(this))
		nowa = new Guarana(swiat, this->getX(), this->getY());
	if (dynamic_cast<WilczeJagody*>(this))
		nowa = new WilczeJagody(swiat, this->getX(), this->getY());
	if (dynamic_cast<BarszczSosnowskiego*>(this))
		nowa = new BarszczSosnowskiego(swiat, this->getX(), this->getY());
	nowa->przesunNaWolneMiejsce();
	swiat->dodajOgranizm(nowa);
}

void Roslina::przesunNaWolneMiejsce()
{
	int liczbaWolnychKierunkow = 0;
	if (swiat->czyWolneMiejsce(polozenie[PX], polozenie[PY] - 1)) {
		liczbaWolnychKierunkow++;
	}
	if (swiat->czyWolneMiejsce(polozenie[PX], polozenie[PY] + 1)) {
		liczbaWolnychKierunkow++;
	}
	if (swiat->czyWolneMiejsce(polozenie[PX] - 1, polozenie[PY])) {
		liczbaWolnychKierunkow++;
	}
	if (swiat->czyWolneMiejsce(polozenie[PX] + 1, polozenie[PY])) {
		liczbaWolnychKierunkow++;
	}
	int x = 0;
	int y = 0;
	bool moved = false;
	if (liczbaWolnychKierunkow) {
		while (!moved) {
			switch (rand() % 4)
			{
			case GORA:
				if (swiat->czyWolneMiejsce(polozenie[PX], polozenie[PY] - 1)) {
					moved = true;
					y--;
				}
				break;
			case DOL:
				if (swiat->czyWolneMiejsce(polozenie[PX], polozenie[PY] + 1)) {
					moved = true;
					y++;
				}
				break;
			case LEWO:
				if (swiat->czyWolneMiejsce(polozenie[PX] - 1, polozenie[PY])) {
					moved = true;
					x--;
				}
				break;
			case PRAWO:
				if (swiat->czyWolneMiejsce(polozenie[PX] + 1, polozenie[PY])) {
					moved = true;
					x++;
				}
				break;
			}
		}

		polozenie[PX] += x;
		polozenie[PY] += y;
		cout << endl << "Nowa roslina (" << this->getNazwa() << ") jest na polu (" << polozenie[PX] << ", " << polozenie[PY] << ")" << endl;
	}
}


string Roslina::getNazwa()
{
	return nazwa;
}

bool Roslina::czyOdparlAtak(Organizm* organizm)
{
	return false;
}


