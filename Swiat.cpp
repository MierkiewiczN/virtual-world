#include "Swiat.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Czlowiek.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"
Swiat::Swiat(int szerokosc, int wysokosc)
{
	this->szerokosc = szerokosc;
	this->wysokosc = wysokosc;
	plansza.resize(szerokosc);
	organizmy_tabela_id.resize(szerokosc);
	for (int i = 0; i < szerokosc; i++) {
		plansza[i].resize(wysokosc);
		organizmy_tabela_id[i].resize(wysokosc);
	}
	for (int i = 0; i < szerokosc; i++) {
		for (int j = 0; j < wysokosc; j++) {
			plansza[i][j] = ' ';
			organizmy_tabela_id[i][j] = 0;
		}
	}
	srand(time(NULL));
}

void Swiat::rysujSwiat()
{
	cout << char(201);
	for (int i = 0; i < 2 * szerokosc + 3; i++) {
		cout << char(205);
	}
	cout << char(187) << endl;
	for (int i = 0; i < wysokosc; i++) {
		cout << char(186) << ' ' << char(250);
		for (int j = 0; j < szerokosc; j++) {
			cout << plansza[j][i] << char(250);
		}
		cout << ' ' << char(186) << endl;
	}
	cout << char(186) << ' ' << char(250);
	for (int j = 0; j < szerokosc; j++) {
		cout << ' ' << char(250);
	}
	cout << ' ' << char(186) << endl;
	cout << char(200);
	for (int i = 0; i < 2 * szerokosc + 3; i++) {
		cout << char(205);
	}
	cout << char(188) << endl;
	cout << "Natalia Mierkiewicz 179940" << endl;
	//--------------------------------------------------- nizej s¹ id
	cout << char(201);
	for (int i = 0; i < 2 * szerokosc + 3; i++) {
		cout << char(205);
	}
	cout << char(187) << endl;
	for (int i = 0; i < wysokosc; i++) {
		cout << char(186) << ' ' << char(250);
		for (int j = 0; j < szerokosc; j++) {
			cout << organizmy_tabela_id[j][i] << char(250);
		}
		cout << ' ' << char(186) << endl;
	}
	cout << char(186) << ' ' << char(250);
	for (int j = 0; j < szerokosc; j++) {
		cout << ' ' << char(250);
	}
	cout << ' ' << char(186) << endl;
	cout << char(200);
	for (int i = 0; i < 2 * szerokosc + 3; i++) {
		cout << char(205);
	}
	cout << char(188) << endl;
}


void Swiat::dodajOgranizm(Organizm* organizm)
{
	organizm->setId(++lastId);
	int x = organizm->getX();
	int y = organizm->getY();
	if (dynamic_cast<BarszczSosnowskiego*>(organizm)) {

		if (y + 1 < wysokosc) {
			organizmy_tabela_id[x][y + 1] = organizm->getId();
		}
		if (x + 1 < szerokosc && y + 1 < wysokosc) {
			organizmy_tabela_id[x + 1][y + 1] = organizm->getId();
		}
		if (x > 0 && y + 1 < wysokosc) {
			organizmy_tabela_id[x - 1][y + 1] = organizm->getId();
		}
		if (x + 1 < szerokosc) {
			organizmy_tabela_id[x + 1][y] = organizm->getId();
		}
		if (x + 1 < szerokosc && y > 0) {
			organizmy_tabela_id[x + 1][y - 1] = organizm->getId();
		}
		if (y > 0) {
			organizmy_tabela_id[x][y - 1] = organizm->getId();
		}
		if (y + 1 < wysokosc) {
			organizmy_tabela_id[x][y + 1] = organizm->getId();
		}
		if (x > 0 && y > 0) {
			organizmy_tabela_id[x - 1][y - 1] = organizm->getId();
		}
	}


	organizmy_tabela_id[x][y] = organizm->getId();
	plansza[x][y] = organizm->rysowanie();
	if (organizmy_kolejka.size() > 0) {
		vector<Organizm*>::iterator it;
		for (it = organizmy_kolejka.begin(); it != organizmy_kolejka.end(); ++it) {
			if ((*it)->getInicjatywa() < organizm->getInicjatywa()) break;
		}
		it = organizmy_kolejka.insert(it, organizm);
	}
	else organizmy_kolejka.push_back(organizm);
	liczbaOrganizmow++;
}

