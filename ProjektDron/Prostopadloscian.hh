#ifndef PROJEKTDRON_PROSTOPADLOSCIAN_HH
#define PROJEKTDRON_PROSTOPADLOSCIAN_HH

#include "Bryla.hh"

class Prostopadloscian: public Bryla
{
protected:
    Wektor<double, 3>Wierzcholki[8];
public:
    Prostopadloscian();
    void Rysuj() override;
    void Czysc() override;
    void RotujX(int kat);
    void RotujY(int kat);
    void RotujZ(int kat);
};

Prostopadloscian::Prostopadloscian()
{
    Wierzcholki[0] = Wektor<double, 3>(-3,2,1);
    Wierzcholki[1] = Wektor<double, 3>(-3,-2,1);
    Wierzcholki[2] = Wektor<double, 3>(3,-2,1);
    Wierzcholki[3] = Wektor<double, 3>(3,2,1);
    Wierzcholki[4] = Wektor<double, 3>(-3,2,-1);
    Wierzcholki[5] = Wektor<double, 3>(-3,-2,-1);
    Wierzcholki[6] = Wektor<double, 3>(3,-2,-1);
    Wierzcholki[7] = Wektor<double, 3>(3,2,-1);
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
    std::cout << id <<  std::endl;
    int a=0;
    a = Wsk_API->draw_polyhedron(std::vector<std::vector<drawNS::Point3D> > {{
                                                                            W1,W2,W3,W4
                                                                     },{
                                                                             W5,W6,W7,W8
                                                                     }},"blue");
    //Wsk_API->redraw();
    id = a;
    std::cout << id << std::endl;
}
void Prostopadloscian::Czysc()
{
    Wsk_API->erase_shape(id);
}

void Prostopadloscian:: RotujX(int kat)
{


}

void Prostopadloscian:: RotujY(int kat)
{

}

void Prostopadloscian:: RotujZ(int kat)
{

}

#endif