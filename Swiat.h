#pragma once
#include "Organizm.h"
#include "Zwierze.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <vector>

#define PX 0
#define PY 1
enum kierunek {
	GORA=0,
	DOL=1,
	PRAWO=2,
	LEWO=3
};
using namespace std;
class Swiat
{
public:
	Swiat(int szerokosc, int wysokosc);
	~Swiat() {};
	void rysujSwiat();
	void dodajOgranizm(Organizm* organizm);
	void utworzOrganizm(Organizm* organizm);
	void wykonajTure();
	void przesunZwierze(Organizm* organizm, int stary_X, int stary_Y, int nowy_X, int nowy_Y);
	int getWysokosc();
	int getSzerokosc();
	bool czyWolneMiejsce(int poz_X, int poz_Y);
	int getSilaOrganizmuNaPolu(int poz_X, int poz_Y);
	void usunOrganizm(int poz_X, int poz_Y);
	void posortuj();
private:
	//vector<int> znajdzOrganizm(Organizm organizm, vector<int> tab);
	int szerokosc;
	int wysokosc;
	vector<vector<int> > organizmy_tabela_id;
	vector<vector<char> > plansza;
	vector<Organizm*> organizmy_kolejka;
	vector<Organizm*> nowe;
	int liczbaOrganizmow = 0;
	int tura = 0;
	int lastId = 0;
};
