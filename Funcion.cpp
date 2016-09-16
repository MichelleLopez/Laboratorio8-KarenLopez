#include "Butaca.h"
#include "Funcion.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using std::vector;
using std::string;

Funcion::Funcion(int sala, int horaI, int horaF, int minI, int minF, int anio, int mes, int dia){
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