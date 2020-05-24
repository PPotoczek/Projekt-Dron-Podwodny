cmake_minimum_required(VERSION 3.15)
project(ProjektDron)

set(CMAKE_CXX_FLAGS -pthread)

add_executable(ProjektDron main.cpp Dr3D_gnuplot_api.cpp Dr3D_gnuplot_api.hh Draw3D_api_interface.hh Bryla.cpp Bryla.hh Prostopadloscian.cpp Prostopadloscian.hh Dron.cpp Dron.hh MacierzKw.cpp MacierzKw.hh Macierz_Obrotu.cpp Macierz_Obrotu.hh Wektor.cpp Wektor.hh Powierzchnia.hh Szesciakat.hh Szesciakat.cpp "Interfejs_rysowania.hh" Wirnik.hh)