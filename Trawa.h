#pragma once
#include "Roslina.h"
class Trawa :public Roslina
{
public:
	Trawa(Para polozenie, Swiat& swiat);
	Trawa(Para polozenie, Swiat& swiat, int dlugosc_zycia);
	char rysowanie() override;
	void akcja() override;
	void rozmnazanie() override;
};

