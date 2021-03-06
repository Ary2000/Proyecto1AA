#ifndef ALGORITMOPROGDINA_H
#define ALGORITMOPROGDINA_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <tuple>
#include <stack>
#include <chrono>

#include "Mundo.h"
#include "BTColor.h"
#include "Pais.h"



class AlgoritmoProgDina
{
    private:
    Mundo* mundo;
    int pNumColores;
    std::vector<std::string> todosLosColores;
    ManejadorDocs* manejador;
    std::tuple<int, std::vector<int>> asignarMejorColor(std::vector<int> pColoresUsar,std::vector<int> pContadorColores);
    std::vector<int> hacerVectorColores(int pNumColores);

    public:
    AlgoritmoProgDina(Mundo* mundo,int pNumColores,std::vector<std::string> todosLosColores, ManejadorDocs* manejador);
    void realizarProgDina();
    
    
};

#endif