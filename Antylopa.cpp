#include "Antylopa.h"

Antylopa::Antylopa(Para polozenie, Swiat& swiat) : Zwierze(4, 4, polozenie, swiat)
{

}

Antylopa::Antylopa(Para polozenie, Swiat& swiat, int dlugoscZycia) : Zwierze(4, 4, polozenie, swiat, dlugoscZycia)
{

}

Antylopa::Antylopa(int sila, int inicjatywa, Para polozenie, Swiat& swiat, int dlugosc_zycia) : Zwierze(sila, inicjatywa, polozenie, swiat, dlugosc_zycia)
{

}

void Antylopa::akcja()
{
	int ruch = rand() % 4;
	Organizm* org = nullptr;
	Para tmpPolozenie = polozenie, brakWolnegoMiejsca = { -1, -1 };
	for (int i = 1; i <= 2; i++)
	{
		if (ruch == LEWO && tmpPolozenie.y - 1 >= 0)
		{
			tmpPolozenie.y--;
		}
		else if (ruch == PRAWO && tmpPolozenie.y + 1 < swiat.getM())
		{
			tmpPolozenie.y++;
		}
		else if (ruch == GORA && tmpPolozenie.x - 1 >= 0)
		{
			tmpPolozenie.x--;
		}
		else if (ruch == DOL && tmpPolozenie.x + 1 < swiat.getN())
		{
			tmpPolozenie.x++;
		}
		else
			return;
	}
	org = swiat.getOrganizm(tmpPolozenie);
	if (org != nullptr)
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

char Antylopa::rysowanie()
{
	return 'A';
}

int Antylopa::kolizja(Organizm* org)
{
	string orgType = org->rozpoznanieOrg();
	string THIS = this->rozpoznanieOrg();
	if (THIS == orgType)
	{
		if (this->getDlugoscZycia() >= 0 && org->getDlugoscZycia() >= 0)
			rozmnazanie();
		return ROZMNAZANIE;
	}
	if (rand() % 2 == 0)
		UCIECZKA1;
	else
		Zwierze::kolizja(org);
}


void Antylopa::rozmnazanie()
{
	Para polozenie = szukajPozycji(this->polozenie), brakWolnegoMiejsca = { -1, -1 };
	if (polozenie == brakWolnegoMiejsca)
		return;
	Organizm* tmp = new Antylopa(polozenie, swiat, -1);
	if (tmp != nullptr)
		swiat.setOrganizm(tmp);
}