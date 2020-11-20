#include "Pais.h"

Pais::Pais(std::string nombre, pugi::xml_attribute attrDV, pugi::xml_attribute attrPD, pugi::xml_attribute attrBT) 
{ 
    this->nombre = nombre; 
    this->visitadoRegiones = false;
    this->pasadoBT = false;
    this->colorBT = -1;
    this->attrDV = attrDV;
    this->attrPD = attrPD;
    this->attrBT = attrBT;
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