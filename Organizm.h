#pragma once
#include<string>
#include<iostream>
#include"Swiat.h"
#include"Para.h"

//STANY KOLIZJI
#define ODPIERANIE_ATAKU 0
#define ROZMNAZANIE 0
#define WYGRYWA_ATAKUJACY 1
#define WYGRYWA_BRONIACY 2
#define UCIECZKA1 3
#define UCIECZKA2 4
#define OBA_GINA 5
#define PUSTE 6


using namespace std;

class Swiat;
class Zwierze;
class Organizm;

class Organizm
{
protected:
	int sila;
	int inicjatywa;
	Para polozenie;
	Swiat& swiat;
	int dlugosc_zycia;
public:
	virtual ~Organizm();
	Organizm(int sila, int inicjatywa, Para polozenie, Swiat& swiat, int dlugosc_zycia);
	virtual void akcja() = 0;
	virtual int kolizja(Organizm* org) = 0;
	virtual char rysowanie() = 0;
	virtual void rozmnazanie() = 0;

	virtual int getSila();
	virtual void setSila(int sila);
	virtual int getInicjatywa();
	virtual void setInicjatywa(int inicjatywa);
	virtual Para getPolozenie();
	virtual void setPolozenie(Para polzenie);
	virtual Swiat& getSwiat();
	virtual void setSwiat(Swiat& swiat);
	virtual int getDlugoscZycia();
	virtual void setDlugoscZycia();
	virtual Para szukajPozycji(Para polozenie); 
	string rozpoznanieOrg();//rosliny
};

