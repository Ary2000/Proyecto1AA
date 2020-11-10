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
	bool visitadoRegiones = false;

//public:
	Pais(std::string nombre);
	void anadirPaisAdyacente(Pais* paisAdyacente);
	bool haSidoVisitado() { return visitadoRegiones; }
	void marcarAdyacentes();

};

#endif