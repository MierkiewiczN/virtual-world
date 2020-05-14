#pragma once
#include "Zwierze.h"
class Zolw :
	public virtual Zwierze
{
public:
	Zolw(Swiat* swiat, int x, int y);
	Zolw();
	void akcja() override;
	Organizm* kolizja() override;
	bool czyOdparlAtak(Organizm* organizm) override;
};

