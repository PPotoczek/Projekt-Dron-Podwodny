#ifndef PROJEKTDRON_MACIERZ_OBROTU_HH
#define PROJEKTDRON_MACIERZ_OBROTU_HH

#include<iostream>
#include<math.h>
#include"MacierzKw.hh"

class Macierz_Obrotu : public MacierzKw<double, 3>
{
public:
    Macierz_Obrotu();
    Macierz_Obrotu(char os, double kat, MacierzKw<double, 3> Ob);
};

Macierz_Obrotu:: Macierz_Obrotu()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            daneMac[i][j]=0;
        }
    }
    daneMac[0][0] = daneMac[1][1] = daneMac[2][2] = 1;
}

Macierz_Obrotu:: Macierz_Obrotu(char os, double kat,MacierzKw<double, 3> Ob)
{
    double rad = kat*3.14159/180;
    switch(os)
    {
        case 'x':
        {
            Ob[0][0] = 1;
            Ob[0][1] = 0;
            Ob[0][2] = 0;
            Ob[1][0] = 0;
            Ob[1][1] = cos(rad);
            Ob[1][2] = -sin(rad);
            Ob[2][0] = 0;
            Ob[2][1] = sin(rad);
            Ob[2][2] = cos(rad);
            break;
        }
        case 'y':
        {
            Ob[0][0] = cos(rad);
            Ob[0][1] = 0;
            Ob[0][2] = sin(rad);
            Ob[1][0] = 0;
            Ob[1][1] = 1;
            Ob[1][2] = 0;
            Ob[2][0] = -sin(rad);
            Ob[2][1] = 0;
            Ob[2][2] = cos(rad);
            break;
        }
        case 'z':
        {
            Ob[0][0] = cos(rad);
            Ob[0][1] = -sin(rad);
            Ob[0][2] = 0;
            Ob[1][0] = sin(rad);
            Ob[1][1] = cos(rad);
            Ob[1][2] = 0;
            Ob[2][0] = 0;
            Ob[2][1] = 0;
            Ob[2][2] = 1;
            break;
        }

    }
}

#endif