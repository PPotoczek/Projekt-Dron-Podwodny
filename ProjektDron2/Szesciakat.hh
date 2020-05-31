#pragma once
#ifndef PROJEKTDRON_SZESCIAKAT_HH
#define PROJEKTDRON_SZESCIAKAT_HH

#include "Bryla.hh"

/*!
 * \file Szesciakat.hh Zawiera przepis na stworzenie szesciakatu
 */

/*!
 * \brief Klasa Szesciakat zawiera pola i metody potrzebne do stworzenia szesciakatu w gnuplocie
 */

class Szesciakat: public Bryla
{
protected:
    /*!
     * Wierzcholki2 - tablica wektorow zawierajaca wspolrzedne wierzcholkow szesciakata
     */
    Wektor<double, 3>Wierzcholki2[12];
public:
    /*!
     * \brief Konstruktor dla Szesciakata
     * \param api - wskaznik na scene
     * \param Srodek_Wirnik - Srodek Szesciakata (nazwany tak poniewaz narazie wykorzystuje go tylko do tworzenia wirnikow )
     */
    Szesciakat(std::shared_ptr<drawNS::Draw3DAPI> api, Wektor<double, 3> Srodek_Wirnik);
    /*!
     * \brief Bezparametryczny konstruktor dla Szesciakata
     */
    Szesciakat() {};
    void Rysuj() override;
    void Czysc() override;

};

Szesciakat::Szesciakat(std::shared_ptr<drawNS::Draw3DAPI> api, Wektor<double, 3> Srodek_Wirnik)
{
    Wsk_API = api;
    Wierzcholki2[0] = Wektor<double, 3>(-2+Srodek_Wirnik[0], -2+Srodek_Wirnik[1], 1+Srodek_Wirnik[2]);
    Wierzcholki2[1] = Wektor<double, 3>(-1+Srodek_Wirnik[0], -2+Srodek_Wirnik[1], 1+Srodek_Wirnik[2]);
    Wierzcholki2[2] = Wektor<double, 3>(0+Srodek_Wirnik[0], -2+Srodek_Wirnik[1], 0+Srodek_Wirnik[2]);
    Wierzcholki2[3] = Wektor<double, 3>(-1+Srodek_Wirnik[0], -2+Srodek_Wirnik[1], -1+Srodek_Wirnik[2]);
    Wierzcholki2[4] = Wektor<double, 3>(-2+Srodek_Wirnik[0], -2+Srodek_Wirnik[1], -1+Srodek_Wirnik[2]);
    Wierzcholki2[5] = Wektor<double, 3>(-3+Srodek_Wirnik[0], -2+Srodek_Wirnik[1], 0+Srodek_Wirnik[2]);
    Wierzcholki2[6] = Wektor<double, 3>(-2+Srodek_Wirnik[0], -3+Srodek_Wirnik[1], 1+Srodek_Wirnik[2]);
    Wierzcholki2[7] = Wektor<double, 3>(-1+Srodek_Wirnik[0], -3+Srodek_Wirnik[1], 1+Srodek_Wirnik[2]);
    Wierzcholki2[8] = Wektor<double, 3>(0+Srodek_Wirnik[0], -3+Srodek_Wirnik[1], 0+Srodek_Wirnik[2]);
    Wierzcholki2[9] = Wektor<double, 3>(-1+Srodek_Wirnik[0], -3+Srodek_Wirnik[1], -1+Srodek_Wirnik[2]);
    Wierzcholki2[10] = Wektor<double, 3>(-2+Srodek_Wirnik[0], -3+Srodek_Wirnik[1], -1+Srodek_Wirnik[2]);
    Wierzcholki2[11] = Wektor<double, 3>(-3+Srodek_Wirnik[0], -3+Srodek_Wirnik[1], 0+Srodek_Wirnik[2]);
}

void Szesciakat::Rysuj()
{
    Wektor<double,3> Pom[12];
    for(int i=0;i<12;i++)
    {
        Pom[i] = Srodek + Orientacja*Wierzcholki2[i];
    }

    drawNS::Point3D W1 = Wektor_na_punkt(Pom[0]);
    drawNS::Point3D W2 = Wektor_na_punkt(Pom[1]);
    drawNS::Point3D W3 = Wektor_na_punkt(Pom[2]);
    drawNS::Point3D W4 = Wektor_na_punkt(Pom[3]);
    drawNS::Point3D W5 = Wektor_na_punkt(Pom[4]);
    drawNS::Point3D W6 = Wektor_na_punkt(Pom[5]);
    drawNS::Point3D W7 = Wektor_na_punkt(Pom[6]);
    drawNS::Point3D W8 = Wektor_na_punkt(Pom[7]);
    drawNS::Point3D W9 = Wektor_na_punkt(Pom[8]);
    drawNS::Point3D W10 = Wektor_na_punkt(Pom[9]);
    drawNS::Point3D W11 = Wektor_na_punkt(Pom[10]);
    drawNS::Point3D W12 = Wektor_na_punkt(Pom[11]);
    id = Wsk_API->draw_polyhedron(std::vector<std::vector<drawNS::Point3D> > {{
                                                                                     W1,W2,W3,W4,W5,W6
                                                                             },{
                                                                                     W7,W8,W9,W10,W11,W12
                                                                             }},"red");
    Wsk_API->redraw();
}

void Szesciakat::Czysc()
{
    Wsk_API->erase_shape(id);
}


#endif //PROJEKTDRON_SZESCIAKAT_HH
