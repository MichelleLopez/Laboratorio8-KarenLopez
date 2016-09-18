#include "Butaca.h"
#include "Funcion.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


Funcion::Funcion(int sala, int horaI, int minI, int horaF, int minF){
	this->sala = sala;
	this->horaI = horaI;
	this->horaF = horaF;


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
void Funcion::setSala(int sala){
	this->sala = sala;
}
int Funcion::getHoraI(){
	return this->horaI;
}
void Funcion::setHoraI(int horaI){
	this->horaI = horaI;
}

void Funcion::setMinI(int minI){
	this->minI = minI;
}

int Funcion::getHoraF(){
	return this->horaF;
}
void Funcion::setMinF(int minF){
	this->minF = minF;
}
void Funcion::setHoraF(int horaF){
	this->horaF = horaF;
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
							cout<<"Butaca reservada correctamente"<<endl;
						}
						else{
							cout<<"Butaca reservada, por favor seleccione otra"<<endl;
							flag = true;
						}
						break;

					case 'B':
					case 'b':
						if (this->filaB.at(columna - 1)->butacaVacia()){
							flag = true;
							this->filaB.at(columna - 1)->ocuparButaca();
							cout<<"Butaca reservada correctamente"<<endl;
						}
						else{
							cout<<"Butaca reservada, por favor seleccione otra"<<endl;
							flag = true;
						}
						break;

					case 'C':
					case 'c':
						if (this->filaC.at(columna - 1)->butacaVacia()){
							flag = true;
							this->filaC.at(columna - 1)->ocuparButaca();
							cout<<"Butaca reservada correctamente"<<endl;
						}
						else{
							cout<<"Butaca reservada, por favor seleccione otra"<<endl;
							flag = true;
						}
						break;
					case 'D':
					case 'd':

						if (this->filaD.at(columna - 1)->butacaVacia()){
							flag = true;
							this->filaD.at(columna - 1)->ocuparButaca();
							cout<<"Butaca reservada correctamente"<<endl;
							break;
						}
						else{
							cout<<"Butaca reservada, por favor seleccione otra"<<endl;
							flag = true;
						}
						break;
					case 'E':
					case 'e':
						if (this->filaE.at(columna - 1)->butacaVacia()){
							flag = true;
							this->filaE.at(columna - 1)->ocuparButaca();
							cout<<"Butaca reservada correctamente"<<endl;
						}
						else{
							cout<<"Butaca reservada, por favor seleccione otra"<<endl;
							flag = true;
						}
						break;

					default:
						cout<<"Fila incorrecta, seleccione otra"<<endl;
						flag = true;
						break;
				}
			}
			else{
				cout<<"Columna incorrecta, seleccione otra"<<endl;
				flag = true;
				break;
			}
		}
	}
	else{
		cout<<"No hay cupo en esta funcion"<<endl;
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
	cout<<"    1 2 3 4 5"<<endl;	
	cout<<a<<" |"<<endl;
	cout<<b<<" |"<<endl;
	cout<<c<<" |"<<endl;
	cout<<d<<" |"<<endl;
	cout<<e<<" |"<<endl;

}

string Funcion::toString(){
	stringstream ss;
	char cero1 = ' ';
	char cero2 = ' ';
	char cero3 = ' ';
	char cero4 = ' ';
	if (horaI < 10)
	{
		cero1 = '0';
	}
	if (horaF < 10)
	{
		cero2 = '0';
	}
	if (minI < 10)
	{
		cero3 = '0';
	}
	if (minF < 10)
	{
		cero4 = '0';
	}
	ss<<sala<<"\t"<<cero1<<this->horaI<<":"<<cero3<<minI<<"\t\t"<<cero2<<this->horaF<<":"<<cero3<<minF;
	return ss.str();
}