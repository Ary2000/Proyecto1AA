#ifndef ALGORITMOBT_H
#define ALGORITMOBT_H

#include <utility>
#include <vector>
#include <numeric>

#include "Mundo.h"
#include "BTColor.h"

#define COLORES 4

class AlgoritmoBT
{
    private:
    Mundo* mundo;
    int cantidadEspaciosMinimos;

    BTColor* realizarSolucionesBT(Pais* pais, int tamRegion);
    BTColor* realizarSolucionesBTColores(Pais* pais, int tamRegion, int sePintoBlanco);
    void lazyWritting(BTColor* colores);

    public:
    AlgoritmoBT(Mundo* mundo);
    void realizarBT();
    
};

#endif