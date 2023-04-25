#include "Czlowiek.h"

using namespace std;

Czlowiek::Czlowiek(Para polozenie, Swiat& swiat): Zwierze(5, 4, polozenie, swiat), cooldown(0), ruch(-1)
{
}

Czlowiek::Czlowiek(int sila, int inicjatywa, Para polozenie, Swiat& swiat, int dlugosc_zycia, int cooldown) : Zwierze(sila, inicjatywa, polozenie, swiat, dlugosc_zycia), cooldown(cooldown), ruch(-1)
{

}

void Czlowiek::akcja()
{
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
	if (sila > 5)
	{
		sila--;
	}
	if(cooldown > 0)
		cooldown--;
	
}

void Czlowiek::umiejetnosc()
{
	cooldown = 10;
	sila += 5;
}

char Czlowiek::rysowanie()
{
	return '^';
}

void Czlowiek::setRuch(int ruch)
{
	this->ruch = ruch;
}

int Czlowiek::getRuch()
{
	return ruch;
}

int Czlowiek::getCooldown()
{
	return cooldown;
}