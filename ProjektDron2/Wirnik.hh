#ifndef PROJEKTDRON_WIRNIK_HH
#define PROJEKTDRON_WIRNIK_HH

#include "Szesciakat.hh"
/*!
 * \file Wirnik.hh
 * Zawiera przepis na stworzenie wirnika
 */

/*!
 * \brief Klasa Wirnik zawiera pola i metody potrzebne do stworzenia wirnika w gnuplocie
 */

class Wirnik :public Szesciakat
{
protected:
public:
    /*!
     * Konstruktor bezparametryczny dla Wirnika
     */
    Wirnik() {};
    /*!
     * Konstruktor dla Wirnika
     * \param api - wskaznik na scene
     * \param Srodek_Wirnik - Srodek Wirnika
     */
    Wirnik(std::shared_ptr<drawNS::Draw3DAPI> api, Wektor<double, 3> Srodek_Wirnik);
    /*!
     * Metoda na obroty wirnika  w trakcie poruszania sie drona
     * \param Ob - orientacja korpusu drona
     * \param W - punkt srodka wirnika w danym momencie
     * \param kat - kat obrotu wirnika
     */
    void Obroty (Macierz_Obrotu Ob, Wektor<double,3> W,double kat);
};

Wirnik::Wirnik(std::shared_ptr<drawNS::Draw3DAPI> api, Wektor<double, 3> Srodek_Wirnik)
{
    Wsk_API = api;
    Wierzcholki2[0] = Wektor<double, 3>(-1.5+Srodek_Wirnik[0], 0.5+Srodek_Wirnik[1], 0+Srodek_Wirnik[2]);
    Wierzcholki2[1] = Wektor<double, 3>(-0.5+Srodek_Wirnik[0], 0.5+Srodek_Wirnik[1], 1+Srodek_Wirnik[2]);
    Wierzcholki2[2] = Wektor<double, 3>(0.5+Srodek_Wirnik[0], 0.5+Srodek_Wirnik[1], 1+Srodek_Wirnik[2]);
    Wierzcholki2[3] = Wektor<double, 3>(1.5+Srodek_Wirnik[0], 0.5+Srodek_Wirnik[1], 0+Srodek_Wirnik[2]);
    Wierzcholki2[4] = Wektor<double, 3>(0.5+Srodek_Wirnik[0], 0.5+Srodek_Wirnik[1], -1+Srodek_Wirnik[2]);
    Wierzcholki2[5] = Wektor<double, 3>(-0.5+Srodek_Wirnik[0], 0.5+Srodek_Wirnik[1], -1+Srodek_Wirnik[2]);
    Wierzcholki2[6] = Wektor<double, 3>(-1.5+Srodek_Wirnik[0], -0.5+Srodek_Wirnik[1], 0+Srodek_Wirnik[2]);
    Wierzcholki2[7] = Wektor<double, 3>(-0.5+Srodek_Wirnik[0], -0.5+Srodek_Wirnik[1], 1+Srodek_Wirnik[2]);
    Wierzcholki2[8] = Wektor<double, 3>(0.5+Srodek_Wirnik[0], -0.5+Srodek_Wirnik[1], 1+Srodek_Wirnik[2]);
    Wierzcholki2[9] = Wektor<double, 3>(1.5+Srodek_Wirnik[0], -0.5+Srodek_Wirnik[1], 0+Srodek_Wirnik[2]);
    Wierzcholki2[10] = Wektor<double, 3>(0.5+Srodek_Wirnik[0], -0.5+Srodek_Wirnik[1], -1+Srodek_Wirnik[2]);
    Wierzcholki2[11] = Wektor<double, 3>(-0.5+Srodek_Wirnik[0], -0.5+Srodek_Wirnik[1], -1+Srodek_Wirnik[2]);
}

// NIE DZIALA
void Wirnik::Obroty(Macierz_Obrotu Ob, Wektor<double,3> W,double kat)
{
    Orientacja = Ob;
    Srodek = W;
    //std::cout << Srodek << std::endl <<Orientacja;
    RotujY(kat);
}


#endif //PROJEKTDRON_WIRNIK_HH
