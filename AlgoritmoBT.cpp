#include "AlgoritmoBT.h"

AlgoritmoBT::AlgoritmoBT(Mundo* mundo)
{
    this->mundo = mundo;
    cantidadEspaciosMinimos = -1;
}

BTColor* AlgoritmoBT::realizarSolucionesBTColores(Pais* pais, int tamRegion, int sePintoBlanco)
{
    BTColor* mejorResultado = nullptr;
    for(auto iteradorPaisesAdyacentes = pais->paisesAdyacente.begin(); iteradorPaisesAdyacentes != pais->paisesAdyacente.end(); iteradorPaisesAdyacentes++)
    {
        if((*iteradorPaisesAdyacentes)->fueVisitadoBT() == false)
        {
            BTColor* colorActual = realizarSolucionesBT(*iteradorPaisesAdyacentes, tamRegion);
            if(mejorResultado != nullptr)
            {
                if(mejorResultado->existePaisEnLosCambios(mejorResultado->getPaisAPintar()))
                {
                    mejorResultado->push_back(colorActual);
                    mejorResultado->setCantidadBlancos(mejorResultado->getCantidadBlancos() + colorActual->getCantidadBlancos());
                    mejorResultado->setCantidadVisitados(mejorResultado->getPaisesVisitados() + colorActual->getPaisesVisitados());
                }
                else
                {
                    if(colorActual->getCantidadBlancos() >= mejorResultado->getCantidadBlancos())
                        delete colorActual;
                    else
                    {
                        delete mejorResultado;
                        mejorResultado = colorActual;
                    }
                }                
            }
            else
                mejorResultado = colorActual;
        }
    }
    BTColor* respuestaFinal;
    if(mejorResultado != NULL)
        respuestaFinal = new BTColor(pais, pais->colorBT, mejorResultado->getCantidadBlancos() + sePintoBlanco, mejorResultado->getPaisesVisitados() + 1, mejorResultado);
    else
        respuestaFinal = new BTColor(pais, pais->colorBT, sePintoBlanco, 1);
    return respuestaFinal;
}

BTColor* AlgoritmoBT::realizarSolucionesBT(Pais* pais, int tamRegion)
{   
    int sePintoBlanco = 1;
    pais->setVisitadoBT(true);
    std::vector<int> coloresPosibles(COLORES);
    std::iota(std::begin(coloresPosibles), std::end(coloresPosibles), 0);
    //Se busca cuales colores hay alreadedor, talvez hacerlo metodo si tengo tiempo
    for(int indicePaisesAdyacentes = 0; indicePaisesAdyacentes < pais->paisesAdyacente.size(); indicePaisesAdyacentes++)
        if(pais->paisesAdyacente[indicePaisesAdyacentes]->colorBT != -1 && pais->paisesAdyacente[indicePaisesAdyacentes]->colorBT != COLORES + 1)
            coloresPosibles[pais->paisesAdyacente[indicePaisesAdyacentes]->colorBT] = -1;
    //Se elije uno de los colores que no contenga ninguno de los otros paises adyacentes
    BTColor* mejorResultado = realizarSolucionesBTColores(pais, tamRegion, 1);
    for(auto colorPosible: coloresPosibles)
    {
        if(colorPosible != -1)
        {
            pais->colorBT = colorPosible;
            BTColor* colorActual = realizarSolucionesBTColores(pais, tamRegion, 0);
            if(colorActual->getCantidadBlancos() < mejorResultado->getCantidadBlancos())
            {
                delete mejorResultado;
                mejorResultado = colorActual;
            }
        }
    }
    pais->colorBT = -1;
    pais->setVisitadoBT(false);
    return mejorResultado;
}

void AlgoritmoBT::realizarBT()
{
    std::vector<BTColor*> respuestas;
    for(int indiceRegiones = 0; indiceRegiones < mundo->getSizeRegiones(); indiceRegiones++)
    {
        realizarSolucionesBT(mundo->getRegion(indiceRegiones), mundo->getSizeRegion(indiceRegiones));

    }
}