#pragma once
#include "Roslina.h"
class BarszczSosnowskiego :public Roslina
{
public:
	BarszczSosnowskiego(Para polozenie, Swiat& swiat);
	BarszczSosnowskiego(Para polozenie, Swiat& swiat, int dlugosc_zycia);
	void akcja() override;
	char rysowanie() override;
	int kolizja(Organizm* org) override;
	void rozmnazanie() override;
};

