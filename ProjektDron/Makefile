CPPFLAGS= -c -g -Wall -pedantic -std=c++17

__start__: main.out
	./main.out

main.out: Dr3D_gnuplot_api.o main.o
	g++ -o main.out main.o Dr3D_gnuplot_api.o -lpthread

main.o: main.cpp Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o main.o main.cpp

Dr3D_gnuplot_api.o: Dr3D_gnuplot_api.cpp Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o Dr3D_gnuplot_api.o Dr3D_gnuplot_api.cpp

Dr3D_gnuplot_api.hh: Draw3D_api_interface.hh
	touch Dr3D_gnuplot_api.hh

clear:
	rm main.out main.o Dr3D_gnuplot_api.o
