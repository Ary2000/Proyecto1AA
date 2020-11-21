#include "BTColor.h"

BTColor::BTColor(Pais* pais, int color, int cantidadBlancos, int paisesVisitados)
{
    paisAColorear = pais;
    this->color = color;
    this->cantidadBlancos = cantidadBlancos;
    this->paisesVisitados = paisesVisitados;
    siguienteColor = nullptr;
    anteriorColor = nullptr;
}

bool BTColor::existePaisEnLosCambios(Pais* pais)
{
    /*
    if(pais == paisAColorear)
        return true;
    else if(siguienteColor != nullptr)
        return siguienteColor->existePaisEnLosCambios(pais);
    else
        return false;
    */
   BTColor* aux = this;
   while(aux != NULL)
   {
        if(pais == aux->getPaisAPintar())
            return true;
        else
            aux = aux->siguienteColor;
   }
   return false;
}

void BTColor::marcarSiguiente(BTColor* siguiente)
{
    cantidadBlancos += siguiente->getCantidadBlancos();
    paisesVisitados += siguiente->getPaisesVisitados();
    siguienteColor = siguiente;
}

void BTColor::push_back(BTColor* ultimo)
{
    if(siguienteColor)
        siguienteColor->push_back(ultimo);
    else
    {
        siguienteColor = ultimo;
        ultimo->setAnteriorColor(this);
    }
}