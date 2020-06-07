#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "Wektor.hh"
#include <iostream>
#include <math.h>
#include <iomanip>

template<class TYP, int ROZMIAR>
class MacierzKw
{
protected:
    Wektor<TYP,ROZMIAR> daneMac[ROZMIAR];
public:
    MacierzKw();
    const Wektor<TYP, ROZMIAR> & operator[] (int indeks) const;
    Wektor<TYP, ROZMIAR> & operator[] (int indeks);
    Wektor<TYP, ROZMIAR> wez_kolumne(int indeks);
    void Zamiana_kolumny(int indeks, const Wektor<TYP, ROZMIAR> & W);
    void Transpozycja();
    TYP WyznacznikGauss();
    MacierzKw<TYP, ROZMIAR> Odwrotnosc();
    MacierzKw<TYP, ROZMIAR> operator + (MacierzKw<TYP, ROZMIAR> M);
    MacierzKw<TYP, ROZMIAR> operator - (MacierzKw<TYP, ROZMIAR> M);
    MacierzKw<TYP, ROZMIAR> operator * (MacierzKw<TYP, ROZMIAR> M);
    MacierzKw<TYP, ROZMIAR> operator / (TYP L);
    Wektor<TYP, ROZMIAR> operator * (Wektor<TYP, ROZMIAR> W);
};

template<class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &str, MacierzKw<TYP, ROZMIAR> &Mac);

template<class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &str, MacierzKw<TYP, ROZMIAR> &Mac);

template<class TYP, int ROZMIAR>
MacierzKw<TYP, ROZMIAR>::MacierzKw()
{
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0;j<ROZMIAR;j++)
        {
            daneMac[i][j]=0;
        }
    }
}

template<class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> MacierzKw<TYP, ROZMIAR>::wez_kolumne(int indeks)
{
    Wektor<TYP, ROZMIAR> Wynik;
    for(int i=0;i<ROZMIAR;i++)
    {
        Wynik[i] = daneMac[i][indeks];
    }
    return Wynik;
}

template<class TYP, int ROZMIAR>
void MacierzKw<TYP, ROZMIAR>:: Zamiana_kolumny(int indeks, const Wektor<TYP, ROZMIAR> &W)
{
    for(int i=0;i<ROZMIAR;i++)
    {
        daneMac[i][indeks] = W[i];
    }
}

template<class TYP, int ROZMIAR>
void MacierzKw<TYP, ROZMIAR>::Transpozycja()
{
    MacierzKw<TYP, ROZMIAR>M_Pomocnicza;
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0;j<ROZMIAR;j++)
        {
            M_Pomocnicza[i][j]=daneMac[i][j];
        }
    }
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0;j<ROZMIAR;j++)
        {
            daneMac[i][j]=M_Pomocnicza[j][i];
        }
    }
}

template<class TYP, int ROZMIAR>
const Wektor<TYP, ROZMIAR> &MacierzKw<TYP, ROZMIAR>:: operator[](int indeks) const
{
    if (indeks < 0 || indeks >= ROZMIAR)
    {
        std::cerr << "Blad: Zly indeks macierzy";
        exit(1);
    }
    return this->daneMac[indeks];
}

template<class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> & MacierzKw<TYP, ROZMIAR>:: operator[](int indeks)
{
    if (indeks < 0 || indeks >= ROZMIAR)
    {
        std::cerr << "Blad: Zly indeks macierzy";
        exit(1);
    }
    return this->daneMac[indeks];
}

template<class TYP, int ROZMIAR>
TYP MacierzKw<TYP, ROZMIAR>:: WyznacznikGauss()
{
    TYP Wyznacznik;
    Wyznacznik =1;
    TYP mnoznik;
    Wektor<TYP, ROZMIAR> zamiennik;
    for(int i=0;i<ROZMIAR-1;i++)
    {
        for(int j=i+1;j<ROZMIAR;j++)
        {
            if(this->daneMac[i][i]==0)
            {
                for(int k=0;k<ROZMIAR-i;k++)
                {
                    if(this->daneMac[i+k][i]!=0)
                    {
                        zamiennik = this->daneMac[i+k];
                        this->daneMac[i+k] = this->daneMac[i];
                        this->daneMac[i] = zamiennik;
                    }
                }
                if(this->daneMac[i][i]==0)
                {
                    Wyznacznik=0;
                    return Wyznacznik;
                }
                Wyznacznik = Wyznacznik * (-1);
            }
            mnoznik = this->daneMac[j][i] / this->daneMac[i][i];
            this->daneMac[j] = this->daneMac[j] - this->daneMac[i] * mnoznik;
        }
    }
    //std::cout << std::endl << *this << std::endl;
    for(int i=0;i<ROZMIAR;i++)
    {
        Wyznacznik = Wyznacznik*this->daneMac[i][i];
    }
    return Wyznacznik;
}

