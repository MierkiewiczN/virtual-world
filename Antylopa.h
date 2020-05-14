#pragma once
#include "Zwierze.h"
class Antylopa :
	public virtual Zwierze
{
public:
	Antylopa(Swiat* swiat, int x, int y);
	void akcja() override;
	Organizm* kolizja() override;
	bool czyOdparlAtak(Organizm* organizm) override;
	bool czyUciekla();
	void resetujUciekla();
private:
	bool uciekla;
};


