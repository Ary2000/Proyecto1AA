#ifndef MUNDO_H
#define MUNDO_H

#include <vector>

#include "Pais.h"

class Mundo
{
    private:
    std::vector<Pais*> paises;
    void visitarAdyacentes(Pais* pais);

    public:
    std::vector<Pais*> regiones;

    Mundo();
    void anadirPais(Pais* pais) { paises.push_back(pais); }
    void realizarRegiones();

};

#endif