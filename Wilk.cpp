#include "Wilk.h"


Wilk::Wilk(Para polozenie, Swiat& swiat): Zwierze(9, 5, polozenie, swiat)
{
	
}

Wilk::Wilk(Para polozenie, Swiat& swiat, int dlugoscZycia) : Zwierze(9, 5, polozenie, swiat, dlugoscZycia)
{

}

Wilk::Wilk(int sila, int inicjatywa, Para polozenie, Swiat& swiat, int dlugosc_zycia) : Zwierze(sila, inicjatywa, polozenie, swiat, dlugosc_zycia)
{

}

char Wilk::rysowanie()
{
	return 'W';
}

void Wilk::rozmnazanie()
{
	Para polozenie = szukajPozycji(this->polozenie), brakWolnegoMiejsca = { -1, -1 };
	if (polozenie == brakWolnegoMiejsca)
		return;
	Organizm* tmp = new Wilk(polozenie, swiat, -1);
	if (tmp != nullptr)
		swiat.setOrganizm(tmp);
}