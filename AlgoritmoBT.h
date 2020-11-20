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
    BTColor* mejorBT = NULL;
    std::vector<Pais*> paisesDeRegion;

    std::vector<std::vector<int>> coloresRegiones;

    std::vector<int> vectorAuxiliar;

    int cantidadBlancosTotal = 99999999999;
    int tamanoRegionActual = 0;

    std::vector<Pais*> camino;

    BTColor* realizarSolucionesBT(Pais* pais, BTColor* resultadoAnterior, int posicion);
    BTColor* realizarSolucionesBTColores(Pais* pais, BTColor* resultadoAnterior, std::vector<Pais*> camino, int posicion);
    void conseguirPaisesRegion(Pais* pais1, int indice);
    void crearCamino(Pais* pais);
    
    void lazyWritting(BTColor* colores);

    public:
    void crearPosiblesCombinaciones(Pais* pais, int paisesVisitados);
    void crearPCBase(Pais* pais);
    AlgoritmoBT(Mundo* mundo, int canitdadColores, std::vector<std::string> todosLosColores);
    void realizarBT();
    
};

#endif