#include "Lis.h"

Lis::Lis(Para polozenie, Swiat& swiat): Zwierze(3, 7, polozenie, swiat)
{

}

Lis::Lis(Para polozenie, Swiat& swiat, int dlugoscZycia): Zwierze(3, 7, polozenie, swiat, dlugoscZycia)
{

}

Lis::Lis(int sila, int inicjatywa, Para polozenie, Swiat& swiat, int dlugosc_zycia) : Zwierze(sila, inicjatywa, polozenie, swiat, dlugosc_zycia)
{

}

char Lis::rysowanie()
{
	return 'L';
}

void Lis::akcja()
{
	int ruch = rand() % 4;
	Organizm* org = nullptr;
	Para tmpPolozenie = polozenie, brakWolnegoMiejsca = { -1, -1 };
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
	if (org != nullptr)
	{
		if (org->getSila() <= this->sila)
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
	}
	else
	{
		cout << "Organizm " << rozpoznanieOrg() << " [" << polozenie.x << "," << polozenie.y << "] zmienil polozenie na [" << tmpPolozenie.x << "," << tmpPolozenie.y << "]\n";
		setPolozenie(tmpPolozenie);
	}
}

void Lis::rozmnazanie()
{
	Para polozenie = szukajPozycji(this->polozenie), brakWolnegoMiejsca = { -1, -1 };
	if (polozenie == brakWolnegoMiejsca)
		return;
	Organizm* tmp = new Lis(polozenie, swiat, -1);
	if (tmp != nullptr)
		swiat.setOrganizm(tmp);
}