#ifndef PROJEKTDRON_MACIERZ_OBROTU_HH
#define PROJEKTDRON_MACIERZ_OBROTU_HH

#include<iostream>
#include<math.h>
#include"MacierzKw.hh"

/*!
 * \file Macierz_Obrotu.hh
 * Zawiera przepis na macierz obrotu
 */

/*!
 * \brief Klasa Macierz_Obrotu zawiera konstruktory potrzebne do stworzenia macierzy obrotu
 */

class Macierz_Obrotu : public MacierzKw<double, 3>
{
public:
    /*!
     * \brief Bezparametryczny konstruktor dla macierzy obrotu
     */
    Macierz_Obrotu();
    /*!
     * \brief Konstruktor dla Macierzy Obrotu
     * \param os - os ukladu wspolrzednych
     * \param kat - kat obrotu
     */
    Macierz_Obrotu(char os, double kat);
    /*!
     * \brief Konstruktor dla Macierzy Obrotu
     * \param M
     */
    Macierz_Obrotu(MacierzKw<double, 3> M);
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

Macierz_Obrotu:: Macierz_Obrotu(char os, double kat)//,MacierzKw<double, 3> Ob)
{
    double rad = kat*3.14159/180;
    switch(os)
    {
        case 'x':
        {
            daneMac[0][0] = 1;
            daneMac[0][1] = 0;
            daneMac[0][2] = 0;
            daneMac[1][0] = 0;
            daneMac[1][1] = cos(rad);
            daneMac[1][2] = -sin(rad);
            daneMac[2][0] = 0;
            daneMac[2][1] = sin(rad);
            daneMac[2][2] = cos(rad);
            break;
        }
        case 'y':
        {
            daneMac[0][0] = cos(rad);
            daneMac[0][1] = 0;
            daneMac[0][2] = sin(rad);
            daneMac[1][0] = 0;
            daneMac[1][1] = 1;
            daneMac[1][2] = 0;
            daneMac[2][0] = -sin(rad);
            daneMac[2][1] = 0;
            daneMac[2][2] = cos(rad);
            break;
        }
        case 'z':
        {
            daneMac[0][0] = cos(rad);
            daneMac[0][1] = -sin(rad);
            daneMac[0][2] = 0;
            daneMac[1][0] = sin(rad);
            daneMac[1][1] = cos(rad);
            daneMac[1][2] = 0;
            daneMac[2][0] = 0;
            daneMac[2][1] = 0;
            daneMac[2][2] = 1;
            break;
        }
    }
}

Macierz_Obrotu::Macierz_Obrotu(MacierzKw<double, 3> M)
{
    daneMac[0][0] = M[0][0];
    daneMac[0][1] = M[0][1];
    daneMac[0][2] = M[0][2];
    daneMac[1][0] = M[1][0];
    daneMac[1][1] = M[1][1];
    daneMac[1][2] = M[1][2];
    daneMac[2][0] = M[2][0];
    daneMac[2][1] = M[2][1];
    daneMac[2][2] = M[2][2];
}

#endif