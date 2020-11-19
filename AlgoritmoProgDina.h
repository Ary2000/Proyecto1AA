#ifndef ALGORITMOPROGDINA_H
#define ALGORITMOPROGDINA_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <tuple>
#include <stack>

#include "Mundo.h"
#include "BTColor.h"
#include "Pais.h"



class AlgoritmoProgDina
{
    private:
    Mundo* mundo;
    int pNumColores;
    std::tuple<int, std::vector<int>> asignarMejorColor(std::vector<int> pColoresUsar,std::vector<int> pContadorColores);
    std::vector<int> hacerVectorColores(int pNumColores);

    public:
    AlgoritmoProgDina(Mundo* mundo,int pNumColores);

    void realizarProgDina();
    
    
};

#endif