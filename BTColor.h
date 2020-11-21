#ifndef BTCOLOR_H
#define BTCOLOR_H

#include "Pais.h"

class BTColor
{
    private:
    Pais* paisAColorear;
    int color;
    BTColor* anteriorColor;
    BTColor* siguienteColor;
    int cantidadBlancos;
    int paisesVisitados;

    public:

    BTColor(Pais* pais, int color, int cantidadBlancos, int paisesVisitados);

    void marcarSiguiente(BTColor* siguiente);
    bool existePaisEnLosCambios(Pais* pais);
    void push_back(BTColor* ultimo);
    void pintarRegion();
    void agregarVisitado() { paisesVisitados++; }

    //gets
    int getCantidadBlancos() { return cantidadBlancos; }
    int getPaisesVisitados() { return paisesVisitados; }
    int getColor() { return color; }
    Pais* getPaisAPintar() { return paisAColorear; }
    bool tieneSiguiente() 
    { 
        if(siguienteColor != nullptr)
            return true;
        return false;
    }
    BTColor* getSiguienteColor() { return siguienteColor; }
    BTColor* getAnteriorColor() { return anteriorColor; }
    
    //sets
    void setCantidadBlancos(int cantidadBlancos) { this->cantidadBlancos = cantidadBlancos; }
    void setCantidadVisitados(int paisesVisitados) { this->paisesVisitados = paisesVisitados; }
    void setSiguienteColor(BTColor* siguienteColor) { this->siguienteColor = siguienteColor ;}
    void setAnteriorColor(BTColor* anteriorColor) { this->anteriorColor = anteriorColor ;}
    

};

#endif