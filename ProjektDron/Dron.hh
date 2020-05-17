#ifndef PROJEKTDRON_DRON_HH
#define PROJEKTDRON_DRON_HH

#include "Prostopadloscian.hh"

class Dron :public Prostopadloscian
{
protected:
    Prostopadloscian D;
public:
    Dron() {};
    //void Rysuj();
    void Przod(double odleglosc);
    void Tyl(double odleglosc);
    void Gora(double odleglosc);
    void Dol(double odleglosc);
};



void Dron::Przod(double odleglosc)
{
    double dlugosc = odleglosc/100;
    Wektor<double, 3> W = Wektor<double, 3>(1,0,0);
    for(int i=0;i<100;i++)
    {
        D.Ruch(W,dlugosc);
        D.Rysuj();
        //D.Czysc();
    }
}

void Dron::Tyl(double odleglosc)
{
    double dlugosc = odleglosc/100;
    Wektor<double, 3> W = Wektor<double, 3>(-1,0,0);
    for(int i=0;i<100;i++)
    {
        D.Ruch(W,dlugosc);
        D.Rysuj();
        D.Czysc();
    }
}

void Dron::Gora(double odleglosc)
{
    double dlugosc = odleglosc/100 ;
    Wektor<double, 3> W = Wektor<double, 3>(0,0,1);
    for(int i=0;i<100;i++)
    {
        D.Ruch(W,dlugosc);
        D.Rysuj();
        D.Czysc();
    }
}

void Dron::Dol(double odleglosc)
{
    double dlugosc = odleglosc/100;
    Wektor<double, 3> W = Wektor<double, 3>(0,0,-1);
    for(int i=0;i<100;i++)
    {
        D.Ruch(W, dlugosc);
        D.Rysuj();
        D.Czysc();
    }
}

#endif //PROJEKTDRON_DRON_HH
