#ifndef BTCOLOR_H
#define BTCOLOR_H

#include "Pais.h"

class BTColor
{
    private:
    Pais* paisAColorear;
    int color;
    BTColor* siguienteColor;
    int cantidadBlancos;
    int paisesVisitados;

    public:

    BTColor(Pais* pais, int color, int cantidadBlancos, int paisesVisitados);
    BTColor(Pais* pais, int color, int cantidadBlancos, int paisesVisitados, BTColor* colorSiguiente);

    void marcarSiguiente(BTColor* siguiente) { siguienteColor = siguiente; }
    bool existePaisEnLosCambios(Pais* pais);
    void push_back(BTColor* ultimo);
    void pintarRegion();

    //gets
    int getCantidadBlancos() { return cantidadBlancos; }
    int getPaisesVisitados() { return paisesVisitados; }
    int getColor() {return color; }
    Pais* getPaisAPintar() { return paisAColorear; }
    BTColor* getSiguienteColor() { return siguienteColor; }
    
    //sets
    void setCantidadBlancos(int cantidadBlancos) { this->cantidadBlancos = cantidadBlancos; }
    void setCantidadVisitados(int paisesVisitados) { this->paisesVisitados = paisesVisitados; }

    ~BTColor() { delete siguienteColor; }
    

};

#endif