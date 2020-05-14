#pragma once
#include "Zwierze.h"
class Czlowiek :
	public virtual Zwierze
{
public:
	Czlowiek(Swiat* swiat, int x, int y);
	void akcja() override;
	Organizm* kolizja() override;
	bool maWlaczonaMoc();
	bool czyOdparlAtak(Organizm* organizm) override;
private:
	int wlaczona_moc=0;
	int liczba_tur_do_mocy=0;
};

