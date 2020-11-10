#pragma once
#include <string>
#include <vector>
#include <tuple>

//string prueba ="m 12,13 2,-3 z m 1,1 2,2 z";


//Funcion que recibe como parametros el String de Cordenadas X y Y, devuelde la Sumatoria de ambas
std::tuple<std::vector<float>, std::vector<float>> ParserCordenadasXY(std::string pCordenadas) {

    std::vector<float> CordenadasX{};
    std::vector<float> CordenadasY{};
    std::tuple<std::vector<float>, std::vector<float>> CordenadasXY{};


    int largoString = pCordenadas.length();
    float sumatoriaX = 0;
    float sumatoriaY = 0;
    std::string indiceX = "";
    std::string indiceY = "";
    int i = 2;
    int indiceCordenadas = 0;

    while (i < largoString) {
        while ((pCordenadas.at(i) != *" ") && (pCordenadas.at(i) != *"z")) {

            indiceX += pCordenadas.at(i);
            i++;
            if (pCordenadas.at(i) == *",") {
                sumatoriaX += stof(indiceX);
                CordenadasX.push_back(sumatoriaX);
                i++;
                while (pCordenadas.at(i) != *" ") {
                    indiceY += pCordenadas.at(i);
                    i++;
                }
                sumatoriaY += stof(indiceY);
                CordenadasY.push_back(sumatoriaY);
                indiceY = "";
                indiceX = "";
                i++;
                if (pCordenadas.at(i) == *"l")
                {
                    i+=2;
                }
                

            }
        }
        if (pCordenadas.at(i) == *"z")
        {
            i += 4;
            sumatoriaX = 0;
            sumatoriaY = 0;
            indiceY = " ";
            indiceX = " ";
        }
    }

    CordenadasXY = make_tuple(CordenadasX,CordenadasY);
    return CordenadasXY;

}