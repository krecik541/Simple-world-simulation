#pragma once
#include "Zwierze.h"
#define UMEJETNOSC 5
class Czlowiek :public Zwierze
{
private:
	int cooldown, ruch;
public:
	Czlowiek(Para polozenie, Swiat& swiat);
	Czlowiek(int sila, int inicjatywa, Para polozenie, Swiat& swiat, int dlugosc_zycia, int cooldown);
	void akcja() override;
	void setRuch(int ruch);
	int getRuch();
	int getCooldown();
	void umiejetnosc();
	char rysowanie() override;
};

