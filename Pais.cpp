#include "Pais.h"

Pais::Pais(std::string nombre) 
{ 
    this->nombre = nombre; 
    this->visitadoRegiones = false;
    this->pasadoBT = false;
    this->colorBT = -1;
}

void Pais::anadirPaisAdyacente(Pais* paisAdyacente) { paisesAdyacente.push_back(paisAdyacente); }

int Pais::marcarAdyacentes()
{   
    int tamanoRegion = 1;
    visitadoRegiones = true;
    for(auto iteradorAdyacentes = paisesAdyacente.begin(); iteradorAdyacentes != paisesAdyacente.end(); iteradorAdyacentes++)
        if((*iteradorAdyacentes)->visitadoRegiones == false)
            tamanoRegion += (*iteradorAdyacentes)->marcarAdyacentes();
    return tamanoRegion;
}