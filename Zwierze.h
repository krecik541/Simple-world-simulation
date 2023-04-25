#pragma once
#include "Organizm.h"
//KIERUNKI RUCHU
#define GORA 0
#define LEWO 1
#define DOL 2
#define PRAWO 3


class Zwierze : public Organizm
{
public:
    Zwierze(int sila, int inicjatywa, Para polozenie, Swiat& swiat);
    Zwierze(int sila, int inicjatywa, Para polozenie, Swiat& swiat, int dlugosc_zycia);
    virtual void akcja() override;
    void rozmnazanie() override;
    int kolizja(Organizm* org) override;
};

