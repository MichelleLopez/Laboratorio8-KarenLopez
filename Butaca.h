#pragma once

class Butaca{
private:
	bool estado;
	char marca;

public:
	Butaca();
	~Butaca();
	void setEstado(bool);
	bool getEstado();
	void setMarca(char);
	char getMarca();
	void ocuparButaca();
	bool butacaVacia();
};