void Swiat::utworzOrganizm(Organizm* organizm)
{
	organizm->setId(liczbaOrganizmow + 1);
	int x = organizm->getX();
	int y = organizm->getY();
	if (dynamic_cast<BarszczSosnowskiego*>(organizm)) {

		if (y + 1 < wysokosc) {
			organizmy_tabela_id[x][y + 1] = organizm->getId();
		}
		if (x + 1 < szerokosc && y + 1 < wysokosc) {
			organizmy_tabela_id[x + 1][y + 1] = organizm->getId();
		}
		if (x > 0 && y + 1 < wysokosc) {
			organizmy_tabela_id[x - 1][y + 1] = organizm->getId();
		}
		if (x + 1 < szerokosc) {
			organizmy_tabela_id[x + 1][y] = organizm->getId();
		}
		if (x + 1 < szerokosc && y > 0) {
			organizmy_tabela_id[x + 1][y - 1] = organizm->getId();
		}
		if (y > 0) {
			organizmy_tabela_id[x][y - 1] = organizm->getId();
		}
		if (y + 1 < wysokosc) {
			organizmy_tabela_id[x][y + 1] = organizm->getId();
		}
		if (x > 0 && y > 0) {
			organizmy_tabela_id[x - 1][y - 1] = organizm->getId();
		}
	}


	organizmy_tabela_id[x][y] = organizm->getId();
	plansza[x][y] = organizm->rysowanie();
	if (organizmy_kolejka.size() > 0) {
		vector<Organizm*>::iterator it;
		for (it = organizmy_kolejka.begin(); it != organizmy_kolejka.end(); ++it) {
			if ((*it)->getInicjatywa() < organizm->getInicjatywa()) break;
		}
		organizmy_kolejka.insert(it, organizm);
	}
	else organizmy_kolejka.push_back(organizm);
	liczbaOrganizmow++;
}

void Swiat::wykonajTure()
{
	tura %= organizmy_kolejka.size();
	if (tura == 0) posortuj();
	organizmy_kolejka[tura]->akcja();
	//if (dynamic_cast<Zwierze*>(organizmy_kolejka[tura]))
	if (tura + 1 == organizmy_kolejka.size())
		rysujSwiat();
	tura++;
	for (vector<Organizm*>::iterator it = organizmy_kolejka.begin(); it != organizmy_kolejka.end(); ++it) {
		(*it)->zwiekszWiek();
	}
}

