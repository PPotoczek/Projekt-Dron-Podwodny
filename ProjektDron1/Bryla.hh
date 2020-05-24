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
     */
    Macierz_Obrotu Orientacja;
    Wektor<double, 3> Srodek= Wektor<double, 3>(0,0,0);
    int id;
public:
    /*!
     * \brief Konstruktor dla bryly
     * \param api - wskaznik na scene
     */
    Bryla(std::shared_ptr<drawNS::Draw3DAPI> api);
    /*!
     * \brief Bezparametryczny konstruktor dla bryly
     */
    Bryla() {};
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
};

Bryla::Bryla(std::shared_ptr<drawNS::Draw3DAPI> api)
{
    Wsk_API = api;
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

#endif