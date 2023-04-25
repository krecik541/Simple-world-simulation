#include "Zolw.h"

Zolw::Zolw(Para polozenie, Swiat& swiat) : Zwierze(2, 1, polozenie, swiat)
{

}

Zolw::Zolw(Para polozenie, Swiat& swiat, int dlugoscZycia) : Zwierze(2, 1, polozenie, swiat, dlugoscZycia)
{

}

Zolw::Zolw(int sila, int inicjatywa, Para polozenie, Swiat& swiat, int dlugosc_zycia) : Zwierze(sila, inicjatywa, polozenie, swiat, dlugosc_zycia)
{

}

void Zolw::akcja()
{
	int ruch = rand() % 4;
	if (ruch > 0)
		return;
	Zwierze::akcja();
}

char Zolw::rysowanie()
{
	return 'Z';
}

int Zolw::kolizja(Organizm* org)
{
	string orgType = org->rozpoznanieOrg();
	string THIS = this->rozpoznanieOrg();
	if (THIS == orgType)
	{
		if (this->getDlugoscZycia() >= 0 && org->getDlugoscZycia() >= 0)
			rozmnazanie();
		return ROZMNAZANIE;
	}
	if (org->getSila() < 5)
		return ODPIERANIE_ATAKU;
	else
		return Zwierze::kolizja(org);
}

void Zolw::rozmnazanie()
{
	Para polozenie = szukajPozycji(this->polozenie), brakWolnegoMiejsca = { -1, -1 };
	if (polozenie == brakWolnegoMiejsca)
		return;
	Organizm* tmp = new Zolw(polozenie, swiat, -1);
	if (tmp != nullptr)
		swiat.setOrganizm(tmp);
}