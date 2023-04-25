#include "Organizm.h"
#include"Antylopa.h"
#include"Lis.h"
#include"Owca.h"
#include"Wilk.h"
#include"Zolw.h"
#include"BarszczSosnowskiego.h"
#include"Guarana.h"
#include"Trawa.h"
#include"Mlecz.h"
#include"WilczeJagody.h"
#include"Czlowiek.h"

using namespace std;

Organizm::Organizm(int sila, int inicjatywa, Para polozenie, Swiat& swiat, int dlugosc_zycia): swiat(swiat), dlugosc_zycia(dlugosc_zycia)
{
	setSila(sila);
	setInicjatywa(inicjatywa);
	setPolozenie(polozenie);
}

Organizm::~Organizm()
{
	;
}

int Organizm::getSila()
{
	return sila;
}

void Organizm::setSila(int sila)
{
	this->sila = sila;
}

int Organizm::getInicjatywa()
{
	return inicjatywa;
}

void Organizm::setInicjatywa(int inicjatywa)
{
	this->inicjatywa = inicjatywa;
}

Para Organizm::getPolozenie()
{
	return polozenie;
}

void Organizm::setPolozenie(Para polozenie)
{
	this->polozenie.x = polozenie.x;
	this->polozenie.y = polozenie.y;
}

Swiat& Organizm::getSwiat()
{
	return swiat;
}

void Organizm::setSwiat(Swiat& swiat)
{
	this->swiat = swiat;
}

int Organizm::getDlugoscZycia()
{
	return dlugosc_zycia;
}

void Organizm::setDlugoscZycia()
{
	this->dlugosc_zycia++;
}

string Organizm::rozpoznanieOrg()
{
	Zwierze* tmp = dynamic_cast<Zwierze*>(this);
	if(tmp != nullptr)
	{
		tmp = dynamic_cast<Antylopa*>(this);
		if (tmp != nullptr)
			return "Antylopa";
		tmp = dynamic_cast<Lis*>(this);
		if (tmp != nullptr)
			return "Lis";
		tmp = dynamic_cast<Owca*>(this);
		if (tmp != nullptr)
			return "Owca";
		tmp = dynamic_cast<Wilk*>(this);
		if (tmp != nullptr)
			return "Wilk";
		tmp = dynamic_cast<Zolw*>(this);
		if (tmp != nullptr)
			return "Zolw";
		tmp = dynamic_cast<Czlowiek*>(this);
		if (tmp != nullptr)
			return "Czlowiek";
	}
	Roslina* tmp1 = dynamic_cast<Roslina*>(this);
	if (tmp1 != nullptr)
	{
		tmp1 = dynamic_cast<Trawa*>(this);
		if (tmp1 != nullptr)
			return "Trawa";
		tmp1 = dynamic_cast<Mlecz*>(this);
		if (tmp1 != nullptr)
			return "Mlecz";
		tmp1 = dynamic_cast<Guarana*>(this);
		if (tmp1 != nullptr)
			return "Guarana";
		tmp1 = dynamic_cast<WilczeJagody*>(this);
		if (tmp1 != nullptr)
			return "Wilcze jagody";
		tmp1 = dynamic_cast<BarszczSosnowskiego*>(this);
		if (tmp1 != nullptr)
			return "Barszcz Sosnowskiego";
	}
}

Para Organizm::szukajPozycji(Para polozenie)
{
	int i = 0, ma = swiat.getM() * swiat.getN();
	bool gora = true, dol = true, lewo = true, prawo = true;
	if (polozenie.y - 1 < 0 || swiat.getOrganizm({ polozenie.x, polozenie.y - 1 }) != nullptr)
		lewo = false;
	if (polozenie.y + 1 >= swiat.getM() || swiat.getOrganizm({polozenie.x, polozenie.y + 1}) != nullptr)
		prawo = false;
	if (polozenie.x - 1 < 0 || swiat.getOrganizm({ polozenie.x - 1, polozenie.y }) != nullptr)
		gora = false;
	if (polozenie.x + 1 >= swiat.getN() || swiat.getOrganizm({ polozenie.x + 1, polozenie.y }) != nullptr)
		dol = false;
	
	if (!gora && !dol && !prawo && !lewo)
		return { -1, -1 };
	while (1)
	{
		i = rand() % 4;
		if (i == LEWO  && lewo)
			return { polozenie.x, polozenie.y - 1 };
		else if (i == PRAWO && prawo)
			return { polozenie.x, polozenie.y + 1 };
		else if (i == GORA && gora)
			return { polozenie.x - 1, polozenie.y };
		else if (i == DOL && dol)
			return { polozenie.x + 1, polozenie.y };
	}
}