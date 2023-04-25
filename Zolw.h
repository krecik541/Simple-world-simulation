#pragma once
#include "Zwierze.h"
class Zolw :
    public Zwierze
{
public:
    Zolw(Para polozenie, Swiat& swiat);
    Zolw(Para polozenie, Swiat& swiat, int dlugoscZycia);
    Zolw(int sila, int inicjatywa, Para polozenie, Swiat& swiat, int dlugosc_zycia);
    void akcja() override;
    int kolizja(Organizm* org) override;
    char rysowanie() override;
    void rozmnazanie() override;
};

