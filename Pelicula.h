#pragma once
#include "Funcion.h"
#include "Butaca.h"
#include <string>
#include <sstream>
#include <vector>
using std::string;
using std::vector;

class Pelicula
{
private:
	string name;
	vector<Funcion*> listaFunciones;

public:
	Pelicula();
	Pelicula(string);
	~Pelicula();
	void setName(string);
	string getName();
	void setListaFunciones(Funcion*);
	Funcion* getListaFunciones(int);
	void mostrarFunciones();
	bool elegirFuncion(int, char, int);
	string toString();
	
};