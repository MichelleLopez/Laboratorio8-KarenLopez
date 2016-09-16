#include "Butaca.h"
#include "Funcion.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


Funcion::Funcion(int sala, int horaI, int minI, int horaF, int minF, int anio, int mes, int dia){
	this->sala = sala;
	this->horaI = horaI;
	this->horaF = horaF;
	this->anio = anio;
	this->mes = mes;
	this->dia = dia;

	for (int i = 0; i < 5; ++i)
	{
		this->filaA.push_back(new Butaca());
		this->filaB.push_back(new Butaca());
		this->filaC.push_back(new Butaca());
		this->filaD.push_back(new Butaca());
		this->filaE.push_back(new Butaca());
	}
}

Funcion::Funcion(){}

Funcion::~Funcion(){}

int Funcion::getSala(){
	return this->sala;
}

int Funcion::getHoraI(){
	return this->horaI;
}

int Funcion::getHoraF(){
	return this->horaF;
}

int Funcion::getAnio(){
	return this->anio;
}
int Funcion::getMes(){
	return this->mes;
}
int Funcion::getDia(){
	return this->dia;
}

bool Funcion::hayCupo(){
	bool flag = false;
	for (int i = 0; i < 5; ++i)
	{
		if (this->filaA.at(i)->butacaVacia())
		{
			flag = true;
		}
		if (this->filaB.at(i)->butacaVacia())
		{
			flag = true;
		}
		if (this->filaC.at(i)->butacaVacia())
		{
			flag = true;
		}
		if (this->filaD.at(i)->butacaVacia())
		{
			flag = true;
		}
		if (this->filaE.at(i)->butacaVacia())
		{
			flag = true;
		}
	}
	return flag;
}

bool Funcion::seleccionarButaca(char fila, int columna){
	bool flag = false;
	if (this->hayCupo())
	{
		while(!flag){
			if (columna >=1 && columna <=5)
			{
				switch(fila){
					case 'A':
					case 'a':
						if (this->filaA.at(columna - 1)->butacaVacia()){
							flag = true;
							this->filaA.at(columna - 1)->ocuparButaca();
							cout<<"Butaca reservada correctamente";
						}
						else{
							cout<<"Butaca reservada, por favor seleccione otra";
						}
					case 'B':
					case 'b':
						if (this->filaB.at(columna - 1)->butacaVacia()){
							flag = true;
							this->filaB.at(columna - 1)->ocuparButaca();
							cout<<"Butaca reservada correctamente";
						}
						else{
							cout<<"Butaca reservada, por favor seleccione otra";
						}
					case 'C':
					case 'c':
						if (this->filaC.at(columna - 1)->butacaVacia()){
							flag = true;
							this->filaC.at(columna - 1)->ocuparButaca();
							cout<<"Butaca reservada correctamente";
						}
						else{
							cout<<"Butaca reservada, por favor seleccione otra";
						}
					case 'D':
					case 'd':

						if (this->filaD.at(columna - 1)->butacaVacia()){
							flag = true;
							this->filaD.at(columna - 1)->ocuparButaca();
							cout<<"Butaca reservada correctamente";
						}
						else{
							cout<<"Butaca reservada, por favor seleccione otra";
						}
					case 'E':
					case 'e':
						if (this->filaE.at(columna - 1)->butacaVacia()){
							flag = true;
							this->filaE.at(columna - 1)->ocuparButaca();
							cout<<"Butaca reservada correctamente";
						}
						else{
							cout<<"Butaca reservada, por favor seleccione otra";
						}
					default:
						cout<<"Columna incorrecta, seleccione otra";
				}
			}
			else{
				cout<<"Fila incorrecta, seleccione otra";
			}
		}
	}
	else{
		cout<<"No hay cupo en esta funcion";
	}
	
	return flag;
}

void Funcion::printButacas(){
	string a = "A | ";
	string b = "B | ";
	string c = "C | ";
	string d = "D | ";
	string e = "E | ";
	for (int i = 0; i < 5; i++)
	{
		a = a + filaA.at(i)->getMarca() + " ";
		b = b + filaB.at(i)->getMarca() + " ";
		c = c + filaC.at(i)->getMarca() + " ";
		d = d + filaD.at(i)->getMarca() + " ";
		e = e + filaE.at(i)->getMarca() + " ";
	}
	cout<<"    1 2 3 4 5";	
	cout<<a<<" |"<<endl;
	cout<<b<<" |"<<endl;
	cout<<c<<" |"<<endl;
	cout<<d<<" |"<<endl;
	cout<<e<<" |"<<endl;

}

string Funcion::toString(){
	stringstream ss;
	cout<<"Sala\tHora Inicio\t Hora Fin\t Fecha\n";
	ss<<sala<<"\t"<<this->horaI<<":"<<minI<<"\t"<<this->horaF<<":"<<minF<<"\t"<<dia<<"/"<<mes<<"/"<<anio;
	return ss.str();
}