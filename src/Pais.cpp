#include "include/Pais.h"

Pais::Pais(std::string nombre) { this->nombre = nombre; }

void Pais::anadirPaisAdyacente(Pais* paisAdyacente) { paisesAdyacente.push_back(paisAdyacente); }