template<class TYP, int ROZMIAR>
MacierzKw<TYP, ROZMIAR> MacierzKw<TYP, ROZMIAR>::Odwrotnosc()
{
    MacierzKw<TYP, ROZMIAR> Wynik;
    MacierzKw<TYP, ROZMIAR> Zmienna;
    Wektor<TYP, ROZMIAR> zamiennik;
    Wektor<TYP, ROZMIAR> zamiennik_Wynik;
    Zmienna = *this;
    TYP wyznacznik;
    TYP mnoznik;
    wyznacznik = Zmienna.WyznacznikGauss();
    if(wyznacznik==0)
    {
        std::cerr << "Blad : Wyznaczik jest rowny zeru. Macierz odwrotna nie istnieje." << std::endl;
        exit(1);
    }
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0;j<ROZMIAR;j++)
        {
            if(i==j)
            {
                Wynik[i][j] = 1;
            }
            else
            {
                Wynik[i][j] = 0;
            }
        }
    }
    for(int i=0;i<ROZMIAR-1;i++)
    {
        for(int j=i+1;j<ROZMIAR;j++)
        {
            if(this->daneMac[i][i]==0)
            {
                for(int k=0;k<ROZMIAR-i;k++)
                {
                    if(this->daneMac[i+k][i]!=0)
                    {
                        zamiennik = this->daneMac[i+k];
                        this->daneMac[i+k] = this->daneMac[i];
                        this->daneMac[i] = zamiennik;
                        zamiennik_Wynik = Wynik[i+k];
                        Wynik[i+k] = Wynik[i];
                        Wynik[i] = zamiennik_Wynik;
                    }
                }
                if(this->daneMac[i][i]==0)
                {
                    std::cerr << "Blad : Wyznaczik jest rowny zeru. Macierz odwrotna nie istnieje." << std::endl;
                    exit(1);
                }
            }
            mnoznik = this->daneMac[j][i] / this->daneMac[i][i];
            this->daneMac[j] = this->daneMac[j] - this->daneMac[i] * mnoznik;
            Wynik[j] = Wynik[j] - Wynik[i]*mnoznik;
        }
    }
    for(int i=ROZMIAR-1;i>0;i--)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(this->daneMac[j][i]!=0)
            {
                mnoznik = this->daneMac[i][i] / this->daneMac[j][i];
                this->daneMac[j] = this->daneMac[j]*mnoznik - this->daneMac[i];
                Wynik[j] = Wynik[j]*mnoznik - Wynik[i];
            }
        }
    }
    for(int i=0;i<ROZMIAR;i++)
    {
        Wynik[i] = Wynik[i]/this->daneMac[i][i];
    }
    return Wynik;
}



template<class TYP, int ROZMIAR>
MacierzKw<TYP, ROZMIAR> MacierzKw<TYP, ROZMIAR>::operator+(MacierzKw<TYP, ROZMIAR> M)
{
    MacierzKw<TYP, ROZMIAR> Wynik;
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0;j<ROZMIAR;j++)
        {
            Wynik[i][j]=this->daneMac[i][j]+M.daneMac[i][j];
        }
    }
    return Wynik;
}

template<class TYP, int ROZMIAR>
MacierzKw<TYP, ROZMIAR> MacierzKw<TYP, ROZMIAR>::operator-(MacierzKw<TYP, ROZMIAR> M)
{
    MacierzKw<TYP, ROZMIAR> Wynik;
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0;j<ROZMIAR;j++)
        {
            Wynik[i][j]=this->daneMac[i][j]-M.daneMac[i][j];
        }
    }
    return Wynik;
}

template<class TYP, int ROZMIAR>
MacierzKw<TYP, ROZMIAR> MacierzKw<TYP, ROZMIAR>::operator*(MacierzKw<TYP, ROZMIAR> M)
{
    MacierzKw<TYP, ROZMIAR> Wynik;
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0;j<ROZMIAR;j++)
        {
            Wynik[i][j]= this->daneMac[i]*M.wez_kolumne(j);
        }
    }
    return Wynik;
}

template<class TYP, int ROZMIAR>
MacierzKw<TYP, ROZMIAR> MacierzKw<TYP, ROZMIAR>::operator / (TYP L)
{
    if(L==0)
    {
        std::cerr << "Blad : Nie mozna dzielic przez 0";
        exit (1);
    }
    MacierzKw<TYP, ROZMIAR> Wynik;
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0;j<ROZMIAR;j++)
        {
            Wynik[i][j]=daneMac[i][j]/L;
        }
    }
    return Wynik;
}

template<class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> MacierzKw<TYP, ROZMIAR>::operator*(Wektor<TYP, ROZMIAR> W)
{
    Wektor<TYP, ROZMIAR> Wynik;
    for(int i=0;i<ROZMIAR;i++)
    {
        Wynik[i]=this->daneMac[i]*W;
    }
    return Wynik;
}

template<class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &str, MacierzKw<TYP, ROZMIAR> &Mac)
{
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0;j<ROZMIAR;j++)
        {
            str >>  Mac[i][j];
        }
    }
    return str;
}

template<class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &str, MacierzKw<TYP, ROZMIAR> &Mac)
{
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0;j<ROZMIAR;j++)
        {
            str << std::fixed << std::setprecision(2) << Mac[i][j] << " ";
        }
        str << std::endl;
    }
    return str;
}


#endif