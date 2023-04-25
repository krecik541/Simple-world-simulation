#pragma once
#include "Zwierze.h"
class Antylopa :
    public Zwierze
{
public:
    Antylopa(Para polozenie, Swiat& swiat);
    Antylopa(Para polozenie, Swiat& swiat, int dlugoscZycia);
    Antylopa(int sila, int inicjatywa, Para polozenie, Swiat& swiat, int dlugosc_zycia);
    void akcja() override;
    char rysowanie() override;
    int kolizja(Organizm* org) override;
    void rozmnazanie() override;
};

