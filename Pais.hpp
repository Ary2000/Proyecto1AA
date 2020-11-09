#pragma once

#include <string>
#include <vector>

class Pais
{
//private:
public:
	std::string nombre;
	std::vector<Pais*> paisesAdyacente;

//public:
	Pais(std::string nombre);
	void anadirPaisAdyacente(Pais* paisAdyacente);

};

