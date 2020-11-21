#ifndef ALGORITMOBT_H
#define ALGORITMOBT_H

#include <utility>
#include <vector>
#include <numeric>
#include <string>

#include "Mundo.h"
#include "BTColor.h"

#include "pugixml.hpp"
#include "manejadorDocs.h"

class AlgoritmoBT
{
    private:
    Mundo* mundo;
    int cantidadEspaciosMinimos;
    int cantidadColores;
    std::vector<std::string> todosLosColores;
    BTColor* mejorBT = nullptr;
    std::vector<Pais*> paisesDeRegion;
    ManejadorDocs* manejador;

    std::vector<std::vector<int>> coloresRegiones;

    std::vector<BTColor*> mejoresAnteriores;

    std::vector<int> vectorAuxiliar;

    int cantidadBlancosTotal = 9999999;
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
    AlgoritmoBT(Mundo* mundo, int cantidadColores, std::vector<std::string> todosLosColores, ManejadorDocs* manejador);
    void realizarBT();
    
};

#endif