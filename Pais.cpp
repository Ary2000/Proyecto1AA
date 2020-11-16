#include "Pais.hpp"

Pais::Pais(std::string nombre) { this->nombre = nombre; }

void Pais::anadirPaisAdyacente(Pais* paisAdyacente)
{ 
    bool seEncontro = false;
    for(auto iteradorPaisesAdyacentes = paisesAdyacente.begin(); iteradorPaisesAdyacentes != paisesAdyacente.end(); iteradorPaisesAdyacentes++)
    {
        if(*iteradorPaisesAdyacentes == paisAdyacente)
        {
            seEncontro = true;
            break;
        }
    }
    if(!seEncontro)
        paisesAdyacente.push_back(paisAdyacente);
}