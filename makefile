main:	main.o Pelicula.o Funcion.o Butaca.o
	g++ main.o Pelicula.o Funcion.o Butaca.o -o cine

main.o:	main.cpp Pelicula.h Funcion.h Butaca.h
	g++ -c main.cpp 

Pelicula.o:	Pelicula.cpp Pelicula.h Funcion.h Butaca.h
	g++ -c Pelicula.cpp	

Funcion.o:	Funcion.cpp Funcion.h Butaca.h
	g++ -c Funcion.cpp	

Butaca.o:	Butaca.cpp Butaca.h
	g++ -c Butaca.cpp