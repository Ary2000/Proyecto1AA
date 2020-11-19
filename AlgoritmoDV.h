#ifndef ALGORITMODV_H
#define ALGORITMODV_H

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



class AlgoritmoDV
{
    private:
    Mundo* mundo;
    int pNumColores;
    std::vector<int> hacerVectorColores(int pNumColores);

    public:
    AlgoritmoDV(Mundo* mundo,int pNumColores);
    void realizarDV();
    
    
};

#endif