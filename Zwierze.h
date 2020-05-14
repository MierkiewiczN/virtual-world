#pragma once
#include "Organizm.h"
#include "Swiat.h"
class Zwierze :
	public virtual Organizm
{
public:
	void akcja() override;
	Organizm* kolizja() override;
	bool czyOdparlAtak(Organizm* organizm) override;
	void przesunNaWolneMiejsce() override;
	string getNazwa() override;
	void wrocNaOstatnieMiejsce();
	void zwiekszSile();
protected:
	int wczesniejsze_polozenie[2];
};