#ifndef ALGORITMODV_H
#define ALGORITMODV_H

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



class AlgoritmoDV
{
    private:
    Mundo* mundo;
    int pNumColores;
    std::vector<std::string> todosLosColores;
    std::vector<int> hacerVectorColores(int pNumColores);
    ManejadorDocs* manejador;

    public:
    AlgoritmoDV(Mundo* mundo,int pNumColores,std::vector<std::string> todosLosColores, ManejadorDocs* manejador);
    void realizarDV();
    
    
};

#endif