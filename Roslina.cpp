#include "Roslina.h"

using namespace std;

Roslina::Roslina(int sila, Para polozenie, Swiat& swiat): Organizm(sila, 0, polozenie, swiat, 0)
{

}

Roslina::Roslina(int sila, Para polozenie, Swiat& swiat, int dlugosc_zycia): Organizm(sila, 0, polozenie, swiat, dlugosc_zycia)
{

}

void Roslina::rozmnazanie()
{

}

void Roslina::akcja()
{

}

int Roslina::kolizja(Organizm*org)
{
	return WYGRYWA_ATAKUJACY;
}