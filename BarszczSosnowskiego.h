#pragma once
#include "Roslina.h"
class BarszczSosnowskiego :
	public Roslina
{
public:
	BarszczSosnowskiego(Swiat* swiat, int x, int y);
	bool czyOdparlAtak(Organizm* organizm) override;
};

