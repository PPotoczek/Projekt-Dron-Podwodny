#ifndef PROJEKTDRON_PROSTOPADLOSCIAN_HH
#define PROJEKTDRON_PROSTOPADLOSCIAN_HH

#include "Bryla.hh"
/*!
 * \file Prostopadloscian.hh Zawiera przepis na tworzenie prostopadloscianu
 */

/*!
 * \brief Klasa Prostopadloscian zawiera pola i metody potrzebne do stworzenia prostopadloscianu w gnuplocie
 */

class Prostopadloscian: public Bryla
{
protected:
    /*!
     * Wierzcholki[8] - tablica zawiera wierzcholki prostopadloscianu
     */
    Wektor<double, 3>Wierzcholki[8];
public:
    /*!
     * Konstruktor dla prostopadloscianu
     * \param api - wskaznik na scene
     * \param Srodek - Srodek prostopadloscianu
     */
    Prostopadloscian(std::shared_ptr<drawNS::Draw3DAPI> api,Wektor<double,3> Srodek);
    /*!
     * Bezparametryczny konstruktor dla prostopadloscianu
     */
    Prostopadloscian() {};
    void Rysuj() override;
    void Czysc() override;
};

Prostopadloscian::Prostopadloscian(std::shared_ptr<drawNS::Draw3DAPI> api,Wektor<double,3> Srodek)
{
    Wsk_API = api;
    Wierzcholki[0] = Wektor<double, 3>(-3+Srodek[0],2+Srodek[1],1+Srodek[2]);
    Wierzcholki[1] = Wektor<double, 3>(-3+Srodek[0],-2+Srodek[1],1+Srodek[2]);
    Wierzcholki[2] = Wektor<double, 3>(3+Srodek[0],-2+Srodek[1],1+Srodek[2]);
    Wierzcholki[3] = Wektor<double, 3>(3+Srodek[0],2+Srodek[1],1+Srodek[2]);
    Wierzcholki[4] = Wektor<double, 3>(-3+Srodek[0],2+Srodek[1],-1+Srodek[2]);
    Wierzcholki[5] = Wektor<double, 3>(-3+Srodek[0],-2+Srodek[1],-1+Srodek[2]);
    Wierzcholki[6] = Wektor<double, 3>(3+Srodek[0],-2+Srodek[1],-1+Srodek[2]);
    Wierzcholki[7] = Wektor<double, 3>(3+Srodek[0],2+Srodek[1],-1+Srodek[2]);
}

void Prostopadloscian::Rysuj()
{
    Wektor<double,3> Pom[8];
    for(int i=0;i<8;i++)
    {
        Pom[i] = Srodek + Orientacja*Wierzcholki[i];
    }

    drawNS::Point3D W1 = Wektor_na_punkt(Pom[0]);
    drawNS::Point3D W2 = Wektor_na_punkt(Pom[1]);
    drawNS::Point3D W3 = Wektor_na_punkt(Pom[2]);
    drawNS::Point3D W4 = Wektor_na_punkt(Pom[3]);
    drawNS::Point3D W5 = Wektor_na_punkt(Pom[4]);
    drawNS::Point3D W6 = Wektor_na_punkt(Pom[5]);
    drawNS::Point3D W7 = Wektor_na_punkt(Pom[6]);
    drawNS::Point3D W8 = Wektor_na_punkt(Pom[7]);
    id = Wsk_API->draw_polyhedron(std::vector<std::vector<drawNS::Point3D> > {{
                                                                            W1,W2,W3,W4
                                                                     },{
                                                                             W5,W6,W7,W8
                                                                     }},"black");
    Wsk_API->redraw();
}
void Prostopadloscian::Czysc()
{
    Wsk_API->erase_shape(id);
}



#endif