#include "BTColor.h"

BTColor::BTColor(Pais* pais, int color, int cantidadBlancos, int paisesVisitados)
{
    paisAColorear = pais;
    this->color = color;
    this->cantidadBlancos = cantidadBlancos;
    this->paisesVisitados = paisesVisitados;
    siguienteColor = nullptr;
}

BTColor::BTColor(Pais* pais, int color, int cantidadBlancos, int paisesVisitados, BTColor* siguienteColor)
{
    paisAColorear = pais;
    this->color = color;
    this->cantidadBlancos = cantidadBlancos;
    this->paisesVisitados = paisesVisitados;
    this->siguienteColor = siguienteColor;
}

bool BTColor::existePaisEnLosCambios(Pais* pais)
{
    if(pais == paisAColorear)
        return true;
    else if(siguienteColor)
        return siguienteColor->existePaisEnLosCambios(pais);
    else
        return false;
}

void BTColor::push_back(BTColor* ultimo)
{
    if(siguienteColor)
        siguienteColor->push_back(ultimo);
    else
        siguienteColor = ultimo;
}