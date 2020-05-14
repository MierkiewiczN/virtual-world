#include <iostream>
#include "Swiat.h"
#include "Organizm.h"   
#include "Czlowiek.h"
#include "Wilk.h"
#include "Owca.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"
int main()
{
    int n, m;
    cout << "Podaj szerokosc planszy: ";
    cin >> n;
    cout << "\nPodaj wysokosc planszy: ";
    cin >> m;
    Swiat* swiat = new Swiat(n, m);
    Czlowiek* czlowiek = new Czlowiek(swiat,1,5);
    Owca* owca = new Owca(swiat,5,6);

    
    Trawa* trawa = new Trawa(swiat, 9, 2);
    Mlecz* mlecz = new Mlecz(swiat, 7, 7);
    Guarana* guarana = new Guarana(swiat, 13, 3);
    WilczeJagody* jagody = new WilczeJagody(swiat, 6, 3);
    BarszczSosnowskiego* barszcz = new BarszczSosnowskiego(swiat, 12, 3);
    Antylopa* Antylopa1 = new Antylopa(swiat, 17, 4);
    Lis* lis2 = new Lis(swiat, 1, 2);
    Antylopa* Antylopa3 = new Antylopa(swiat, 12, 5);
    Antylopa* Antylopa4 = new Antylopa(swiat, 11, 2);
    Wilk* wilk = new Wilk(swiat, 10, 3);
    swiat->dodajOgranizm(czlowiek);
    swiat->dodajOgranizm(lis2);
    swiat->dodajOgranizm(owca);
    swiat->dodajOgranizm(Antylopa1);
    swiat->dodajOgranizm(mlecz);
    swiat->dodajOgranizm(Antylopa3);
    swiat->dodajOgranizm(Antylopa4);
    swiat->dodajOgranizm(trawa);
    swiat->dodajOgranizm(guarana);
    swiat->dodajOgranizm(jagody);
    swiat->dodajOgranizm(barszcz);
    swiat->dodajOgranizm(wilk);
    swiat->rysujSwiat();
    while (1) {
        swiat->wykonajTure();
    }
}