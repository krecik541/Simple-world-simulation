#include <iostream>
#include"Swiat.h"
#include"BarszczSosnowskiego.h"
#include"Owca.h"
#include"Trawa.h"
#include"Zolw.h"
#include"Antylopa.h"
#include"Czlowiek.h"
#include<string>
#include<Windows.h>
#include<conio.h>
//antylopa->akcja
using namespace std;

int main()
{
    srand(time(NULL));
    char zn = ' ';
    int n, m;
    double zapelnienie;
    bool czlowiekzyje = true;
    cout << "Podaj wymiary planszy: \n";
    cin >> n >> m;
    cout << "Podaj zapelnienie (zakres 0-1): \n";
    cin >> zapelnienie;
    Swiat swiat(n, m, zapelnienie);
    Organizm* tmp;
    Czlowiek *czlowiek = new Czlowiek({ 0,0 }, swiat);
    tmp = czlowiek;
    swiat.setOrganizm(tmp);
    swiat.rysujSwiat();
    while (1)
    {
        zn = _getch();
        if (zn == 'q')
            break;
        else if (zn == 'u' && czlowiek->getCooldown() == 0 && czlowiekzyje)
        {
            czlowiek->umiejetnosc();
            system("CLS");
            swiat.rysujSwiat();
            cout << "Cooldown umiejetnosci " << czlowiek->getCooldown() << endl;
            cout << "Sila Czlowieka " << czlowiek->getSila() << endl;
        }
        else if (zn == 's')
        {
            swiat.zapis(czlowiek);
            system("CLS");
            cout << "ZAPISANO POMYSLNIE\n";
            swiat.rysujSwiat();
        }
        else if (zn == 'l')
        {
            swiat.odczyt(&czlowiek);
            system("CLS");
            cout << "ODCZYTANO POMYSLNIE\n";
            swiat.rysujSwiat();
        }
        else if (zn == -32)
        {
            zn = _getch();
            switch (zn)
            {
            case 72:
            {
                czlowiek->setRuch(GORA);
                break;
            }
            case 80:
            {
                czlowiek->setRuch(DOL);
                break;
            }
            case 75:
            {
                czlowiek->setRuch(LEWO);
                break;
            }
            case 77:
            {
                czlowiek->setRuch(PRAWO);
                break;
            }
            }
            swiat.wykonajTure();
            czlowiekzyje = swiat.rysujSwiat();
            
        }
        if (czlowiekzyje)
        {
            cout << "Cooldown umiejetnosci " << czlowiek->getCooldown() << endl;
            cout << "Sila Czlowieka " << czlowiek->getSila() << endl;
        }
        
        
    }
    return 0;
}