#ifndef PROJEKTDRON_POWIERZCHNIA_H
#define PROJEKTDRON_POWIERZCHNIA_H

#include<iostream>
#include "Interfejs rysowania.h"

class Powierzchnia :public Interfejs_rys
{
public:
    //void UtworzScene();
    void PowGora();
    void PowDol();
};

void Powierzchnia::PowGora()
{
    for(int i=-10;i<100;i=i+3)
    {
        drawNS::Point3D W1 = drawNS::Point3D(-10,i,-10);
        drawNS::Point3D W2 = drawNS::Point3D(-5,i,-10);
        drawNS::Point3D W3 = drawNS::Point3D(0,i,-10);
        drawNS::Point3D W4 = drawNS::Point3D(5,i,-10);
        drawNS::Point3D W5 = drawNS::Point3D(10,i,-10);
        drawNS::Point3D W6 = drawNS::Point3D(-10,i+3,-10);
        drawNS::Point3D W7 = drawNS::Point3D(-5,i+3,-10);
        drawNS::Point3D W8 = drawNS::Point3D(0,i+3,-10);
        drawNS::Point3D W9 = drawNS::Point3D(5,i+3,-10);
        drawNS::Point3D W10 = drawNS::Point3D(10,i+3,-10);
    Wsk_API->draw_surface(std::vector<std::vector<drawNS::Point3D> > {
        {W1, W2, W3, W4, W5}, {W6, W7, W8, W9, W10}},"yellow");
    }
}

void Powierzchnia::PowDol()
{
    for(int i=-10;i<100;i=i+3)
    {
        drawNS::Point3D W1 = drawNS::Point3D(-10, i, 10);
        drawNS::Point3D W2 = drawNS::Point3D(-5, i, 10);
        drawNS::Point3D W3 = drawNS::Point3D(0, i, 10);
        drawNS::Point3D W4 = drawNS::Point3D(5, i, 10);
        drawNS::Point3D W5 = drawNS::Point3D(10, i, 10);
        drawNS::Point3D W6 = drawNS::Point3D(-10, i + 3, 10);
        drawNS::Point3D W7 = drawNS::Point3D(-5, i + 3, 10);
        drawNS::Point3D W8 = drawNS::Point3D(0, i + 3, 10);
        drawNS::Point3D W9 = drawNS::Point3D(5, i + 3, 10);
        drawNS::Point3D W10 = drawNS::Point3D(10, i + 3, 10);
        Wsk_API->draw_surface(std::vector<std::vector<drawNS::Point3D> >{
                {W1, W2, W3, W4, W5},
                {W6, W7, W8, W9, W10}}, "blue");
    }
}

//void Powierzchnia::UtworzScene()
//{
//    Wsk_API = std::shared_ptr<drawNS::Draw3DAPI>(new drawNS:: APIGnuPlot3D(-10,10,-10,10,-10,10,0));
//}


#endif //PROJEKTDRON_POWIERZCHNIA_H
