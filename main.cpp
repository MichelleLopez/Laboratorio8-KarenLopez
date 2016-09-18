#include "Butaca.h"
#include "Funcion.h"
#include "Pelicula.h"
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;
using std::string;
bool validarInt(int);

int main(int argc, char const *argv[])
{
	int opcion = 0, opcion2 = 0;
	vector<Pelicula*> listaPeliculas;
	int cont = 0;
	listaPeliculas.push_back(new Pelicula("Interstellar"));
	listaPeliculas.push_back(new Pelicula("American Story X"));
	listaPeliculas.push_back(new Pelicula("Into the Wild"));

	do{
		cout<<"*******************Gestion de Cine******************"<<endl;
		cout<<"Elija una opción:"<<endl;
		cout<<"1. Gestión de Pelicula"<<endl;
		cout<<"2. Gestión de Funciones"<<endl;
		cout<<"3. Vender un boleto"<<endl;
		cout<<"4. Salir"<<endl;
		cin>>opcion;
		
		if (cin.fail())
		{
			opcion = 0;
			cin.clear();
			cin.ignore(1024, '\n');
		}
		string name;
		int pelicula = 0, funcion = 0, columna = 0;
		Funcion* tempFuncion;
		char fila;
		int sala, horaI, horaF, minI, minF, anio, mes, dia;
		switch(opcion){
			case 1:
				do{
					cout<<"Seleccione una opción:"<<endl;
					cout<<"1. Agregar una Película"<<endl;
					cout<<"2. Modificar un pelicula"<<endl;
					cout<<"3. Borrar Película"<<endl;
					cout<<"4. Regresar"<<endl;
					cin>>opcion2;
					if (cin.fail())
					{
						opcion2 = 0;
						cin.clear();
						cin.ignore(1024, '\n');
					}

					switch(opcion2){
						case 1:
							cout<<"Ingrese el nombre de la Pelicula: ";
							getline(cin, name, '\n');
							getline(cin, name, '\n');
							listaPeliculas.push_back(new Pelicula(name));
							cout<<endl<<"Pelicula agregada correctamente"<<endl;
							break;

						case 2:
							if (listaPeliculas.size() == 0)
							{
								cout<<"No hay peliculas";
							}
							else{
								cout<<"¿Qué película desea modificar?"<<endl;
								for (int i = 0; i < listaPeliculas.size(); ++i)
								{
									cout<<i+1<<". "<<listaPeliculas.at(i)->getName()<<endl;
								}
								cin>>pelicula;

								cout<<"Escriba el nuevo nombre: ";
								getline(cin, name, '\n');
								getline(cin, name, '\n');
								listaPeliculas.at(pelicula - 1)->setName(name);
								cout<<"\nModificado correctamente"<<endl<<listaPeliculas.at(pelicula - 1)->getName();
							}
							break;
						case 3: 
							if (listaPeliculas.size() == 0)
							{
								cout<<"No hay peliculas";
							}
							else{
								cout<<"¿Qué película desea borrar?"<<endl;
								for (int i = 0; i < listaPeliculas.size(); ++i)
								{
									cout<<i+1<<". "<<listaPeliculas.at(i)->getName()<<endl;
								}
								cin>>pelicula;
								
								listaPeliculas.erase(listaPeliculas.begin() + pelicula - 1);
								cout<<"Pelicula borrada con éxito"<<endl;
							}
							break;
						case 4:
						break;
						default: 
							cout<<"Opción incorrecta"<<endl;
							break;
						}
				}while(opcion2 !=4);
				break;

			case 2:
				do{
					cout<<"Seleccione una opción:"<<endl;
					cout<<"1. Agregar una función"<<endl;
					cout<<"2. Modificar una función"<<endl;
					cout<<"3. Borrar una función"<<endl;
					cout<<"4. Regresar"<<endl;
					cin>>opcion2;
					if (cin.fail())
					{
						opcion2 = 0;
						cin.clear();
						cin.ignore(1024, '\n');
					}
					switch(opcion2){
						case 1:
							cout<<"¿A qué película desea agregar la función?"<<endl;
							for (int i = 0; i < listaPeliculas.size(); ++i)
							{
								cout<<i+1<<". "<<listaPeliculas.at(i)->getName()<<endl;
							}
							cin>>pelicula;
							cout<<"Seleccione la función: "<<endl;
							listaPeliculas.at(pelicula - 1)->mostrarFunciones();
							cin>>funcion;
							cout<<"Ingrese el número de sala: ";
							cin>>sala;
							cout<<"Ingrese la hora inicio (0-23): ";
							cin>>horaI;
							cout<<"Ingrese los minutos (0-59): ";
							cin>>minI;
							cout<<"Ingrese la hora de finalización (0-23): ";
							cin>>horaF;
							cout<<"Ingrese los minutos: (0-59)";
							cin>>minF;
							
							tempFuncion = new Funcion(sala, horaI, minI, horaF, minF);
							listaPeliculas.at(pelicula - 1)->setListaFunciones(tempFuncion);
							break;
						case 2:
							cout<<"¿De qué película desea modificar la función?"<<endl;
							for (int i = 0; i < listaPeliculas.size(); ++i)
							{
								cout<<i+1<<". "<<listaPeliculas.at(i)->getName()<<endl;
							}
							cin>>pelicula;
							cout<<"Seleccione la función: "<<endl;
							listaPeliculas.at(pelicula - 1)->mostrarFunciones();
							cin>>funcion;
							tempFuncion = listaPeliculas.at(pelicula - 1)->getListaFunciones(funcion - 1);
							cout<<"Ingrese el número de sala: ";
							cin>>sala;
							tempFuncion->setSala(sala);
							cout<<"Ingrese la hora inicio : ";
							cin>>horaI;
							tempFuncion->setHoraI(horaI);
							cout<<"Ingrese los minutos: ";
							cin>>minI;
							tempFuncion->setMinI(minI);
							cout<<"Ingrese la hora de finalización: ";
							cin>>horaF;
							tempFuncion->setHoraF(horaF);
							cout<<"Ingrese los minutos: ";
							cin>>minF;
							tempFuncion->setMinF(minF);
							break;

						case 3: 
							cout<<"¿De qué película desea eliminar la función?"<<endl;
							for (int i = 0; i < listaPeliculas.size(); ++i)
							{
								cout<<i+1<<". "<<listaPeliculas.at(i)->getName()<<endl;
							}
							cin>>pelicula;
							cout<<"Seleccione la función: "<<endl;
							listaPeliculas.at(pelicula - 1)->mostrarFunciones();
							cin>>funcion;
							listaPeliculas.at(pelicula-1)->eraseFuncion(funcion-1);
							cout<<"Borrado correctamente";
							break;	
						default: 
						cout<<"Opción incorrecta"<<endl;
						break;

					}
				}while(opcion2!=4);
				break;
			
			case 3:
				cout<<"****************Venta de Boletos*****************"<<endl;
				if (listaPeliculas.size() == 0)
				{
					cout<<"No hay peliculas"<<endl;
				}
				else{
					cout<<"Seleccione la pelicula: "<<endl;
					for (int i = 0; i < listaPeliculas.size(); ++i)
					{
						cout<<i+1<<". "<<listaPeliculas.at(i)->getName()<<endl;
					}
					cin>>pelicula;

					if (listaPeliculas.at(pelicula - 1)->hayFuncion())
					{
						cout<<"Seleccione la función: "<<endl;
						listaPeliculas.at(pelicula - 1)->mostrarFunciones();
						cin>>funcion;
						if (listaPeliculas.at(pelicula - 1)->getListaFunciones(funcion - 1)->hayCupo())
						{
							listaPeliculas.at(pelicula - 1)->getListaFunciones(funcion - 1)->printButacas();
							cout<<"\n Escriba la letra de fila: ";
							cin>>fila;
							cout<<"\n Escriba el numero de columna: ";
							cin>>columna;
							listaPeliculas.at(pelicula - 1)->elegirFuncion(funcion, fila, columna);
						}else{
							cout<<"No hay cupo en esta funcion"<<endl;
						}
					}else{
						cout<<"No hay funciones para esa pelicula"<<endl;
					}	
				}
				break;	
			case 4:
				break;
			default: 
				cout<<"Opción incorrecta"<<endl;
				break;		
		}

	}while(opcion !=4);
	return 0;
}