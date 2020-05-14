#pragma once
#include "Zwierze.h"
class Lis :
	public virtual Zwierze
{
public:
	Lis(Swiat* swiat, int x, int y);
	void akcja() override;

};

