#ifndef PROJEKTDRON_DRON_HH
#define PROJEKTDRON_DRON_HH

#include "Prostopadloscian.hh"
#include "Interfejs_Drona.hh"
#include "Wirnik.hh"
#include "Przeszkoda.hh"

/*!
 * \file Dron.hh
 * Zawiera przepis na drona
 */

/*!
 * Klasa dron zawiera pola i metody potrzebne do stworzenia drona w gnuplocie
 */

class Dron :public Prostopadloscian, public Przeszkoda, public Interfejs_Drona
{
protected:
    /*!
     * D - prostopadloscian, korpus drona
     * Pozycja1 - pozycja pierwszego wirnika
     * Pozycja2 - pozycja drugiego wirnika
     * P - prawy wirnik
     * L - lewy wirnik
     */
    Prostopadloscian D;
    Wektor<double, 3> Pozycja1;// = Wektor<double, 3>(1.5,-2.5,0);
    Wektor<double, 3> Pozycja2;// = Wektor<double, 3>(-1.5,-2.5,0);
    Wirnik P;
    Wirnik L;
public:
    /*!
     * Konstruktor dla drona
     * \param api - wskaznik na scene
     */
    Dron(std::shared_ptr<drawNS::Draw3DAPI> api,Wektor<double,3> Srodek);
    /*!
     * Bezparametryczny konstruktor dla drona
     */
    Dron() {};
    /*!
     * Metoda na poruszanie sie, animacje poruszania sie drona w gnuplocie
     * \param odleglosc - odleglosc na jaka chcemy przemiescic drona
     */
    void Przod(double odleglosc, std::vector<std::shared_ptr<Przeszkoda> > &kolekcja_przeszkod);
    /*!
     * Metoda na poruszanie sie, animacje poruszania sie drona do tylu w gnuplocie
     * \param odleglosc - odleglosc na jaka chcemy przemiescic drona
     */
    void Tyl(double odleglosc);
    /*!
     * Metoda na wynuzanie/zanuzanie drona
     * \param kat - kat pod jakim chcemy aby nasz dron sie wynuzyl/zanuzyl
     * \param odleglosc - odleglosc na jaka chemy przemiscic drona
     */
    void Gora(double kat, double odleglosc);
    /*!
     * Metoda na wynuzanie/zanuzanie drona do tylu
     * \param kat - kat pod jakim chcemy aby nasz dron sie wynuzyl/zanuzyl
     * \param odleglosc - odleglosc na jaka chemy przemiscic drona
     */
    void Dol(double kat, double odleglosc);
    /*!
     * Metoda na Rotacje drona wokol roznych osi, w naszym przypadku x,y lub z
     * \param os - os wokol ktorej chcemy obrocic drona
     * \param kat - kat o jaki chcemy obrocic drona
     */
    void Rotacja(char os, double kat);
    bool Kolizja(Interfejs_Drona *D) {};
    Wektor<double, 3> getSrodek();
};

Dron::Dron(std::shared_ptr<drawNS::Draw3DAPI> api,Wektor<double,3> Srodek)
{
    Wsk_API = api;
    D = Prostopadloscian(api,Srodek);
    Pozycja1 = Wektor<double,3>(1.5+Srodek[0],-2.5+Srodek[1],0+Srodek[2]);
    Pozycja2 = Wektor<double,3>(-1.5+Srodek[0],-2.5+Srodek[1],0+Srodek[2]);
    P = Wirnik(api,Pozycja1);
    L = Wirnik(api, Pozycja2);
    D.Rysuj();
    P.Rysuj();
    L.Rysuj();
}

void Dron::Przod(double odleglosc, std::vector<std::shared_ptr<Przeszkoda> > &kolekcja_przeszkod)
{
    double dlugosc = odleglosc/100;
    //double kat = 15;
    Wektor<double, 3> W = Wektor<double, 3>(0,1,0);
    for(int i=0;i<100;i++)
    {
        /*
        for (int i=0;i<kolekcja_przeszkod.size();++i)
        {
            kolekcja_przeszkod[i]->Kolizja(static_cast<Interfejs_Drona *>(this));
        }
         */
        L.Czysc();
        P.Czysc();
        D.Czysc();
        L.Ruch(W,dlugosc);
        //L.Obroty(Orientacja,Pozycja1+Orientacja*Srodek,kat);
        P.Ruch(W,dlugosc);
        //P.Obroty(Orientacja,Srodek+Orientacja*Pozycja2,kat);
        D.Ruch(W,dlugosc);
        L.Rysuj();
        P.Rysuj();
        D.Rysuj();
        //kat=kat+15;
        //std::cout << Srodek <<std::endl;
    }
}

void Dron::Tyl(double odleglosc)
{
    double dlugosc = odleglosc/100;
    Wektor<double, 3> W = Wektor<double, 3>(0,-1,0);
    for(int i=0;i<100;i++)
    {
        L.Czysc();
        P.Czysc();
        D.Czysc();
        L.Ruch(W,dlugosc);
        P.Ruch(W,dlugosc);
        D.Ruch(W,dlugosc);
        L.Rysuj();
        P.Rysuj();
        D.Rysuj();
    }
}

void Dron::Gora(double kat, double odleglosc)
{
    Rotacja('x',kat);
    double dlugosc = odleglosc/100 ;
    Wektor<double, 3> W = Wektor<double, 3>(0,1,0);
    for(int i=0;i<100;i++)
    {
        L.Czysc();
        P.Czysc();
        D.Czysc();
        L.Ruch(W,dlugosc);
        P.Ruch(W,dlugosc);
        D.Ruch(W,dlugosc);
        L.Rysuj();
        P.Rysuj();
        D.Rysuj();
    }
    Rotacja('x',-kat);
}

void Dron::Dol(double kat,double odleglosc)
{
    Rotacja('x',kat);
    double dlugosc = odleglosc/100 ;
    Wektor<double, 3> W = Wektor<double, 3>(0,-1,0);
    for(int i=0;i<100;i++)
    {
        L.Czysc();
        P.Czysc();
        D.Czysc();
        L.Ruch(W,dlugosc);
        P.Ruch(W,dlugosc);
        D.Ruch(W,dlugosc);
        L.Rysuj();
        P.Rysuj();
        D.Rysuj();
    }
    Rotacja('x',-kat);
}

void Dron::Rotacja(char os,double kat)
{
    double kat_pom = kat/100;
    switch(os)
    {
        case 'x':
        {
            for(int i=0;i<100;i++)
            {
                L.Czysc();
                P.Czysc();
                D.Czysc();
                L.RotujX(kat_pom);
                P.RotujX(kat_pom);
                D.RotujX(kat_pom);
                L.Rysuj();
                P.Rysuj();
                D.Rysuj();
            }
            break;
        }
        case 'y':
        {
            for(int i=0;i<100;i++)
            {
                L.Czysc();
                P.Czysc();
                D.Czysc();
                L.RotujY(kat_pom);
                P.RotujY(kat_pom);
                D.RotujY(kat_pom);
                L.Rysuj();
                P.Rysuj();
                D.Rysuj();
            }
            break;
        }
        case 'z':
        {
            for(int i=0;i<100;i++)
            {
                L.Czysc();
                P.Czysc();
                D.Czysc();
                L.RotujZ(kat_pom);
                P.RotujZ(kat_pom);
                D.RotujZ(kat_pom);
                L.Rysuj();
                P.Rysuj();
                D.Rysuj();
            }
            break;
        }
    }
}

Wektor<double, 3> Dron::getSrodek()
{
    return Srodek;
}


#endif //PROJEKTDRON_DRON_HH
