#pragma once
#include "Zwierze.h"
class Owca : public Zwierze
{
public:
    Owca(Para polozenie, Swiat& swiat);
    Owca(Para polozenie, Swiat& swiat, int dlugoscZycia);
    Owca(int sila, int inicjatywa, Para polozenie, Swiat& swiat, int dlugosc_zycia);
    char rysowanie() override;
    void rozmnazanie() override;
};

