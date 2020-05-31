#ifndef PROJEKTDRON_POWIERZCHNIA_HH
#define PROJEKTDRON_POWIERZCHNIA_HH

#include<iostream>
#include "Interfejs_rysowania.hh"
/*!
 * \file Powierzchnia.hh
 * Zawiera przepis na tworzenie powierzchni
 */

/*!
 * \brief klasa Powierzchnia zawiera metody do stworzenia powierzchni
 */

class Powierzchnia :public Interfejs_rys
{
public:
    /*!
     * \brief Konstruktor dla powierzchni
     * \param api - wskaznik na scene
     */
    Powierzchnia(std::shared_ptr<drawNS::Draw3DAPI> api);
    /*!
     * \brief Metoda Pow tworzy powierzchnie na scenie
     * \param poziom - poziom na jakim tworzona jest powierzchnia
     */
    void Pow(double poziom);
};

Powierzchnia::Powierzchnia(std::shared_ptr<drawNS::Draw3DAPI> api)
{
    Wsk_API = api;
}

void Powierzchnia::Pow(double poziom)
{
    for(int i=-10;i<100;i=i+3)
    {
        drawNS::Point3D W1 = drawNS::Point3D(-10,i,poziom);
        drawNS::Point3D W2 = drawNS::Point3D(-5,i,poziom);
        drawNS::Point3D W3 = drawNS::Point3D(0,i,poziom);
        drawNS::Point3D W4 = drawNS::Point3D(5,i,poziom);
        drawNS::Point3D W5 = drawNS::Point3D(10,i,poziom);
        drawNS::Point3D W6 = drawNS::Point3D(-10,i+3,poziom);
        drawNS::Point3D W7 = drawNS::Point3D(-5,i+3,poziom);
        drawNS::Point3D W8 = drawNS::Point3D(0,i+3,poziom);
        drawNS::Point3D W9 = drawNS::Point3D(5,i+3,poziom);
        drawNS::Point3D W10 = drawNS::Point3D(10,i+3,poziom);
    Wsk_API->draw_surface(std::vector<std::vector<drawNS::Point3D> > {
        {W1, W2, W3, W4, W5}, {W6, W7, W8, W9, W10}},"blue");
    }
}

#endif //PROJEKTDRON_POWIERZCHNIA_HH
