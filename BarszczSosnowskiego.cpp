#include "BarszczSosnowskiego.h"
#include "Zwierze.h"

using namespace std;

BarszczSosnowskiego::BarszczSosnowskiego(Para polozenie, Swiat& swiat) : Roslina(10, polozenie, swiat)
{

}

BarszczSosnowskiego::BarszczSosnowskiego(Para polozenie, Swiat& swiat, int dlugosc_zycia) :Roslina(10, polozenie, swiat, dlugosc_zycia)
{

}

void BarszczSosnowskiego::akcja()
{
	Organizm* tmp;
	tmp = swiat.getOrganizm({ polozenie.x, polozenie.y - 1});
	tmp = dynamic_cast<Zwierze*>(tmp);
	if (!(tmp == nullptr))
		swiat.setOrganizm({ polozenie.x, polozenie.y - 1 }, polozenie);
	
	tmp = swiat.getOrganizm({ polozenie.x, polozenie.y + 1});
	tmp = dynamic_cast<Zwierze*>(tmp);
	if (!(tmp == nullptr))
		swiat.setOrganizm({ polozenie.x, polozenie.y + 1 }, polozenie);
	
	tmp = swiat.getOrganizm({ polozenie.x - 1, polozenie.y});
	tmp = dynamic_cast<Zwierze*>(tmp);
	if (!(tmp == nullptr))
		swiat.setOrganizm({ polozenie.x - 1, polozenie.y }, polozenie);
	
	tmp = swiat.getOrganizm({ polozenie.x + 1, polozenie.y});
	tmp = dynamic_cast<Zwierze*>(tmp);
	if (!(tmp == nullptr))
		swiat.setOrganizm({ polozenie.x + 1, polozenie.y }, polozenie);
	if (rand() % 9 == 0)
		rozmnazanie();
}

char BarszczSosnowskiego::rysowanie()
{
	return 'B';
}

int BarszczSosnowskiego::kolizja(Organizm* org)
{
	return OBA_GINA;
}

void BarszczSosnowskiego::rozmnazanie()
{
	Para polozenie = szukajPozycji(this->polozenie), brakWolnegoMiejsca = { -1, -1 };
	if (polozenie == brakWolnegoMiejsca)
		return;
	Organizm* tmp = new BarszczSosnowskiego(polozenie, swiat, -1);
	if (tmp != nullptr)
		swiat.setOrganizm(tmp);
}