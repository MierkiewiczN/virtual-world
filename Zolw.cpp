#include "Zolw.h"
Zolw::Zolw(Swiat* swiat, int x, int y)
{
    symbol = 'z';
    nazwa = "Zolw";
	this->swiat = swiat;
	sila = 2;
	inicjatywa = 1;
	polozenie[PX] = x;
	polozenie[PY] = y;
    wczesniejsze_polozenie[PX] = polozenie[PX];
    wczesniejsze_polozenie[PY] = polozenie[PY];
    wiek = 0;
}

Zolw::Zolw()
{
    wiek = 0;
    przesunNaWolneMiejsce();
}

void Zolw::akcja()
{
    // TODO: w 75% przypadków nie rusza siê
    bool moved = false;
    int stoi = rand()%4;
    wczesniejsze_polozenie[PX] = polozenie[PX];
    wczesniejsze_polozenie[PY] = polozenie[PY];
    if (stoi) cout << endl << endl << nazwa << " nie porusza sie i zostaje" << " na polu (" << polozenie[PX] << ", " << polozenie[PY] << ")" << endl;
    else {
        cout << endl << endl << nazwa << " poruszyl sie z pola (" << polozenie[PX] << ", " << polozenie[PY] << ")";
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
}


Organizm* Zolw::kolizja()
{
    // TODO: odpieranie ataku gdy sila < 5
    cout << endl << "Powstaje nowy Zolw" << endl;
    return new Zolw(swiat, this->getX(), this->getY());
}

bool Zolw::czyOdparlAtak(Organizm* organizm)
{
    if (organizm->getSila() < 5) {
        cout << endl << this->getNazwa() << " odparl atak " << organizm->getNazwa() << ". " << endl
            << organizm->getNazwa() << " wraca na swoje miejsce." << endl;
        return true;
    }
    else cout << endl << organizm->getNazwa() << " pokonal " << this->getNazwa() << ". " << endl;
    return true;
}