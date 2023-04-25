#pragma once
#include "Roslina.h"
class Mlecz :public Roslina
{
public:
	Mlecz(Para polozenie, Swiat& swiat);
	Mlecz(Para polozenie, Swiat& swiat, int dlugosc_zycia);
	void akcja() override;
	char rysowanie() override;
};

