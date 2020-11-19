#include "Pais.h"

Pais::Pais(std::string nombre, pugi::xml_node nodeDV, pugi::xml_node nodePD, pugi::xml_node nodeBT) 
{ 
    this->nombre = nombre; 
    this->visitadoRegiones = false;
    this->pasadoBT = false;
    this->colorBT = -1;
    this->nodeDV = nodeDV;
    this->nodePD = nodePD;
    this->nodeBT = nodeBT;
}

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

int Pais::marcarAdyacentes()
{   
    int tamanoRegion = 1;
    visitadoRegiones = true;
    for(auto iteradorAdyacentes = paisesAdyacente.begin(); iteradorAdyacentes != paisesAdyacente.end(); iteradorAdyacentes++)
        if((*iteradorAdyacentes)->visitadoRegiones == false)
            tamanoRegion += (*iteradorAdyacentes)->marcarAdyacentes();
    return tamanoRegion;
}