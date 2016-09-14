#pragma once
#include "Butaca.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Butaca::Butaca(){
	this->estado = true;
	this->marca = '_';
}

Butaca::~Butaca(){

}

void Butaca::setEstado(bool estado){
	this->estado = estado;
}

bool Butaca::getEstado(){
	return this->estado;
}

void Butaca::setMarca(char marca){
	this->marca = marca;
}

char Butaca::getMarca(){
	return this->marca;
}

bool Butaca::butacaVacia(){
	return this->estado;
}

void Butaca::ocuparButaca(){
	this->estado = false;
	this->marca = 'X';
}

