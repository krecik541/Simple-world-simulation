#define _CRT_SECURE_NO_WARNINGS
#include "Swiat.h"
#include"Antylopa.h"
#include"Owca.h"
#include"Zolw.h"
#include"Czlowiek.h"
#include"BarszczSosnowskiego.h"
#include"Guarana.h"
#include"Lis.h"
#include"Mlecz.h"
#include"Trawa.h"
#include"WilczeJagody.h"
#include"Wilk.h"
#include<fstream>


using namespace std;

Swiat::Swiat(int n, int m, double zapelnienie) :n(n), m(m), zapelnienie(zapelnienie)
{
	t = new Organizm*[n * m];
	for (int i = 0; i < n * m; i++)
		t[i] = nullptr;
	generacja(zapelnienie);
	tab = new char* [n];
	for (int i = 0; i < n; i++)
	{
		tab[i] = new char[m];
		for (int j = 0; j < m; j++)
			tab[i][j] = ' ';
	}
	Para pol;
	int i = 0;
	while (i < n * m)
	{
		if (t[i] != nullptr)
		{
			pol = t[i]->getPolozenie();
			if (0 <= pol.x && pol.x < n && 0 <= pol.y && pol.y < m)
				tab[pol.x][pol.y] = t[i]->rysowanie();
		}
		i++;
	}
}

Swiat::Swiat() :n(20), m(20), zapelnienie(0.5)
{
	t = new Organizm*[n * m];
	for (int i = 0; i < n * m; i++)
		t[i] = nullptr;
	generacja(zapelnienie);
	char** tab = new char* [n];
	for (int i = 0; i < n; i++)
	{
		tab[i] = new char[m];
		for (int j = 0; j < m; j++)
			tab[i][j] = ' ';
	}
	Para pol;
	int i = 0;
	while (i < n * m)
	{
		if (t[i] != nullptr)
		{
			pol = t[i]->getPolozenie();
			if (0 <= pol.x && pol.x < n && 0 <= pol.y && pol.y < m)
				tab[pol.x][pol.y] = t[i]->rysowanie();
		}
		i++;
	}
}

Swiat::~Swiat()
{
	delete[]t;
	for (int i = 0; i < n; i++)
		delete[]tab[i];
	delete[]tab;
}

int Swiat::getN()
{
	return n;
}

int Swiat::getM()
{
	return m;
}

void Swiat::wykonajTure()
{
	system("CLS");
	sortuj();
	/*for (int i = 0; i < n * m; i++)
		if(t[i]!= nullptr)
			cout << t[i]->rozpoznanieOrg() << " znajduje sie na pozycji [" << t[i]->getPolozenie().x << "," << t[i]->getPolozenie().y << "] " << t[i]->getSila() << " " << t[i]->getInicjatywa() << " " << t[i]->getDlugoscZycia() << endl;
	cout << "--------------------------------------\n";*/
	for (int i = 0; i < n * m; i++)
	{
		if (t[i] != nullptr)
		{
			t[i]->setDlugoscZycia();
			if(t[i]->getDlugoscZycia() > 0)
				t[i]->akcja();
		}
	}
	//zaleznie od kolejnosc prirytetow wykonac akcje dla kazdego Organizmow
	//pozycja kursora
	//wypisz logi
	//jesli nowe organizmy zostaly dodane albo stare usunete dodaj lub usun 
	//jesli ^, posortuj wedlug inicjatywy a pozniej wedlug wieku
}

bool Swiat::rysujSwiat()
{
	bool czyZyje = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			tab[i][j] = ' ';
	}

	Para pol;
	int i = 0;
	while (i < n * m)
	{
		if(t[i] != nullptr)
		{
			pol = t[i]->getPolozenie();
			if (0 <= pol.x && pol.x < n && 0 <= pol.y && pol.y < m)
				tab[pol.x][pol.y] = t[i]->rysowanie();
		}
		i++;
	}

	cout << (char)218;
	for (int i = 1; i < m + 1; i++)
		cout << (char)196;
	cout << (char)191 << endl;
	for (int i = 0; i < n; i++)
	{
		cout << '|';
		for (int j = 0; j < m; j++)
		{
			if (tab[i][j] == 'A' || tab[i][j] == 'L' || tab[i][j] == 'O' || tab[i][j] == 'W' || tab[i][j] == 'Z')
				cout << "\033[1;31m" << tab[i][j] << "\033[0m";
			else if (tab[i][j] == 'J' || tab[i][j] == 'M' || tab[i][j] == 'T' || tab[i][j] == 'B' || tab[i][j] == 'G')
				cout << "\033[1;32m" << tab[i][j] << "\033[0m";
			else if (tab[i][j] == '^')
			{
				czyZyje = true;
				cout << "\033[1;35m" << tab[i][j] << "\033[0m";
			}
			else
				cout << tab[i][j];
		}

		cout << '|' << endl;
	}
	cout << (char)192;
	for (int i = 1; i < m + 1; i++)
		cout << (char)196;
	cout << (char)217 << endl; 
	return czyZyje;
}

