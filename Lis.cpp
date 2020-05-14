#include "Lis.h"

Lis::Lis(Swiat* swiat, int x, int y)
{
	symbol = char(191);
	nazwa = "Lis";
	this->swiat = swiat;
	sila = 3;
	inicjatywa = 7;
	polozenie[PX] = x;
	polozenie[PY] = y;
	wczesniejsze_polozenie[PX] = polozenie[PX];
	wczesniejsze_polozenie[PY] = polozenie[PY];
	wiek = 0;
}

void Lis::akcja()
{
	// TODO: jeœli obok ktoœ silniejszy, to siê tam nie rusza

	cout << endl << nazwa << " poruszyl sie z pola (" << polozenie[PX] << ", " << polozenie[PY] << ")";
	wczesniejsze_polozenie[PX] = polozenie[PX];
	wczesniejsze_polozenie[PY] = polozenie[PY];
	int liczbaWolnychKierunkow = 0;
		if (swiat->czyWolneMiejsce(polozenie[PX], polozenie[PY] - 1) || (polozenie[PY] - 1 >= 0 && sila > swiat->getSilaOrganizmuNaPolu(polozenie[PX], polozenie[PY] - 1))) {
			liczbaWolnychKierunkow++;
		}
		if (swiat->czyWolneMiejsce(polozenie[PX], polozenie[PY] + 1) || (polozenie[PY] + 1 < swiat->getWysokosc() && sila > swiat->getSilaOrganizmuNaPolu(polozenie[PX], polozenie[PY] + 1))) {
			liczbaWolnychKierunkow++;
		}
		if (swiat->czyWolneMiejsce(polozenie[PX]-1, polozenie[PY]) || (polozenie[PX] - 1 >= 0 &&  sila > swiat->getSilaOrganizmuNaPolu(polozenie[PX] - 1, polozenie[PY]))) {
			liczbaWolnychKierunkow++;
		}
		if (swiat->czyWolneMiejsce(polozenie[PX]+1, polozenie[PY]) || (polozenie[PX] + 1 < swiat->getSzerokosc() && sila > swiat->getSilaOrganizmuNaPolu(polozenie[PX] + 1, polozenie[PY]))) {
			liczbaWolnychKierunkow++;
		}
	
	bool moved = false;
	if (liczbaWolnychKierunkow) {
		while (!moved) {
			switch (rand() % 4)
			{
			case GORA:
				if (polozenie[PY] > 0 && sila > swiat->getSilaOrganizmuNaPolu(polozenie[PX], polozenie[PY] - 1)) {
					moved = true;
					polozenie[PY]--;
				}
				break;
			case DOL:
				if (polozenie[PY] < swiat->getWysokosc() - 1 && sila > swiat->getSilaOrganizmuNaPolu(polozenie[PX], polozenie[PY] + 1)) {
					moved = true;
					polozenie[PY]++;
				}
				break;
			case LEWO:
				if (polozenie[PX] > 0 && sila > swiat->getSilaOrganizmuNaPolu(polozenie[PX] - 1, polozenie[PY])) {
					moved = true;
					polozenie[PX]--;
				}
				break;
			case PRAWO:
				if (polozenie[PX] < swiat->getSzerokosc() - 1 && sila > swiat->getSilaOrganizmuNaPolu(polozenie[PX] + 1, polozenie[PY])) {
					moved = true;
					polozenie[PX]++;
				}
				break;
			}
		}

		cout << " na pole (" << polozenie[PX] << ", " << polozenie[PY] << ")" << endl;
		swiat->przesunZwierze(this, wczesniejsze_polozenie[PX], wczesniejsze_polozenie[PY], polozenie[PX], polozenie[PY]);
	}
	else cout << endl << "Lis nie ma mozliwosci ruchu" << endl;
}


