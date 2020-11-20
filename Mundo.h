#ifndef MUNDO_H
#define MUNDO_H

#include <vector>
#include <string>

#include "Pais.h"

class Mundo
{
    private:
    std::vector<Pais*> paises;
    void visitarAdyacentes(Pais* pais);

    public:
    std::vector<Pais*> regiones;
    std::vector<int> tamanoRegiones;
    std::vector<std::string> colores;

    Mundo();
    void anadirPais(Pais* pais) { paises.push_back(pais); }
    void realizarRegiones();
    Pais* getRegion(int regionSeleccionada) { return regiones[regionSeleccionada]; }
    int getSizeRegion(int regionSeleccionada) { return tamanoRegiones[regionSeleccionada]; }
    //Cambiar nombre a cantidadRegiones
    int getSizeRegiones() { return regiones.size(); }
};

#endif