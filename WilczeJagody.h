#pragma once
#include "Roslina.h"
class WilczeJagody :
	public virtual Roslina
{
public:
	WilczeJagody(Swiat* swiat, int x, int y);
	bool czyOdparlAtak(Organizm* organizm) override;
};