void Swiat::generacja(float zapelnienie)
{
	int n = 0;
	int liczbaOrganizmow = floor(this->n * this->m * zapelnienie)-1;
	Para miejsceDlaCzlowieka = { 0, 0 };
	Organizm* tmp = nullptr;
	while (liczbaOrganizmow > 0)
	{
		Para polozenie = { rand() % this->n, rand() % this->m };
		if (polozenie == miejsceDlaCzlowieka || getOrganizm(polozenie) != nullptr)
			continue;
		n = rand() % 10;
		switch (n)
		{
		case OWCA:
		{
			Owca *owca = new Owca(polozenie, *this);
			tmp = owca;
			break;
		}
		case WILK:
		{
			Wilk *wilk = new Wilk(polozenie, *this);
			tmp = wilk;
			break;
		}
		case LIS:
		{
			Lis *lis = new Lis(polozenie, *this);
			tmp = lis;
			break;
		}
		case ZOLW:
		{
			Zolw *zolw = new Zolw(polozenie, *this);
			tmp = zolw;
			break;
		}
		case ANTYLOPA:
		{
			Antylopa *antylopa = new Antylopa(polozenie, *this);
			tmp = antylopa;
			break;
		}
		case TRAWA:
		{
			Trawa *trawa = new Trawa(polozenie, *this);
			tmp = trawa;
			break;
		}
		case MLECZ:
		{
			Mlecz *mlecz = new Mlecz(polozenie, *this);
			tmp = mlecz;
			break;
		}
		case GUARANA:
		{
			Guarana* guarana = new Guarana(polozenie, *this);
			tmp = guarana;
			break;
		}
		case JAGODY:
		{
			WilczeJagody *jagody = new WilczeJagody(polozenie, *this);
			tmp = jagody;
			break;
		}
		case BARSZCZ:
		{
			BarszczSosnowskiego *barszcz = new BarszczSosnowskiego(polozenie, *this);
			tmp = barszcz;
			break;
		}
		}
		setOrganizm(tmp);
		liczbaOrganizmow--;
	}
}

void Swiat::setOrganizm(Organizm* org)
{
	if (org == nullptr)
		return;
	int i = 0;
	while (t[i] != nullptr && i<n*m)
	{
		i++;
	}
	if (i >= n * m)
		return;
	t[i] = org;
	cout << "Powstal Organizm " << t[i]->rozpoznanieOrg() << " na pozycji [" << t[i]->getPolozenie().x << "," << t[i]->getPolozenie().y << "]\n";
}

void Swiat::setOrganizm(Organizm* org, Organizm* doUsuniecia)
{
	int i = 0;
	while (i < n * m)
	{
		if (t[i] == doUsuniecia)
		{
			cout << "Organizm " << doUsuniecia->rozpoznanieOrg() << " [" << doUsuniecia->getPolozenie().x << "," << doUsuniecia->getPolozenie().y << "]" << " zostal zabity przez " << org->rozpoznanieOrg() << " [" << org->getPolozenie().x << "," << org->getPolozenie().y << "]" << endl;
			org->setPolozenie(doUsuniecia->getPolozenie());
			t[i] = nullptr;
			break;
		}
		i++;
	}
}

void Swiat::setOrganizm(Para polozenieDoUsuniecia, Para przez)
{
	int i = 0;
	while (i < n * m)
	{
		if (t[i] != nullptr && t[i]->getPolozenie() == polozenieDoUsuniecia)
		{
			if(getOrganizm(przez) != nullptr)
				cout << "Organizm " << t[i]->rozpoznanieOrg() << "[" << t[i]->getPolozenie().x << "," << t[i]->getPolozenie().y << "] zostal zabity przez " << getOrganizm(przez)->rozpoznanieOrg() << " [" << przez.x << "," << przez.y << "]\n";
			else
				cout << "Jednoczesnie Organizm " << t[i]->rozpoznanieOrg() << " [" << t[i]->getPolozenie().x << "," << t[i]->getPolozenie().y << "] zostal zabity\n";
			t[i] = nullptr;
			break;
		}
		i++;
	}
}

Organizm* Swiat::getOrganizm(Para polozenie)
{
	int i = 0;
	while (i < n*m)
	{
		if (t[i] != nullptr)
			if(t[i]->getPolozenie() == polozenie)
				return t[i];
		i++;
	}
	return nullptr;
}

void Swiat::sortuj()
{
	for (int i = 0; i < n * m; i++)
	{
		for (int j = 1; j < n * m - i; j++)
		{
			if (t[j - 1] == nullptr || t[j] == nullptr)
				continue;
			if (t[j - 1]->getInicjatywa() < t[j]->getInicjatywa())
			{
				swap(t[j - 1], t[j]);
			}
			else if (t[j - 1]->getInicjatywa() == t[j]->getInicjatywa())
			{
				if(t[j-1]->getDlugoscZycia() > t[j]->getDlugoscZycia())
					swap(t[j - 1], t[j]);
			}
		}
	}
}

