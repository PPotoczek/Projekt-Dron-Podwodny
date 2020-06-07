#pragma once
#ifndef PROJEKTDRON_BRYLA_HH
#define PROJEKTDRON_BRYLA_HH
#include<iostream>
#include "Macierz_Obrotu.hh"
#include "Interfejs_rysowania.hh"

/*!
 * \file Bryla.hh
 * Zawiera przepis na tworzenie bryly
 */

/*!
 * \brief Klasa Bryla zawiera pola i metody potrzebne do stworzenia, narysowania, obrocenia bryly w gnuplocie.
 */

class Bryla :public Interfejs_rys
{
protected:
    /*!
     * Orientacja - Macierz Obrotu zawierejaca orientacje obiektu
     * Srodek - Wektor 3x1 zawierajacy wspolrzedne srodka obiektu, Poczatkowo ustawiony na (0,0,0) dla kazdego obiektu
     * id - zawiera id obiektu
     * IloscBrylUtworzonych - ilosc utworzonych bryl
     * IloscBrylIstniejacych - ilosc istniejacych bryl
     */
    Macierz_Obrotu Orientacja;
    Wektor<double, 3> Srodek;
    int id;
    inline static int IloscBrylUtworzonych=0;
    inline static int IloscBrylIstniejacych=0;
public:
    /*!
     * \brief Bezparametryczny konstruktor dla bryly
     */
    Bryla();
    /*!
     * \brief Destruktor dla bryly
     */
     ~Bryla();
     /*!
      * \brief Konstruktor kopiujacy dla bryly
      * \param nowa - obiekt ktory bedzie kopiowany
      */
     Bryla(const Bryla &nowa);
    /*!
     * \brief Metoda w klasach pochodnych opisuje jak na scenie narysowac dany obiekt
     */
    virtual void Rysuj() =0;
    /*!
     * \brief Metoda w klasach pochodnych opisuje jak wymazac dany obiekt ze sceny
     */
    virtual void Czysc() =0;
    /*!
     *  Metoda opisuje ruch obiektu na scenie
     * \param W - kierunek w ktorym porusza sie obiekt
     * \param odleglosc - odleglosc na jaka chcemy przesunac obiekt
     */
    void Ruch(const Wektor<double, 3> &W, double odleglosc);
    /*!
     * Metoda konwertuje Wektor na punkt
     * \param Punkt - Wektor ze wspolrzednymi punktu
     * \return Punkt - funkcja zwraca punkt rusowalny w gnuplocie
     */
    drawNS::Point3D Wektor_na_punkt(Wektor<double, 3> &Punkt);
    /*!
     * Metoda opisuje jak obrocic obiekt w osi OX
     * \param kat - kat o jaki chcemy obrocic obiekt
     */
    void RotujX(double kat);
    /*!
     * Metoda opisuje jak obrocic obiekt w osi OY
     * \param kat - kat o jaki chcemy obrocic obiekt
     */
    void RotujY(double kat);
    /*!
     * Metoda opisuje jak obrocic obiekt w osi OZ
     * \param kat - kat o jaki chcemy obrocic obiekt
     */
    void RotujZ(double kat);
    /*!
     * Funkcja statyczna zwracajaca ilosc utworzonych bryl
     */
    static int GetUtworzone();
    /*!
     * Funkcja statyczna zwracajaca ilosc istniejacych bryl
     */
    static int GetIstniejace();
};

Bryla::Bryla()
{
    IloscBrylUtworzonych++;
    IloscBrylIstniejacych++;
}

Bryla::~Bryla()
{
    IloscBrylIstniejacych--;
}

Bryla::Bryla(const Bryla &nowa)
{
    IloscBrylUtworzonych++;
    IloscBrylIstniejacych++;
}

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

void Bryla:: RotujX(double kat)
{
    Macierz_Obrotu Pom = Macierz_Obrotu('x',kat);
    Orientacja = Orientacja*Pom;
}

void Bryla:: RotujY(double kat)
{
    Macierz_Obrotu Pom = Macierz_Obrotu('y',kat);
    Orientacja = Orientacja*Pom;
}

void Bryla:: RotujZ(double kat)
{
    Macierz_Obrotu Pom = Macierz_Obrotu('z',kat);
    Orientacja = Orientacja*Pom;
}

int Bryla::GetUtworzone()
{
    return IloscBrylUtworzonych;
}

int Bryla::GetIstniejace()
{
    return IloscBrylIstniejacych;
}

#endif