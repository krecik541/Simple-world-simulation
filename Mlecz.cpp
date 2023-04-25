#include "Mlecz.h"
#include<ctime>

using namespace std;

Mlecz::Mlecz(Para polozenie, Swiat& swiat) :Roslina(0, polozenie, swiat)
{

}

Mlecz::Mlecz(Para polozenie, Swiat& swiat, int dlugosc_zycia) :Roslina(0, polozenie, swiat, dlugosc_zycia)
{

}

void Mlecz::akcja()
{
	int i = 1;
	Organizm* tmp;
	Para pol = szukajPozycji(this->polozenie), brakWolnegoMiejsca = {-1, -1};
	while(i<=3)
	{
		if (rand() % 7 == 0)
		{
			if (pol != brakWolnegoMiejsca)
			{
				Mlecz* mlecz = new Mlecz(pol, swiat, -1);
				tmp = mlecz;
				swiat.setOrganizm(tmp);
			}
			else
				break;
		}
		i++;
		pol = szukajPozycji(this->polozenie);
	}
}

char Mlecz::rysowanie()
{
	return 'M';
}
