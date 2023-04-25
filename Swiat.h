#pragma once
#include<iostream>
#include"Organizm.h"
#include"Para.h"
#define OWCA 0 
#define WILK 1
#define LIS 2
#define ZOLW 3
#define ANTYLOPA 4
#define TRAWA 5
#define MLECZ 6
#define GUARANA 7
#define JAGODY 8
#define BARSZCZ 9

using namespace std;

class Organizm;
class Czlowiek;

class Swiat
{
private:
	Organizm **t;//init + vector?
	int n, m;//ROZMIARY PLANSZY
	char** tab;
	double zapelnienie;
	void sortuj();
public:
	Swiat(int n, int m, double zapelnienie);
	Swiat();
	~Swiat();
	int getN();
	int getM();
	void wykonajTure();
	bool rysujSwiat();
	void generacja(float zapelnienie);
	void setOrganizm(Organizm* org);
	void setOrganizm(Organizm* org, Organizm* doUsuniecia);
	void setOrganizm(Para polozenieDoUsuniecia, Para przez);
	Organizm* getOrganizm(Para polozenie);
	void zapis(Czlowiek* czlowiek);
	void odczyt(Czlowiek** czlowiek);
};