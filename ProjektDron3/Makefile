CPPFLAGS= -c -g -Wall -pedantic -std=c++17

__start__: main.out
	./main.out

main.out: Dr3D_gnuplot_api.o main.o
	g++ -o main.out main.o Dr3D_gnuplot_api.o -lpthread

main.o: main.cpp Dron.hh Powierzchnia.hh Przeszkoda_Prostopadloscian.hh
	g++ ${CPPFLAGS} -o main.o main.cpp

Dr3D_gnuplot_api.o: Dr3D_gnuplot_api.cpp Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o Dr3D_gnuplot_api.o Dr3D_gnuplot_api.cpp

Dr3D_gnuplot_api.hh: Draw3D_api_interface.hh
	touch Dr3D_gnuplot_api.hh

Powierzchnia.hh: Interfejs_rysowania.hh
	touch Powierzchnia.hh

Interfejs_rysowania.hh: Dr3D_gnuplot_api.hh Draw3D_api_interface.hh
	touch Interfejs_rysowania.hh

Bryla.hh: Interfejs_rysowania.hh Macierz_Obrotu.hh
	touch Bryla.hh

Macierz_Obrotu.hh: MacierzKw.hh
	touch Macierz_Obrotu.hh

MacierzKw.hh: Wektor.hh
	touch MacierzKw.hh

Wektor.hh:
	touch Wektor.hh

Prostopadloscian.hh: Bryla.hh
	touch Prostopadloscian.hh

Dron.hh: Prostopadloscian.hh Interfejs_Drona.hh Wirnik.hh Przeszkoda.hh
	touch Dron.hh

Wirnik.hh: Szesciakat.hh
	touch Wirnik.hh

Szesciakat.hh: Bryla.hh
	touch Szesciakat.hh

Interfejs_Drona.hh:
	touch Interfejs_Drona.hh

Przeszkoda.hh: Dron.hh
	touch Przeszkoda.hh

Przeszkoda_prostopadloscian: Interfejs_rysowania.hh Przeszkoda.hh
	touch Przeszkoda_prostopadloscienna



clear:
	rm main.out main.o Dr3D_gnuplot_api.o
