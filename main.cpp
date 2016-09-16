#include "Butaca.h"
#include "Funcion.h"
#include "Pelicula.h"
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;
using std::string;

int main(int argc, char const *argv[])
{
	int opcion = 0;
	vector<Pelicula*> listaPeliculas;

	listaPeliculas.push_back(new Pelicula("Interstellar"));
	listaPeliculas.push_back(new Pelicula("American Story X"));
	listaPeliculas.push_back(new Pelicula("Into the Wild"));

	do{
		cout<<"*******************Gestion de Cine******************"<<endl;
		cout<<"Elija una opción:"<<endl;
		cout<<"1. Agregar una Pelicula"<<endl;
		cout<<"2. Agregar una Funcion"<<endl;
		cout<<"3. Agregar una Pelicula"<<endl;
		cout<<"4. Agregar una Funcion"<<endl;
		cout<<"5. Vender un boleto"<<endl;
		cout<<"6. Salir"<<endl;
		cin>>opcion;
		string name;
		int pelicula = 0, funcion = 0, columna = 0;
		char fila;
		int sala, horaI, horaF, minI, minF, anio, mes, dia;
		switch(opcion){
			case 1:
				cout<<"Ingrese el nombre de la Pelicula: ";
				cin>>name;
				listaPeliculas.push_back(new Pelicula(name));
				cout<<endl<<"Pelicula agregada correctamente"<<endl;
				break;

			case 2:
				cout<<"¿De qué película desea agregar la nueva función?"<<endl;
				for (int i = 0; i < listaPeliculas.size(); ++i)
				{
					cout<<i+1<<". "<<listaPeliculas.at(i)->getName()<<endl;
				}
				cin>>pelicula;
				cout<<"Ingrese el número de sala: ";
				cin>>sala;
				cout<<"Ingrese la hora inicio : ";
				cin>>horaI;
				cout<<"Ingrese los minutos: ";
				cin>>minI;
				cout<<"Ingrese la hora de finalización: ";
				cin>>horaF;
				cout<<"Ingrese los minutos: ";
				cin>>minF;
				cout<<"Ingrese el anio: ";
				cin>>anio;
				cout<<"Ingrese el mes: ";
				cin>>mes;
				cout<<"Ingrese el día: ";
				cin>>dia;
				Funcion* tempFuncion;
				tempFuncion = new Funcion(sala, horaI, minI, horaF, minF, anio, mes, dia);
				listaPeliculas.at(pelicula - 1)->setListaFunciones(tempFuncion);
			break;
			case 5:
				cout<<"****************Venta de Boletos*****************"<<endl;
				cout<<"Seleccione la pelicula: "<<endl;
				for (int i = 0; i < listaPeliculas.size(); ++i)
				{
					cout<<i+1<<". "<<listaPeliculas.at(i)->getName()<<endl;
				}
				cin>>pelicula;
				cout<<"Seleccione la función: "<<endl;
				listaPeliculas.at(pelicula - 1)->mostrarFunciones();
				cin>>funcion;
				listaPeliculas.at(pelicula - 1)->getListaFunciones(funcion - 1)->printButacas();
				cout<<"\n Escriba la letra de fila: ";
				cin>>fila;
				cout<<"\n Escriba el numero de columna: ";
				cin>>columna;
				listaPeliculas.at(pelicula - 1)->elegirFuncion(funcion, fila, columna);
				break;				

		}
	}while(opcion !=6);
	return 0;
}