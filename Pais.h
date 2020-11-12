#ifndef PAIS_H
#define PAIS_H

#include <string>
#include <vector>

class Pais
{
//private:
public:
	std::string nombre;
	std::vector<Pais*> paisesAdyacente;
	bool visitadoRegiones;
	bool pasadoBT;
	int colorBT;

	Pais(std::string nombre);
	void anadirPaisAdyacente(Pais* paisAdyacente);
	bool haSidoVisitado() { return visitadoRegiones; }
	int marcarAdyacentes();

	//set
	void setVisitadoBT(bool estadoNuevo) { pasadoBT = estadoNuevo; }

	//get
	bool fueVisitadoBT() { return pasadoBT; }

};

#endif