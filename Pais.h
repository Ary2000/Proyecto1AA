#ifndef PAIS_H
#define PAIS_H

#include <string>
#include <vector>

#include "pugixml.hpp"

class Pais
{
private:
	pugi::xml_attribute attrDV;
	pugi::xml_attribute attrPD;
	pugi::xml_attribute attrBT;
public:
	std::string nombre;
	std::vector<Pais*> paisesAdyacente;
	bool visitadoRegiones;
	bool pasadoBT;
	int indexBT = -1;
	int colorBT = -1;

	Pais(std::string nombre, pugi::xml_attribute attrDV, pugi::xml_attribute attrPD, pugi::xml_attribute attrBT);
	Pais(std::string nombre) { this->nombre = nombre; }
	void anadirPaisAdyacente(Pais* paisAdyacente);
	bool haSidoVisitado() { return visitadoRegiones; }
	int marcarAdyacentes();
	void pintarPaisBT(std::string colorAPoner) { attrBT.set_value("colorAPoner"); }

	//set
	void setVisitadoBT(bool estadoNuevo) { pasadoBT = estadoNuevo; }
	void setIndexBT(int indexBT) { this->indexBT = indexBT; }

	//get
	bool fueVisitadoBT() { return pasadoBT; }

};

#endif