#include "Zwierze.h"
#include<iostream>
#include<ctime>
#include"Zolw.h"
#include"Antylopa.h"
#include"Wilk.h"
#include"Lis.h"
#include"Owca.h"

using namespace std;

Zwierze::Zwierze(int sila, int inicjatywa, Para polozenie, Swiat& swiat): Organizm(sila, inicjatywa, polozenie, swiat, 0)
{
}

Zwierze::Zwierze(int sila, int inicjatywa, Para polozenie, Swiat& swiat, int dlugosc_zycia): Organizm(sila, inicjatywa, polozenie, swiat, dlugosc_zycia)
{
}

//info o akcji
void Zwierze::akcja()
{
	int ruch = rand() % 4;
	Organizm* org = nullptr;
	Para tmpPolozenie = polozenie, brakWolnegoMiejsca = {-1, -1};
	if (ruch == LEWO && polozenie.y - 1 >= 0)
	{
		tmpPolozenie.y--;
	}
	else if (ruch == PRAWO && polozenie.y + 1 < swiat.getM())
	{
		tmpPolozenie.y++;
	}
	else if (ruch == GORA && polozenie.x - 1 >= 0)
	{
		tmpPolozenie.x--;
	}
	else if (ruch == DOL && polozenie.x + 1 < swiat.getN())
	{
		tmpPolozenie.x++;
	}
	else
		return;
	org = swiat.getOrganizm(tmpPolozenie);
	if(org != nullptr)
	{
		switch (org->kolizja(this))
		{
		case ODPIERANIE_ATAKU:
			break;
		case UCIECZKA1://ucieka atakowany
			tmpPolozenie = this->szukajPozycji(org->getPolozenie());
			if (tmpPolozenie == brakWolnegoMiejsca)
			{
				swiat.setOrganizm(org->getPolozenie(), this->polozenie);
				setPolozenie(tmpPolozenie);
			}
			else
				org->setPolozenie(tmpPolozenie);
			break;
		case WYGRYWA_ATAKUJACY:
			swiat.setOrganizm(this, org);
			break;
		case WYGRYWA_BRONIACY:
			swiat.setOrganizm(this->polozenie, org->getPolozenie());
			break;
		case OBA_GINA:
			swiat.setOrganizm(this->polozenie, org->getPolozenie());
			swiat.setOrganizm(org->getPolozenie(), this->polozenie);
			break;
		default:
			break;
		}
	}
	else
	{
		cout << "Organizm " << rozpoznanieOrg() << " [" << polozenie.x << "," << polozenie.y << "] zmienil polozenie na [" << tmpPolozenie.x << "," << tmpPolozenie.y << "]\n";
		setPolozenie(tmpPolozenie);
	}
}

void Zwierze::rozmnazanie()
{

}

int Zwierze::kolizja(Organizm* org)//info o kolizji
{
	string orgType = org->rozpoznanieOrg();
	string THIS = this->rozpoznanieOrg();
	if (THIS == orgType)
	{
		if(this->getDlugoscZycia() >= 0 && org->getDlugoscZycia() >= 0)
			rozmnazanie();
		return ROZMNAZANIE;
	}
	if (this->sila > org->getSila() || this->sila == org->getSila())
		return WYGRYWA_BRONIACY;
	else if (this->sila < org->getSila())
		return WYGRYWA_ATAKUJACY;
}