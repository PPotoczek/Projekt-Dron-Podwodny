cmake_minimum_required(VERSION 3.15)
project(ProjektDron)

set(CMAKE_CXX_FLAGS -pthread)

add_executable(ProjektDron main.cpp Dr3D_gnuplot_api.cpp Dr3D_gnuplot_api.hh Draw3D_api_interface.hh Bryla.cpp Bryla.hh Prostopadloscian.cpp Prostopadloscian.hh Dron.cpp Dron.hh MacierzKw.cpp MacierzKw.hh Macierz_Obrotu.cpp Macierz_Obrotu.hh Wektor.cpp Wektor.hh Wektor3D.cpp Wektor3D.hh Powierzchnia.h Szesciakat.hh Szesciakat.cpp "Interfejs rysowania.h")