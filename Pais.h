#ifndef PAIS_H
#define PAIS_H

#include <string>
#include <vector>

#include "pugixml.hpp"

class Pais
{
private:
	pugi::xml_node nodeDV;
	pugi::xml_node nodePD;
	pugi::xml_node nodeBT;
public:
	std::string nombre;
	std::vector<Pais*> paisesAdyacente;
	bool visitadoRegiones;
	bool pasadoBT;
	int colorBT;

	Pais(std::string nombre, pugi::xml_node nodeDV, pugi::xml_node nodePD, pugi::xml_node nodeBT);
	void anadirPaisAdyacente(Pais* paisAdyacente);
	bool haSidoVisitado() { return visitadoRegiones; }
	int marcarAdyacentes();

	//set
	void setVisitadoBT(bool estadoNuevo) { pasadoBT = estadoNuevo; }

	//get
	bool fueVisitadoBT() { return pasadoBT; }

};

#endif