#pragma once
#include "Organizm.h"
class Roslina : public Organizm
{
public:
	Roslina(int sila, Para polozenie, Swiat& swiat);
	Roslina(int sila, Para polozenie, Swiat& swiat, int dlugosc_zycia);
	void rozmnazanie() override;
	void akcja() override;
	int kolizja(Organizm* org) override;
};

