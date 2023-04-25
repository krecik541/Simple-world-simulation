#pragma once
#include "Zwierze.h"

class Lis : public Zwierze
{
public:
    Lis(Para polozenie, Swiat& swiat);
    Lis(Para polozenie, Swiat& swiat, int dlugoscZycia);
    Lis(int sila, int inicjatywa, Para polozenie, Swiat& swiat, int dlugosc_zycia);
    char rysowanie() override;
    void akcja() override;
    void rozmnazanie() override;
};

