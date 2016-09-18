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
	int sala, horaI, horaF, minI, minF;
	vector<Butaca*> filaA;
	vector<Butaca*> filaB;
	vector<Butaca*> filaC;
	vector<Butaca*> filaD;
	vector<Butaca*> filaE;

public:
	Funcion();
	Funcion(int, int, int, int, int);
	~Funcion();
	void setSala(int);
	void setHoraI(int);
	void setHoraF(int);
	void setMinI(int);
	void setMinF(int);

	int getSala();
	int getHoraI();
	int getHoraF();


	bool hayCupo();
	void printButacas();
	bool seleccionarButaca(char, int);
	string toString();

};