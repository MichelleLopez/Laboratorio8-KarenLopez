
#include "Pelicula.h"
#include "Funcion.h"
#include "Butaca.h"
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

Pelicula::Pelicula(){}
Pelicula::~Pelicula(){}

Pelicula::Pelicula(string name){
	this->name = name;
	this->listaFunciones.push_back(new Funcion(1, 13, 30, 15, 30, 2016, 8, 15));
	this->listaFunciones.push_back(new Funcion(2, 16, 00, 18, 30, 2016, 8, 15));
}

void Pelicula::setName(string){
	this->name = name;
}

string Pelicula::getName(){
	return this->name;
}

void Pelicula::setListaFunciones(Funcion* funcion){
	this->listaFunciones.push_back(funcion);
}

Funcion* Pelicula::getListaFunciones(int i){
	return listaFunciones.at(i);
}