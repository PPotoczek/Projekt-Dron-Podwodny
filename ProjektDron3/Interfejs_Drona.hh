#ifndef PROJEKTDRON_INTERFEJS_DRONA_HH
#define PROJEKTDRON_INTERFEJS_DRONA_HH

/*!
 * \file Interfejs_Drona.hh
 * Zawiera Interfejs drona
 */

/*!
 * \brief Klasa Interfejs drona jest abstrakcyjna klasa, ktora zawiera wirtualne metody
 */

class Interfejs_Drona
{
public:
    /*!
     * \brief Metoda zwracajaca srodek drona
     */
    virtual Wektor<double, 3> getSrodek() = 0;
};

#endif