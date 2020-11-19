#ifndef PARSERCORDENADAS_H
#define PARSERCORDENADAS_H


#include <string>
#include <vector>
#include <tuple>


//Funcion que recibe como parametros el String de Cordenadas X y Y, devuelde la Sumatoria de ambas
std::tuple<std::vector<double>, std::vector<double>> ParserCordenadasXY(std::string pCordenadas) {

    std::vector<double> CordenadasX{};
    std::vector<double> CordenadasY{};
    std::tuple<std::vector<double>, std::vector<double>> CordenadasXY{};

    int largoString = pCordenadas.length();
    double sumatoriaX = 0;
    double sumatoriaY = 0;
    std::string indiceX = "";
    std::string indiceY = "";
    int i = 2;
    int indiceCordenadas = 0;

    while (i < largoString) {
        while ((pCordenadas.at(i) != *" ") && (pCordenadas.at(i) != *"z")) {

            indiceX += pCordenadas.at(i);
            i++;
            if (pCordenadas.at(i) == *",") {
                sumatoriaX += stod(indiceX);
                CordenadasX.push_back(sumatoriaX);
                i++;
                while (pCordenadas.at(i) != *" ") {
                    indiceY += pCordenadas.at(i);
                    i++;
                }
                sumatoriaY += stod(indiceY);
                CordenadasY.push_back(sumatoriaY);
                //std::cout << sumatoriaX << ' ' << sumatoriaY << std::endl;
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
            indiceY = " ";
            indiceX = " ";
        }
    }

    CordenadasXY = make_tuple(CordenadasX,CordenadasY);
    return CordenadasXY;

}

#endif