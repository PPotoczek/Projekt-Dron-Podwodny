#include <iostream>
//#include "Dr3D_gnuplot_api.hh"
#include "Dron.hh"
#include "Powierzchnia.hh"
#include "Przeszkoda_Prostopadloscian.hh"

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
    std::shared_ptr<drawNS::Draw3DAPI> api(new drawNS::APIGnuPlot3D(-10,10,-10,20,-10,10,-1));
    Powierzchnia Powi(api);
    std::shared_ptr<Przeszkoda_Prostopadloscian> Przeszkoda1(new Przeszkoda_Prostopadloscian(api,Wektor<double,3>(8,15,-5),4,4,10));
    std::shared_ptr<Przeszkoda_Prostopadloscian> Przeszkoda2(new Przeszkoda_Prostopadloscian(api,Wektor<double,3>(-3,8,5),10,2,8));
    std::shared_ptr<Przeszkoda_Prostopadloscian> Przeszkoda3(new Przeszkoda_Prostopadloscian(api,Wektor<double,3>(3,9,-5),5,7,3));
    std::shared_ptr<Przeszkoda_Prostopadloscian> Przeszkoda4(new Przeszkoda_Prostopadloscian(api,Wektor<double,3>(-7,5,-3),-5,8,8));
    std::vector<std::shared_ptr<Przeszkoda> > kolekcja_przeszkod;
    kolekcja_przeszkod.push_back(Przeszkoda1);
    kolekcja_przeszkod.push_back(Przeszkoda2);
    kolekcja_przeszkod.push_back(Przeszkoda3);
    kolekcja_przeszkod.push_back(Przeszkoda4);
    Powi.Pow(10);
    Powi.Pow(-10);
    char wybor;
    char os;
    double kat;
    double odleglosc;
    std::shared_ptr<Dron> D1(new Dron(api,Wektor<double,3>(0,0,0)));
    std::shared_ptr<Dron> D2(new Dron(api,Wektor<double,3>(5,5,5)));
    std::shared_ptr<Dron> D3(new Dron(api,Wektor<double,3>(3,-3,-3)));
    std::vector<std::shared_ptr<Dron> > kolekcja_dronow;
    kolekcja_dronow.push_back(D1);
    kolekcja_dronow.push_back(D2);
    kolekcja_dronow.push_back(D3);
    Wektor<double,3> Srodek_D1 = kolekcja_dronow[0]->getSrodek();
    Wektor<double,3> Srodek_D2 = kolekcja_dronow[1]->getSrodek();
    Wektor<double,3> Srodek_D3 = kolekcja_dronow[2]->getSrodek();
    int wybierz_drona;
    std::shared_ptr<Dron> ktorym_sterujemy = kolekcja_dronow[0];
    for (;;)
    {
        cout << "==MENU==" << endl;
        cout << "w - Przod\n" /*<< "s - tyl\n"*/ << "q - Zanuzenie/Wynuzenie\n" /*<< "e - dol\n" */<< "r - Rotacja\n" << "z - Zmien drona\n" <<"p - Wyjscie\n" << endl;
        cin >> wybor;
        switch (wybor)
        {
            case 'w':  //przod
            {
                cout << "Podaj odleglosc: " << endl;
                cin >> odleglosc;
                if(!cin.good())
                {
                    std::cerr << "Zle podana odleglosc" << endl;
                    cin.clear();
                    exit(1);
                }
                ktorym_sterujemy->Przod(odleglosc);//, kolekcja_przeszkod);
                break;
            }
            /*
            case 's': // tyl
            {
                cout << "Podaj odleglosc: "<< endl;
                cin >> odleglosc;
                if(!cin.good())
                {
                    std::cerr << "Zle podana odleglosc" << endl;
                    cin.clear();
                    exit(1);
                }
                D.Tyl(odleglosc);
                break;
            }
            */
            case 'q': // gora
            {
                cout << "Podaj kat i odleglosc:" << endl << "Kat: ";
                cin >> kat;
                if(!cin.good())
                {
                    std::cerr << "Zle podany kat" << endl;
                    cin.clear();
                    exit(1);
                }
                cout << "Odleglosc: ";
                cin >> odleglosc;
                if(!cin.good())
                {
                    std::cerr << "Zle podana odleglosc" << endl;
                    cin.clear();
                    exit(1);
                }
                ktorym_sterujemy->Gora(kat,odleglosc);
                break;
            }
            /*
            case 'e': // dol
            {
                cout << "Podaj kat i odleglosc:" << endl << "Kat: ";
                cin >> kat;
                if(!cin.good())
                {
                    std::cerr << "Zle podany kat" << endl;
                    cin.clear();
                    exit(1);
                }
                cout << "Odleglosc: ";
                cin >> odleglosc;
                if(!cin.good())
                {
                    std::cerr << "Zle podana odleglosc" << endl;
                    cin.clear();
                    exit(1);
                }
                D.Dol(kat,odleglosc);
                break;
            }
            */
            case 'r': //rotacja
            {
                cout << "Podaj kat obrotu: " << endl;
                cin >> kat;
                if(!cin.good())
                {
                    std::cerr << "Zle podany kat" << endl;
                    cin.clear();
                    exit(1);
                }
                cout << "Podaj os obrotu(x,y,z): " << endl;
                cin >> os;
                switch(os)
                {
                    case 'x':
                    {
                        ktorym_sterujemy->Rotacja('x',kat);
                        break;
                    }
                    case 'y':
                    {
                        ktorym_sterujemy->Rotacja('y',kat);
                        break;
                    }
                    case 'z':
                    {
                        ktorym_sterujemy->Rotacja('z',kat);
                        break;
                    }
                    default:
                    {
                        cout << "Podana os nie istnieje" << endl;
                    }
                }
                break;
            }
            case 'z':
            {
                cout << "Wybierz drona 1 2 lub 3: " << endl;
                cout << "1 - ten ktory na poczatku srodek mial w : " << Srodek_D1 << endl;
                cout << "2 - ten ktory na poczatku srodek mial w : " << Srodek_D2 << endl;
                cout << "3 - ten ktory na poczatku srodek mial w : " << Srodek_D3 << endl;
                cin >> wybierz_drona;
                if(!cin.good())
                {
                    std::cerr << "Zle podany dron" << endl;
                    cin.clear();
                    exit(1);
                }
                ktorym_sterujemy = kolekcja_dronow[wybierz_drona-1];
                break;
            }
            case 'p':
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
        cout << "Ilosc utworzonych wektorow: "<< Wektor<double,3>::GetUtworzone() << endl << "Ilosc istniejacych wektorow: " << Wektor<double,3>::GetIstniejace() << endl;
        cout << "Ilosc utworzonych bryl: " << Bryla::GetUtworzone()+Przeszkoda_Prostopadloscian::GetUtworzone() << endl << "Ilosc istniejacych bryl: " << Bryla::GetIstniejace() + Przeszkoda_Prostopadloscian::GetIstniejace() << endl;
        cout << endl;
    }

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
}
