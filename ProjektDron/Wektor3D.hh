#ifndef PROJEKTDRON_WEKTOR3D_HH
#define PROJEKTDRON_WEKTOR3D_HH

#include "Wektor.hh"
#include<iostream>

class Wektor3D : public Wektor<double, 3>
{
public:
    Wektor3D(double x, double y, double z);
    Wektor3D() {};
};


#endif //PROJEKTDRON_WEKTOR3D_HH
