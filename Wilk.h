#pragma once
#include "Zwierze.h"
class Wilk : public Zwierze
{
public:
    Wilk(Para polozenie, Swiat& swiat);
    Wilk(Para polozenie, Swiat& swiat, int dlugoscZycia);
    Wilk(int sila, int inicjatywa, Para polozenie, Swiat& swiat, int dlugosc_zycia);
    char rysowanie() override;
    void rozmnazanie() override;
};

