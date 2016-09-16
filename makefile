main:	main.o Funcion.o Butaca.o
	g++ main.o Funcion.o Butaca.o -o cine

main.o:	main.cpp Funcion.h Butaca.h
	g++ -c main.cpp 

Funcion.o:	Funcion.cpp Funcion.h Butaca.h
	g++ -c Funcion.cpp	

Butaca.o:	Butaca.cpp Butaca.h
	g++ -c Butaca.cpp