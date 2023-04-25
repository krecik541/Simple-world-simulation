#include "Guarana.h"

using namespace std;

Guarana::Guarana(Para polozenie, Swiat& swiat) : Roslina(0, polozenie, swiat)
{

}

Guarana::Guarana(Para polozenie, Swiat& swiat, int dlugosc_zycia) :Roslina(0, polozenie, swiat, dlugosc_zycia)
{

}

char Guarana::rysowanie()
{
	return 'G';
}

int Guarana::kolizja(Organizm* org)
{
	org->setSila(org->getSila() + 3);
	return WYGRYWA_ATAKUJACY;
}

void Guarana::akcja()
{
	if (rand() % 8 == 0)
		rozmnazanie();
}

void Guarana::rozmnazanie()
{
	Para polozenie = szukajPozycji(this->polozenie), brakWolnegoMiejsca = { -1, -1 };
	if (polozenie == brakWolnegoMiejsca)
		return;
	Organizm* tmp = new Guarana(polozenie, swiat, -1);
	if (tmp != nullptr)
		swiat.setOrganizm(tmp);
}