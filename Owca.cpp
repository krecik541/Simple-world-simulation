#include "Owca.h"

Owca::Owca(Para polozenie, Swiat& swiat): Zwierze(4, 4, polozenie, swiat)
{

}

Owca::Owca(Para polozenie, Swiat& swiat, int dlugoscZycia) : Zwierze(4, 4, polozenie, swiat, dlugoscZycia)
{

}

Owca::Owca(int sila, int inicjatywa, Para polozenie, Swiat& swiat, int dlugosc_zycia) : Zwierze(sila, inicjatywa, polozenie, swiat, dlugosc_zycia)
{

}

void Owca::rozmnazanie()
{
	Para polozenie = szukajPozycji(this->polozenie), brakWolnegoMiejsca = { -1, -1 };
	if (polozenie == brakWolnegoMiejsca)
		return;
	Organizm* tmp = new Owca(polozenie, swiat, -1);
	if (tmp != nullptr)
		swiat.setOrganizm(tmp);
}

char Owca::rysowanie()
{
	return 'O';
}