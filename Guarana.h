#pragma once
#include "Roslina.h"
class Guarana :public Roslina
{
public:
	Guarana(Para polozenie, Swiat& swiat);
	Guarana(Para polozenie, Swiat& swiat, int dlugosc_zycia);
	char rysowanie() override;
	int kolizja(Organizm* org) override;
	void rozmnazanie() override;
	void akcja() override;
};

