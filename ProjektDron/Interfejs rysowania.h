#ifndef PROJEKTDRON_INTERFEJS_RYSOWANIA_H
#define PROJEKTDRON_INTERFEJS_RYSOWANIA_H

#include "Dr3D_gnuplot_api.hh"
#include "Draw3D_api_interface.hh"

class Interfejs_rys
{
protected:
    std::shared_ptr<drawNS::Draw3DAPI> Wsk_API;
public:
    void UtworzScene();
};

void Interfejs_rys::UtworzScene()
{
    std::shared_ptr<drawNS::Draw3DAPI> api(new drawNS::APIGnuPlot3D(-10,10,-10,10,-10,10,0));
    Wsk_API = api;
}

#endif //PROJEKTDRON_INTERFEJS_RYSOWANIA_H
