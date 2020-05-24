#ifndef PROJEKTDRON_INTERFEJS_RYSOWANIA_HH
#define PROJEKTDRON_INTERFEJS_RYSOWANIA_HH

#include "Dr3D_gnuplot_api.hh"
#include "Draw3D_api_interface.hh"

/*!
 * \file Interfejs_rysowania
 * Interfejs rysowania dla wszystkich obiektow i struktur
 */

/*!
 * \brief Klasa Interfejs_rys - klasa trzymajaca wskaznik sceny (dostep do sceny dla pozostalych obiektow)
 */

class Interfejs_rys
{
protected:
    std::shared_ptr<drawNS::Draw3DAPI> Wsk_API;
public:
    /*!
     * \brief Konstruktor parametryczny przekazuje wskaznik na scene
     * \param api
     */
    Interfejs_rys(std::shared_ptr<drawNS::Draw3DAPI> api);
    /*!
     * \brief Konstruktor bezparametryczny
     */
    Interfejs_rys() {};
};

Interfejs_rys::Interfejs_rys(std::shared_ptr<drawNS::Draw3DAPI> api)
{
    Wsk_API = api;
}

#endif //PROJEKTDRON_INTERFEJS_RYSOWANIA_HH
