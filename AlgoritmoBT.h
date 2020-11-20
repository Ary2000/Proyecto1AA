#ifndef ALGORITMOBT_H
#define ALGORITMOBT_H

#include <utility>
#include <vector>
#include <numeric>
#include <string>

#include "Mundo.h"
#include "BTColor.h"

class AlgoritmoBT
{
    private:
    Mundo* mundo;
    int cantidadEspaciosMinimos;
    int cantidadColores;
    std::vector<std::string> todosLosColores;

    BTColor* realizarSolucionesBT(Pais* pais, int tamRegion);
    BTColor* realizarSolucionesBTColores(Pais* pais, int tamRegion, int sePintoBlanco);
    void lazyWritting(BTColor* colores);

    public:
    AlgoritmoBT(Mundo* mundo, int canitdadColores, std::vector<std::string> todosLosColores);
    void realizarBT();
    
};

#endif