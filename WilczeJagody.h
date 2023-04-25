#pragma once
#include "Roslina.h"
class WilczeJagody :public Roslina
{
public:
	WilczeJagody(Para polozenie, Swiat& swiat);
	WilczeJagody(Para polozenie, Swiat& swiat, int dlugosc_zycia);
	char rysowanie() override;
	void rozmnazanie() override;
	int kolizja(Organizm* org) override;
	void akcja() override;
};

