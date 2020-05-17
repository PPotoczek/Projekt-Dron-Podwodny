#include<iostream>
#include "Macierz_Obrotu.hh"
#include "Wektor3D.hh"
#include "Interfejs rysowania.h"

class Bryla :public Interfejs_rys
{
protected:
    Macierz_Obrotu Orientacja;
    Wektor<double, 3> Srodek= Wektor<double, 3>(0,0,0);
    int id;
public:
 virtual void Rysuj() =0;
 virtual void Czysc() =0;
 //virtual void Inicjalizuj()=0;
 //virtual void Rotuj(Macierz_Obrotu & M_Ob) = 0;
 void Ruch(const Wektor<double, 3> &W, double odleglosc);
 drawNS::Point3D Wektor_na_punkt(Wektor<double, 3> &Punkt);
 //void UstawWskaznik(drawNS::Draw3DAPI * api);
};

void Bryla::Ruch(const Wektor<double, 3> &W, double odleglosc)
{
    Wektor<double, 3> WPom = Orientacja*W;
    Srodek = Srodek + WPom*odleglosc;
}

drawNS::Point3D Bryla::Wektor_na_punkt(Wektor<double, 3> &Punkt)
{
    drawNS::Point3D P = drawNS::Point3D(Punkt[0], Punkt[1], Punkt[2]);
    return P;
}

//void Bryla::UstawWskaznik(drawNS::Draw3DAPI * api)
//{
//    Wsk_API
//}

