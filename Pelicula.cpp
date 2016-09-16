
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

void Pelicula::mostrarFunciones(){
	cout<<"Opcion\tSala\tHora Inicio\t Hora Fin\t Fecha\n";
	for (int i = 0; i < this->listaFunciones.size(); ++i)
	{
		cout<<i+1<<"\t"<<this->listaFunciones.at(i)->toString()<<endl;
	}
}

bool Pelicula::elegirFuncion(int opcion, char fila, int columna){
	bool flag1 = false;
	bool flag2 = false;
	while(!flag1){
		for (int i = 0; i < listaFunciones.size(); ++i)
		{
			if (this->listaFunciones.at(i)->hayCupo())
			{
				flag2 = true;
				break;
			}
		}

		if (flag2)
		{
			if (opcion>=1 && opcion<=this->listaFunciones.size())
			{
				flag1 = this->listaFunciones.at(opcion - 1)->seleccionarButaca(fila, columna);
				if (flag1)
				{
					flag2 = true;
					break;
				}
			}
			else {
				cout<<"Opcion invalida"<<endl;
			}
		}
		else{
			cout<<"Ya no hay cupos para esa pelicula, seleccione otra"<<endl;
			flag1 = true;
		}
	}
	return flag2;
}