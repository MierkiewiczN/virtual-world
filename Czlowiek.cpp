#include "Czlowiek.h"
class Swiat;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
Czlowiek::Czlowiek(Swiat* swiat, int x, int y)
{
    symbol = 'c';
    nazwa = "Czlowiek";
    this->swiat = swiat;
	sila = 5;
	inicjatywa = 4;
    polozenie[PX] = x;
    polozenie[PY] = y;
    wczesniejsze_polozenie[PX] = polozenie[PX];
    wczesniejsze_polozenie[PY] = polozenie[PY];
}

void Czlowiek::akcja()
{
    if (wlaczona_moc > 0)
        wlaczona_moc--;
    if (liczba_tur_do_mocy > 0)
        liczba_tur_do_mocy--;
    char key = '0';
    bool moved = false;
    wczesniejsze_polozenie[PX] = polozenie[PX];
    wczesniejsze_polozenie[PY] = polozenie[PY];
    cout << endl << "Ruch czlowieka";
    while (!moved) {
        switch (key = _getch())
        {
        case KEY_UP:
            if (polozenie[PY] > 0) {
                moved = true;
                polozenie[PY]--;
                //kierunek = GORA;

            }
            break;
        case KEY_DOWN:
            if (polozenie[PY] < swiat->getWysokosc() - 1) {
                moved = true;
                polozenie[PY]++;
                //kierunek = DOL;

            }
            break;
        case KEY_LEFT:
            if (polozenie[PX] > 0) {
                moved = true;
                polozenie[PX]--;
                //kierunek = LEWO;

            }
            break;
        case KEY_RIGHT:
            if (polozenie[PX] < swiat->getSzerokosc() - 1) {
                moved = true;
                polozenie[PX]++;
                //kierunek = PRAWO;

            }
            break;
        case 'm':
            if (liczba_tur_do_mocy == 0) {
                cout << endl << "Czlowiek aktywowal specjalna umiejetnosc." << endl;
                wlaczona_moc = 5;
                liczba_tur_do_mocy = 10;
            }
            else cout << "Nie mozna aktywowac specjalnej umiejetnosci. Pozostalo " << liczba_tur_do_mocy << " rund do mozliwosci jej aktywacji." << endl;
            break;
        }
    }
    cout << " z pola (" << wczesniejsze_polozenie[PX] << ", " << wczesniejsze_polozenie[PY] << ")";
    cout << " na pole (" << polozenie[PX] << ", " << polozenie[PY] << ")" << endl;
    swiat->przesunZwierze(this,wczesniejsze_polozenie[PX], wczesniejsze_polozenie[PY], polozenie[PX], polozenie[PY]);
    
}

Organizm* Czlowiek::kolizja()
{
    if (wlaczona_moc) {
        przesunNaWolneMiejsce();
    }
    return this;
}

bool Czlowiek::maWlaczonaMoc()
{
    return wlaczona_moc;
}

bool Czlowiek::czyOdparlAtak(Organizm* organizm)
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
        
        if (odparlAtak) {
            cout << endl << this->getNazwa() << " odparl atak, pokonuj¹c " << organizm->getNazwa() << endl;
            return odparlAtak;
        }
        else if (!wlaczona_moc) {
            cout << endl << organizm->getNazwa() << " pokonal " << this->getNazwa() << endl;
        return odparlAtak;
    }
    
    przesunNaWolneMiejsce();
    cout << endl << "Czlowiek skorzystal ze specjalnej umiejetnosci." << endl;
    return true;
}

