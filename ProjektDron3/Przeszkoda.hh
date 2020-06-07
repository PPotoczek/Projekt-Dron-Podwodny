#ifndef PROJEKTDRON_PRZESZKODA_HH
#define PROJEKTDRON_PRZESZKODA_HH

#include <iostream>
#include "Dron.hh"

/*!
 * \file Przeszkoda.hh Zawiera przepis na przeszkode
 */

/*!
 * \brief Klasa Przeszkoda jest abstrakcyjna klasa, ktora zawiera wirtualne metody
 */


class Przeszkoda
{
public:
    /*!
     * \brief Bezparametryczny Konstruktor przeszkody
     */
    Przeszkoda() {};
    drawNS::Point3D Wektor_na_punkt(Wektor<double, 3> &Punkt);
    /*!
     * \brief Metoda do wykrywania kolizji pomiedzy objektami
     * \param D - wskaznik na drona
     */
    virtual bool Kolizja(Interfejs_Drona *D) =0;
};

drawNS::Point3D Przeszkoda::Wektor_na_punkt(Wektor<double, 3> &Punkt)
{
    drawNS::Point3D P = drawNS::Point3D(Punkt[0], Punkt[1], Punkt[2]);
    return P;
}


#endif
