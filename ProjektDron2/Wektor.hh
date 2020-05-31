#ifndef WEKTOR_HH
#define WEKTOR_HH


#include <iostream>
#include <math.h>
#include<iomanip>

template<class TYP, int ROZMIAR>
class  Wektor
{
protected:
    TYP daneWek[ROZMIAR];
public:
    Wektor();
    Wektor(double x, double y, double z);
    TYP operator * (const Wektor<TYP, ROZMIAR> &W2) const;
    Wektor<TYP, ROZMIAR> operator + (const Wektor<TYP, ROZMIAR> &W2) const;
    Wektor<TYP, ROZMIAR> operator - (const Wektor<TYP, ROZMIAR> &W2) const;
    Wektor<TYP, ROZMIAR> operator * (TYP liczba) const;
    Wektor<TYP, ROZMIAR> operator / (TYP liczba) const;
    TYP & operator[] (int indeks) const;
    TYP & operator[] (int indeks);
};

template<class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &str, Wektor <TYP, ROZMIAR> &Wek);

template<class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &str, Wektor <TYP, ROZMIAR> &Wek);

template <class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR>:: Wektor()
{
    for(int i=0;i<ROZMIAR;i++)
    {
        daneWek[i]=0;
    }
}

template <class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR>::Wektor(double x, double y, double z)
{
    daneWek[0] = x;
    daneWek[1] = y;
    daneWek[2] = z;
}

template<class TYP, int ROZMIAR>
TYP Wektor<TYP, ROZMIAR>:: operator * (const Wektor<TYP, ROZMIAR> &W2) const
{
    TYP Wynik;
    Wynik=0;
    for(int i=0;i<ROZMIAR;i++)
    {
        Wynik= Wynik + this->daneWek[i]*W2.daneWek[i];
    }
    return Wynik;
}

template<class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> Wektor<TYP, ROZMIAR>:: operator + (const Wektor<TYP, ROZMIAR> &W2) const
{
    Wektor Wynik;
    for(int i=0;i<ROZMIAR;i++)
    {
        Wynik.daneWek[i]=this->daneWek[i]+W2.daneWek[i];
    }
    return Wynik;
}

template<class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> Wektor<TYP, ROZMIAR>:: operator - (const Wektor<TYP, ROZMIAR> &W2) const
{
    Wektor Wynik;
    for(int i=0;i<ROZMIAR;i++)
    {
        Wynik.daneWek[i]=this->daneWek[i]-W2.daneWek[i];
    }
    return Wynik;
}

template<class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> Wektor<TYP, ROZMIAR>:: operator * (const TYP liczba) const
{
    Wektor Wynik;
    for(int i=0;i<ROZMIAR;i++)
    {
        Wynik[i] = this->daneWek[i]*liczba;
    }
    return Wynik;
}

template<class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> Wektor<TYP, ROZMIAR>:: operator / (const TYP liczba) const
{
    Wektor Wynik;
    for(int i=0;i<ROZMIAR;i++)
    {
        Wynik[i] = this->daneWek[i]/liczba;
    }
    return Wynik;
}

template<class TYP, int ROZMIAR>
TYP & Wektor<TYP, ROZMIAR>:: operator[] (int indeks) const
{
    if (indeks < 0 || indeks >= ROZMIAR)
    {
        std::cerr << "Blad: Zly indeks wektora";
        exit(1);
    }
    return this->daneWek[indeks];
}

template<class TYP, int ROZMIAR>
TYP & Wektor<TYP, ROZMIAR>:: operator[] (int indeks)
{
    if (indeks < 0 || indeks >= ROZMIAR)
    {
        std::cerr << "Blad: Zly indeks wektora";
        exit(1);
    }
    return this->daneWek[indeks];
}

template<class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &str, Wektor <TYP, ROZMIAR> &Wek)
{

    for(int i=0;i<ROZMIAR;i++)
    {
        str >> Wek[i];
    }
    return str;
}

template<class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &str, Wektor <TYP, ROZMIAR> &Wek)
{
    str << "( ";
    for(int i=0;i<ROZMIAR;i++)
    {
        str << std::fixed << std::setprecision(2) << Wek[i];
        if(i<ROZMIAR-1)
        {
            str << ", ";
        }
    }
    str << " )";
    return str;
}

#endif