void Swiat::przesunZwierze(Organizm* organizm, int stary_X, int stary_Y, int nowy_X, int nowy_Y)
{
	auto org = find(organizmy_kolejka.begin(), organizmy_kolejka.end(), organizm);
	if (organizmy_tabela_id[nowy_X][nowy_Y] == 0) {
		organizmy_tabela_id[stary_X][stary_Y] = 0;
		organizmy_tabela_id[nowy_X][nowy_Y] = organizm->getId();
		plansza[stary_X][stary_Y] = ' ';
		plansza[nowy_X][nowy_Y] = organizm->rysowanie();
	}
	else {

		Organizm* organizm_kolizja = nullptr;
		int id_kolizja = organizmy_tabela_id[nowy_X][nowy_Y];
		int index;
		for (int i = 0; i != organizmy_kolejka.size(); i++) {
			if (organizmy_kolejka[i]->getId() == id_kolizja) {
				index = i;
				organizm_kolizja = organizmy_kolejka[i];
				break;
			}
		}
		if (dynamic_cast<Zwierze*>(organizm_kolizja))
			cout << "Kolizja! " << organizm->getNazwa() << " napotkal zwierze (" << organizm_kolizja->getNazwa() << ")";
		else {
			if (dynamic_cast<Guarana*>(organizm_kolizja)) dynamic_cast<Zwierze*>(organizm)->zwiekszSile();
			else if (!dynamic_cast<WilczeJagody*>(organizm_kolizja) && !dynamic_cast<BarszczSosnowskiego*>(organizm_kolizja))
			cout << "Kolizja! " << organizm->getNazwa() << " nadepnal na rosline (" << organizm_kolizja->getNazwa() << ")" << endl;
				
		}
		if (organizm->getNazwa() == organizm_kolizja->getNazwa()) { // rozmna¿anie
			dynamic_cast<Zwierze*>(organizm)->wrocNaOstatnieMiejsce();
			Organizm* nowy = organizm_kolizja->kolizja();
			dynamic_cast<Zwierze*>(nowy)->przesunNaWolneMiejsce();
			dodajOgranizm(nowy);
		}
		else {
			if (organizm_kolizja->czyOdparlAtak(organizm)) {
				if (!dynamic_cast<Zolw*>(organizm_kolizja) ) {
					plansza[stary_X][stary_Y] = ' ';
					organizmy_tabela_id[stary_X][stary_Y] = 0;
					if ((!dynamic_cast<Antylopa*>(organizm_kolizja) || !dynamic_cast<Antylopa*>(organizm_kolizja)->czyUciekla()) && (!dynamic_cast<Czlowiek*>(organizm_kolizja) || !dynamic_cast<Czlowiek*>(organizm_kolizja)->maWlaczonaMoc())) { // jesli nie antylopa lub antylopa wygrala
						
						organizmy_kolejka.erase(org);
						liczbaOrganizmow--;
					}
					else if (dynamic_cast<Antylopa*>(organizm_kolizja) || dynamic_cast<Czlowiek*>(organizm_kolizja)) { // jesli antylopa lub czlowiek uciekli
						if (dynamic_cast<Czlowiek*>(organizm_kolizja)) {
							dynamic_cast<Czlowiek*>(organizm_kolizja)->kolizja();
							organizmy_tabela_id[stary_X][stary_Y] = 0;
							organizmy_tabela_id[nowy_X][nowy_Y] = organizm->getId();
							plansza[nowy_X][nowy_Y] = organizm->rysowanie();
							plansza[organizm_kolizja->getX()][organizm_kolizja->getY()] = organizm_kolizja->rysowanie();
						}
						else {
							organizmy_tabela_id[stary_X][stary_Y] = 0;
							organizmy_tabela_id[nowy_X][nowy_Y] = organizm->getId();
							plansza[nowy_X][nowy_Y] = organizm->rysowanie();
							plansza[organizm_kolizja->getX()][organizm_kolizja->getY()] = organizm_kolizja->rysowanie();
							dynamic_cast<Antylopa*>(organizm_kolizja)->resetujUciekla();
						}
					}
				}
			}
			else {
				organizmy_tabela_id[stary_X][stary_Y] = 0;
				organizmy_tabela_id[nowy_X][nowy_Y] = organizm->getId();
				plansza[stary_X][stary_Y] = ' ';
				plansza[nowy_X][nowy_Y] = organizm->rysowanie();
				organizmy_kolejka.erase(organizmy_kolejka.begin() + index);
				liczbaOrganizmow--;
			}

		}
	}
}


int Swiat::getWysokosc()
{
	return wysokosc;
}
int Swiat::getSzerokosc()
{
	return szerokosc;
}

bool Swiat::czyWolneMiejsce(int poz_X, int poz_Y)
{
	if (poz_X >= 0 && poz_Y >= 0 && poz_X < szerokosc && poz_Y < wysokosc && plansza[poz_X][poz_Y] == ' ')
		return true;
	else return false;
}

int Swiat::getSilaOrganizmuNaPolu(int poz_X, int poz_Y)
{
	if (poz_X >= 0 || poz_Y >= 0 || poz_X < szerokosc || poz_Y < wysokosc || organizmy_tabela_id[poz_X][poz_Y] == 0)
		return 0;
	else
	{
		int id_kolizja = organizmy_tabela_id[poz_X][poz_Y];
		for (int i = 0; i != organizmy_kolejka.size(); i++) {
			if (organizmy_kolejka[i]->getId() == id_kolizja) {
				return organizmy_kolejka[i]->getSila();
			}
		}
	}
}

void Swiat::usunOrganizm(int poz_X, int poz_Y)
{
	int id = organizmy_tabela_id[poz_X][poz_Y];
	Organizm* organizm = nullptr;
	int index=0;
	for (int i = 0; i != organizmy_kolejka.size(); i++) {
		if (organizmy_kolejka[i]->getId() == id) {
			index = i;
			organizm = organizmy_kolejka[i];
			break;
		}
	}
	
	if (!dynamic_cast<BarszczSosnowskiego*>(organizm) && organizm != nullptr) {
		organizmy_kolejka.erase(organizmy_kolejka.begin() + index);
		organizmy_tabela_id[poz_X][poz_Y] = 0;
		plansza[poz_X][poz_Y] = ' ';
	}
}

void Swiat::posortuj()
{

}
