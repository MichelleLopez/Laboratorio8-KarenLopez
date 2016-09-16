#pragma once
#include "Butaca.h"
#include <vector>
#include <string>
#include <sstream>

using std::vector;
using std::string;
using std::stringstream;

class Funcion{
private:
	int sala, horaI, horaF, minI, minF, anio, mes, dia;
	vector<Butaca*> filaA;
	vector<Butaca*> filaB;
	vector<Butaca*> filaC;
	vector<Butaca*> filaD;
	vector<Butaca*> filaE;

public:
	Funcion();
	Funcion(int, int, int, int, int, int, int, int);
	~Funcion();
	void setSala(int);
	void setHoraI(int);
	void setHoraF(int);
	void setAnio(string);
	void setMes(string);
	void setDia(string);

	int getSala();
	int getHoraI();
	int getHoraF();
	int getAnio();
	int getMes();
	int getDia();

	bool hayCupo();
	void printButacas();
	bool seleccionarButaca();
	string toString();

};