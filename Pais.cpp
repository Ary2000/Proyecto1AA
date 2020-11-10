#include "Pais.h"

Pais::Pais(std::string nombre) { this->nombre = nombre; }

void Pais::anadirPaisAdyacente(Pais* paisAdyacente) { paisesAdyacente.push_back(paisAdyacente); }

void Pais::marcarAdyacentes()
{
    visitadoRegiones = true;
    for(auto iteradorAdyacentes = paisesAdyacente.begin(); iteradorAdyacentes != paisesAdyacente.end(); iteradorAdyacentes++)
        if((*iteradorAdyacentes)->visitadoRegiones == false)
            (*iteradorAdyacentes)->marcarAdyacentes();
}