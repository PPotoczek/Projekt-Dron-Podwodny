#ifndef PROJEKTDRON_INTERFEJS_DRONA_HH
#define PROJEKTDRON_INTERFEJS_DRONA_HH

class Interfejs_Drona
{
public:
    virtual Wektor<double, 3> getSrodek() = 0;
};

#endif