void Swiat::zapis(Czlowiek* czlowiek)
{
	system("CLS");
	string s;
	cout << "Podaj nazwe pliku do zapisu\n";
	cin >> s;
	s += "\0";
	char* z = new char[s.length()+1];
	for (int i = 0; i < s.length(); i++)
		z[i] = s[i];
	z[s.length()] = '\0';
	FILE* plik1 = fopen(z, "w");
	fclose(plik1);
	fstream plik;
	plik.open(z, ios::out);
	if (plik.good())
	{
		plik << n << " " << m << endl;
		for (int i = 0; i < n * m; i++)
		{
			string nazwa = t[i]->rozpoznanieOrg();
			if (nazwa != "Czlowiek" && nazwa != "")
				plik << nazwa << " " << t[i]->getSila() << " " << t[i]->getInicjatywa() << " " << t[i]->getPolozenie().x << " " << t[i]->getPolozenie().y << " " << t[i]->getDlugoscZycia() << endl;
			else if(nazwa == "Czlowiek")
				plik << nazwa << " " << t[i]->getSila() << " " << t[i]->getInicjatywa() << " " << t[i]->getPolozenie().x << " " << t[i]->getPolozenie().y << " " << t[i]->getDlugoscZycia() << " " << czlowiek->getCooldown() << endl;
		}
		plik.close();
	}
	else
		cout << "BLAD";
	
	//wymiary planszy
	//organizmy sila, inicjatywa, pol.x, pol.y, dlugosc_zycia (cooldown)
}

void Swiat::odczyt(Czlowiek** czlowiek)
{
	system("CLS");
	string s;
	cout << "Podaj nazwe pliku do odczytu\n";
	cin >> s;
	s += "\0";
	char* z = new char[s.length() + 1];
	for (int i = 0; i < s.length(); i++)
		z[i] = s[i];
	z[s.length()] = '\0';
	
	fstream plik;
	plik.open(z, ios::in);
	if (plik.good())
	{
		delete[]t;
		for (int i = 0; i < n; i++)
			delete[]tab[i];
		delete[]tab;
		int sila, inicjatywa, dlugoscZycia, cooldown;
		Para polozenie;
		Organizm* tmp = nullptr;
		plik >> n >> m;
		t = new Organizm * [n * m];
		for (int i = 0; i < n * m; i++)
			t[i] = nullptr;
		tab = new char* [n];
		for (int i = 0; i < n; i++)
		{
			tab[i] = new char[m];
			for (int j = 0; j < m; j++)
				tab[i][j] = ' ';
		}
		
		for (int j = 0; j < n * m; j++)
		{
			string nazwa;
			plik >> nazwa;
			if(nazwa == "Barszcz" || nazwa == "Wilcze")
				plik >> nazwa;
			plik >> sila >> inicjatywa >> polozenie.x >> polozenie.y >> dlugoscZycia;
			if (nazwa == "Czlowiek")
			{
				plik >> cooldown;
				*czlowiek = new Czlowiek(sila, inicjatywa, polozenie, *this, dlugoscZycia, cooldown);
				tmp = *czlowiek;
			}
			else if (nazwa == "Antylopa")
				tmp = new Antylopa(sila, inicjatywa, polozenie, *this, dlugoscZycia);
			else if (nazwa == "Sosnowskiego")
				tmp = new BarszczSosnowskiego(polozenie, *this, dlugoscZycia);
			else if (nazwa == "Guarana")
				tmp = new Guarana(polozenie, *this, dlugoscZycia); 
			else if (nazwa == "Lis")
				tmp = new Lis(sila, inicjatywa, polozenie, *this, dlugoscZycia);
			else if (nazwa == "Mlecz")
				tmp = new Mlecz(polozenie, *this, dlugoscZycia);
			else if (nazwa == "Owca")
				tmp = new Owca(sila, inicjatywa, polozenie, *this, dlugoscZycia);
			else if (nazwa == "Trawa")
				tmp = new Trawa(polozenie, *this, dlugoscZycia);
			else if (nazwa == "Jagody")
				tmp = new WilczeJagody(polozenie, *this, dlugoscZycia);
			else if (nazwa == "Wilk")
				tmp = new Wilk(sila, inicjatywa, polozenie, *this, dlugoscZycia);
			else if (nazwa == "Zolw")
				tmp = new Zolw(sila, inicjatywa, polozenie, *this, dlugoscZycia);
			setOrganizm(tmp);
		}
		plik.close();

		Para pol;
		for (int i = 0; i < n * m; i++)
		{
			if (t[i] != nullptr)
			{
				pol = t[i]->getPolozenie();
				if (0 <= pol.x && pol.x < n && 0 <= pol.y && pol.y < m)
					tab[pol.x][pol.y] = t[i]->rysowanie();
			}
		}
	}
	else
		cout << "BLAD";
}