#include <iostream>
#include "Dr3D_gnuplot_api.hh"
//#include "Macierz_Obrotu.hh"
//#include "Wektor3D.hh"
//#include "Prostopadloscian.hh"
#include "Dron.hh"
#include "Powierzchnia.h"
#include "Szesciakat.hh"
#include "Interfejs rysowania.h"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::cin;
using std::endl;

void wait4key() {
    do {
        std::cout << "\n Press a key to continue..." << std::endl;
    } while(std::cin.get() != '\n');
}

int main()
{
    /*
     *
     *
     * WAZNE : PROGRAM NARAZIE NIE DZIALA
     * STWORZONE SA NARAZIE ODDZIELNIE DNO, POW. WODY, DRON, WIRNIKI, (JAKAS PROBA PORUSZANIA DRONEM)
     * COS NIE DZIALA MI WSKAZNIK API (PO JEDNYM ODPALENIU ZERUJE SIE(SEGFAULTY), NIE PRZYPISUJE SIE DO ID) I CHETNIE PRZYSZEDLBYM NA KONSULTACJE OMOWIC W CZYM JEST PROBLEM
     * WIEKSZOSC RZECZY, PONIEWAZ SA KROTKIE TO TYLKO W HEADERZE SA ZAPISYWANE
     *
     *
     *
     */
    /*
    std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-10,10,-10,10,-10,10,1000)); //włacza gnuplota, pojawia się scena [-5,5] x [-5,5] x [-5,5] odświeżana co 1000 ms
    //drawNS::Draw3DAPI * api = new APIGnuPlot3D(-5,5,-5,5,-5,5,1000); //alternatywnie zwykły wskaźnik
    api->change_ref_time_ms(0); //odświeżanie sceny zmienione na opcję "z każdym pojawieniem się lub zniknięciem kształtu"
    int a=api->draw_line(drawNS::Point3D(0,0,0),drawNS::Point3D(10,0,0)); //rysuje linię pomiędzy (0,0,0) a (2,0,0), zapamiętuje id kształtu w zmiennej a
    api->draw_line(drawNS::Point3D(0,0,0),drawNS::Point3D(0,0,10),"red"); //rysuje czerwoną linie pomiędzy (0,0,0) a (0,0,5)

    cout << endl << "pojawiły się 2 linie: czarna i czerwona" << endl;
    wait4key();

    api->erase_shape(a); //usuwa kształt o id a
    cout << "czarna linia zniknęła" << endl;

    wait4key();

    api->draw_polygonal_chain(vector<Point3D> {drawNS::Point3D(0,0,0),
                                               drawNS::Point3D(0,4,0),drawNS::Point3D(4,4,0),
                                               drawNS::Point3D(4,0,0),drawNS::Point3D(4,0,4)},"purple"); //rysuje fioletową łamaną
    cout << "pojawiła się fioletowa łamana" << endl;

    wait4key();
    api->change_ref_time_ms(1000);
    int b=api->draw_polygonal_chain(vector<Point3D> {drawNS::Point3D(0,0,0),
                                                     drawNS::Point3D(0,-4,0),drawNS::Point3D(-4,-4,0),
                                                     drawNS::Point3D(-4,0,0),drawNS::Point3D(-4,0,-4)},"green");
    cout << "pojawiła się zielona łamana" << endl;

    wait4key();
    api->change_shape_color(b,"yellow");//zmienia kolor
    cout << "zmiana koloru z zielonej na żółtą" << endl;

    wait4key();
    api->change_ref_time_ms(-1);//odświerzanie sceny zmienione na opcję "tylko za pomocą metody redraw()"

    api->draw_polyhedron(vector<vector<Point3D> > {{
                                                           drawNS::Point3D(0,0,0), drawNS::Point3D(0,1,0), drawNS::Point3D(1,1,0)
                                                   },{
                                                           drawNS::Point3D(0,0,3), drawNS::Point3D(0,1,3), drawNS::Point3D(1,2,4)
                                                   }},"blue");//rysuje niebieski graniastosłup
    cout << "nie pojawiła się niebieski graniastosłup" << endl;

    wait4key();

    api->redraw();//odświerzenie sceny
    cout << "dopiero teraz pojawiła się niebieski graniastosłup" << endl;

    wait4key();
    api->change_ref_time_ms(0);

    api->draw_surface(vector<vector<Point3D> > {{
                                                        drawNS::Point3D(-4,-2,-4), drawNS::Point3D(-4,0,-4), drawNS::Point3D(-4,2,-4)
                                                },{
                                                        drawNS::Point3D(-2,-2,-4), drawNS::Point3D(-2,0,-4), drawNS::Point3D(-2,2,-4)
                                                },{
                                                        drawNS::Point3D(-0,-2,-4), drawNS::Point3D(-0,0,-3), drawNS::Point3D(-0,2,-4)
                                                },{
                                                        drawNS::Point3D(2,-2,-4), drawNS::Point3D(2,0,-4), drawNS::Point3D(2,2,-4)
                                                },{
                                                        drawNS::Point3D(4,-2,-4), drawNS::Point3D(4,0,-4), drawNS::Point3D(4,2,-4)
                                                }},"grey");//rysuje szarą powierzchnie
    cout << "pojawiła się szara powierzchnia" << endl;


    wait4key();


    //delete api;//dla zwykłych wskaźników musimy posprzątać
     */
/*

    std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-10,10,-10,10,-10,10,1000)); //włacza gnuplota, pojawia się scena [-5,5] x [-5,5] x [-5,5] odświeżana co 1000 ms
    //drawNS::Draw3DAPI * api = new APIGnuPlot3D(-5,5,-5,5,-5,5,1000); //alternatywnie zwykły wskaźnik
    api->change_ref_time_ms(0); //odświeżanie sceny zmienione na opcję "z każdym pojawieniem się lub zniknięciem kształtu"

    wait4key();
    //drawNS::Draw3DAPI * api = new APIGnuPlot3D(-5,5,-5,5,-5,5,1000);
    //api->change_ref_time_ms(0);

    //int a=api->draw_line(drawNS::Point3D(0,0,0),drawNS::Point3D(10,0,0)); //rysuje linię pomiędzy (0,0,0) a (2,0,0), zapamiętuje id kształtu w zmiennej a
    //api->draw_line(drawNS::Point3D(0,0,0),drawNS::Point3D(0,0,10),"red"); //rysuje czerwoną linie pomiędzy (0,0,0) a (0,0,5)

    wait4key();
    api->draw_surface(vector<vector<Point3D> > {{
                                                        drawNS::Point3D(-2,-2,-4), drawNS::Point3D(-2,0,-4), drawNS::Point3D(-2,2,-4)
                                                },{
                                                        drawNS::Point3D(-0,-2,-4), drawNS::Point3D(-0,0,-3), drawNS::Point3D(-0,2,-4)
                                                },{
                                                        drawNS::Point3D(2,-2,-4), drawNS::Point3D(2,0,-4), drawNS::Point3D(2,2,-4)
                                                },{
                                                        drawNS::Point3D(4,-2,-4), drawNS::Point3D(4,0,-4), drawNS::Point3D(4,2,-4)
                                                }},"grey");//rysuje szarą powierzchnie
    cout << "pojawiła się szara powierzchnia" << endl;
*/
    wait4key();
    Powierzchnia A;
    A.UtworzScene();
    A.PowDol();
    A.PowGora();
    wait4key();

    /*
    char wybor;
    char os;
    double kat;
    for (1;1;1)
    {
        cout << "==MENU==" << endl;
        cout << "w - przod\n" << "s - tyl\n" << "q - gora\n" << "e - dol\n" << "r - rotacja\n" << "x - wyjscie\n";
        cin >> wybor;
        switch (wybor)
        {
            case 'w':  //przod
            {
                break;
            }
            case 's': // tyl
            {
                break;
            }
            case 'q': // gora
            {
                break;
            }
            case 'e': // dol
            {
                break;
            }
            case 'r': //rotacja
            {
                cout << "Podaj kat obrotu: " << endl;
                cin >> kat;
                if(!cin.good())
                {
                    std::cerr << "Zle podany kat" << endl;
                    cin.clear();
                    break;
                }
                cout << "Podaj os obrotu(x,y,z): " << endl;
                cin >> os;
                switch(os)
                {
                    case 'x':
                    {
                        break;
                    }
                    case 'y':
                    {
                        break;
                    }
                    case 'z':
                    {
                        break;
                    }
                    default:
                    {
                        cout << "Podana os nie istnieje" << endl;
                    }
                }
                break;
            }
            case 'x':
            {
                return 0;
                break;
            }
            default:
            {
                cout << "Zla komenda sproboj ponownie" << endl;
                break;
            }
        }
        cout << endl << endl;
    }
    */
}
