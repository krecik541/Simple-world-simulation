#include "Trawa.h"

using namespace std;

Trawa::Trawa(Para polozenie, Swiat& swiat): Roslina(0, polozenie, swiat)
{

}

Trawa::Trawa(Para polozenie, Swiat& swiat, int dlugosc_zycia) :Roslina(0, polozenie, swiat, dlugosc_zycia)
{

}

char Trawa::rysowanie()
{
	return 'T';
}

void Trawa::akcja()
{
	if (rand() % 7 == 0)
		rozmnazanie();
}

void Trawa::rozmnazanie()
{
	Para polozenie = szukajPozycji(this->polozenie), brakWolnegoMiejsca = { -1, -1 };
	if (polozenie == brakWolnegoMiejsca)
		return;
	Organizm* tmp = new Trawa(polozenie, swiat, -1);
	if (tmp != nullptr)
		swiat.setOrganizm(tmp);
}