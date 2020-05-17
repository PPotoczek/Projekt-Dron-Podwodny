#ifndef PROJEKTDRON_SZESCIAKAT_HH
#define PROJEKTDRON_SZESCIAKAT_HH

#include "Prostopadloscian.hh"

class Szesciakat: public Bryla
{
protected:
    Wektor<double, 3>Wierzcholki2[12];
public:
    explicit Szesciakat(char A);
    void Rysuj() override;
    void Czysc() override;

};

Szesciakat::Szesciakat(char A)
{
    if(A == 'P')
    {
        Wierzcholki2[0] = Wektor<double, 3>(-2, -2, 1);
        Wierzcholki2[1] = Wektor<double, 3>(-1, -2, 1);
        Wierzcholki2[2] = Wektor<double, 3>(0, -2, 0);
        Wierzcholki2[3] = Wektor<double, 3>(-1, -2, -1);
        Wierzcholki2[4] = Wektor<double, 3>(-2, -2, -1);
        Wierzcholki2[5] = Wektor<double, 3>(-3, -2, 0);
        Wierzcholki2[6] = Wektor<double, 3>(-2, -3, 1);
        Wierzcholki2[7] = Wektor<double, 3>(-1, -3, 1);
        Wierzcholki2[8] = Wektor<double, 3>(0, -3, 0);
        Wierzcholki2[9] = Wektor<double, 3>(-1, -3, -1);
        Wierzcholki2[10] = Wektor<double, 3>(-2, -3, -1);
        Wierzcholki2[11] = Wektor<double, 3>(-3, -3, 0);
        Srodek = Wektor<double, 3>(-1.5, 1, 0);
    }
    if(A == 'L')
    {
        Wierzcholki2[0] = Wektor<double, 3>(1, -2, 1);
        Wierzcholki2[1] = Wektor<double, 3>(2, -2, 1);
        Wierzcholki2[2] = Wektor<double, 3>(3, -2, 0);
        Wierzcholki2[3] = Wektor<double, 3>(2, -2, -1);
        Wierzcholki2[4] = Wektor<double, 3>(1, -2, -1);
        Wierzcholki2[5] = Wektor<double, 3>(0, -2, 0);
        Wierzcholki2[6] = Wektor<double, 3>(1, -3, 1);
        Wierzcholki2[7] = Wektor<double, 3>(2, -3, 1);
        Wierzcholki2[8] = Wektor<double, 3>(3, -3, 0);
        Wierzcholki2[9] = Wektor<double, 3>(2, -3, -1);
        Wierzcholki2[10] = Wektor<double, 3>(1, -3, -1);
        Wierzcholki2[11] = Wektor<double, 3>(0, -3, 0);
        //Srodek = drawNS::Wektor<double, 3>(0.5, -1, 0);
    }
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
    //Wsk_API->redraw();
}

void Szesciakat::Czysc()
{
    Wsk_API->erase_shape(id);
}


#endif //PROJEKTDRON_SZESCIAKAT_HH
