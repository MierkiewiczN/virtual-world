#pragma once
#include "Organizm.h"
#include "Swiat.h"
class Roslina :
	public virtual Organizm
{
public:
	void akcja() override;
	Organizm* kolizja() override;
	void stworzNowaRosline();
	void przesunNaWolneMiejsce() override;
	string getNazwa() override;
	bool czyOdparlAtak(Organizm* organizm) override;
protected:
	double prawdopodobienstwo;
};

