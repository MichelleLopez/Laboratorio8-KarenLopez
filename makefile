main: main.o Butaca.o
	g++ main.o Butaca.o -o cine

main.o: main.cpp Butaca.h
	g++ -c main.cpp 

Butaca.o:	Butaca.cpp Butaca.h
	g++ -c Butaca.cpp