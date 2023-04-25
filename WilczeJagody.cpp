#include "WilczeJagody.h"

using namespace std;

WilczeJagody::WilczeJagody(Para polozenie, Swiat& swiat) :Roslina(99, polozenie, swiat)
{

}

WilczeJagody::WilczeJagody(Para polozenie, Swiat& swiat, int dlugosc_zycia) :Roslina(0, polozenie, swiat, dlugosc_zycia)
{

}

void WilczeJagody::akcja()
{
	if (rand() % 9 == 0)
		rozmnazanie();
}

char WilczeJagody::rysowanie()
{
	return 'J';
}

int WilczeJagody::kolizja(Organizm* org)
{
	return OBA_GINA;
}

void WilczeJagody::rozmnazanie()
{
	Para polozenie = szukajPozycji(this->polozenie), brakWolnegoMiejsca = { -1, -1 };
	if (polozenie == brakWolnegoMiejsca)
		return;
	Organizm* tmp = new WilczeJagody(polozenie, swiat, -1);
	if (tmp != nullptr)
		swiat.setOrganizm(tmp);
}