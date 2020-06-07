#ifndef PROJEKTDRON_PRZESZKODA_PROSTOPADLOSCIAN_HH
#define PROJEKTDRON_PRZESZKODA_PROSTOPADLOSCIAN_HH

#include "Przeszkoda.hh"
#include "Interfejs_rysowania.hh"

/*!
 * \file Przeszkoda_Prostopadloscian.hh Zawiera przepis na przeszkode prostopadloscienna
 */

/*!
 * \brief Klasa Przeszkoda_Prostopadloscian zawiera pola i metody potrzebne do stworzenia przeszkody prostopadlosciennej w gnuplocie
 */

class Przeszkoda_Prostopadloscian :public Przeszkoda, public Interfejs_rys
{
protected:
    /*!
     * Srodek - Srodek przeszkody prostopadlosciennej
     * Wierzcholki[8] - tablica z wierzcholkami przeszkody prostopadlosciennej
     * promienX - ustalony odgornie promien drona na wspolrzednych X
     * promienY - ustalony odgornie promien drona na wspolrzednych Y
     * promienZ - ustalony odgornie promien drona na wspolrzednych Z
     * IloscPrzeszkodUtworzonych - ilosc utworzonych przeszkod
     * IloscPrzeszkodIstniejacych - ilosc istniejacych przeszkod
     */
    Wektor<double, 3> Srodek;
    Wektor<double, 3> Wierzcholki[8];
    double promienX = 3;
    double promienY = 3;
    double promienZ = 2;
    inline static int IloscPrzeszkodUtworzonych=0;
    inline static int IloscPrzeszkodIstniejacych=0;
public:
    /*!
     * \brief Bezparametryczny konstruktor dla przeszkody prostopadlosciennej
     */
    Przeszkoda_Prostopadloscian();
    /*!
     * \brief Destruktor dla przeszkody prostopadlosciennej
     */
    ~Przeszkoda_Prostopadloscian();
    /*!
     * \brief Konstruktor przeszkody prostopadlosciennej
     * \param api - wskaznik na scene
     * \param Srodek_Przeszkody - Srodek przeszkody prostopadlosciennej
     * \param szerokosc - szerkosc przeszkody prostopadlosciennej
     * \param dlugosc - dlugosc przeszkody prostopadlosciennej
     * \param wysokosc - wysokosc przeszkody prostopadlosciennej
     */
    Przeszkoda_Prostopadloscian(std::shared_ptr<drawNS::Draw3DAPI> api, Wektor<double, 3> Srodek_Przeszkody, double szerokosc, double dlugosc, double wysokosc);
    bool Kolizja(Interfejs_Drona *D) override ;
    /*!
     * Funkcja statyczna zwracajaca ilosc utworzonych przeszkod prostopadlosciennych
     */
    static int GetUtworzone();
    /*!
     * Funkcja statyczna zwracajaca ilosc istniejacych przeszkod prostopadlosciennych
     */
    static int GetIstniejace();
};

Przeszkoda_Prostopadloscian::Przeszkoda_Prostopadloscian()
{
    IloscPrzeszkodUtworzonych++;
    IloscPrzeszkodIstniejacych++;
}

Przeszkoda_Prostopadloscian::~Przeszkoda_Prostopadloscian()
{
    IloscPrzeszkodIstniejacych--;
}

Przeszkoda_Prostopadloscian::Przeszkoda_Prostopadloscian(std::shared_ptr<drawNS::Draw3DAPI> api, Wektor<double, 3> Srodek_Przeszkody, double szerokosc, double dlugosc, double wysokosc)
{
    Wsk_API = api;
    Srodek = Srodek_Przeszkody;
    double s_pom = szerokosc/2;
    double d_pom = dlugosc/2;
    double w_pom = wysokosc/2;
    Wierzcholki[0] = Wektor<double, 3>(-s_pom+Srodek[0],d_pom+Srodek[1],w_pom+Srodek[2]);
    Wierzcholki[1] = Wektor<double, 3>(-s_pom+Srodek[0],-d_pom+Srodek[1],w_pom+Srodek[2]);
    Wierzcholki[2] = Wektor<double, 3>(s_pom+Srodek[0],-d_pom+Srodek[1],w_pom+Srodek[2]);
    Wierzcholki[3] = Wektor<double, 3>(s_pom+Srodek[0],d_pom+Srodek[1],w_pom+Srodek[2]);
    Wierzcholki[4] = Wektor<double, 3>(-s_pom+Srodek[0],d_pom+Srodek[1],-w_pom+Srodek[2]);
    Wierzcholki[5] = Wektor<double, 3>(-s_pom+Srodek[0],-d_pom+Srodek[1],-w_pom+Srodek[2]);
    Wierzcholki[6] = Wektor<double, 3>(s_pom+Srodek[0],-d_pom+Srodek[1],-w_pom+Srodek[2]);
    Wierzcholki[7] = Wektor<double, 3>(s_pom+Srodek[0],d_pom+Srodek[1],-w_pom+Srodek[2]);
    drawNS::Point3D W1 = Wektor_na_punkt(Wierzcholki[0]);
    drawNS::Point3D W2 = Wektor_na_punkt(Wierzcholki[1]);
    drawNS::Point3D W3 = Wektor_na_punkt(Wierzcholki[2]);
    drawNS::Point3D W4 = Wektor_na_punkt(Wierzcholki[3]);
    drawNS::Point3D W5 = Wektor_na_punkt(Wierzcholki[4]);
    drawNS::Point3D W6 = Wektor_na_punkt(Wierzcholki[5]);
    drawNS::Point3D W7 = Wektor_na_punkt(Wierzcholki[6]);
    drawNS::Point3D W8 = Wektor_na_punkt(Wierzcholki[7]);
    Wsk_API->draw_polyhedron(std::vector<std::vector<drawNS::Point3D> > {{
                                                                                      W1,W2,W3,W4
                                                                              },{
                                                                                      W5,W6,W7,W8
                                                                              }},"green");
    IloscPrzeszkodUtworzonych++;
    IloscPrzeszkodIstniejacych++;
}

bool Przeszkoda_Prostopadloscian::Kolizja(Interfejs_Drona *D)
{
    Wektor<double,3> Promien = Wektor<double,3>(promienX,promienY,promienZ);
    Wektor<double, 3> Pom1 = Wierzcholki[3] + Promien;
    Wektor<double, 3> Pom2 = Wierzcholki[5] - Promien;
    if(D->getSrodek()[0] <= Pom1[0] && D->getSrodek()[1] <= Pom1[1] && D->getSrodek()[2] <= Pom1[2] && D->getSrodek()[0] >= Pom2[0] && D->getSrodek()[1] >= Pom2[1] && D->getSrodek()[2] >= Pom2[2])
    {
        std::cout << "Wystapila kolizja\n";
        return true;
    } else
    {
        return false;
    }
}

int Przeszkoda_Prostopadloscian::GetUtworzone()
{
    return IloscPrzeszkodUtworzonych;
}

int Przeszkoda_Prostopadloscian::GetIstniejace()
{
    return IloscPrzeszkodIstniejacych;
}

#endif
