#include "AlgoritmoBT.h"

AlgoritmoBT::AlgoritmoBT(Mundo* mundo, int cantidadColores, std::vector<std::string> todosLosColores)
{
    this->mundo = mundo;
    this->cantidadColores = cantidadColores;
    this->todosLosColores = todosLosColores;
    cantidadEspaciosMinimos = -1;
}
/*
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
    std::vector<int> coloresPosibles(cantidadColores);
    std::iota(std::begin(coloresPosibles), std::end(coloresPosibles), 0);
    //Se busca cuales colores hay alreadedor, talvez hacerlo metodo si tengo tiempo
    for(int indicePaisesAdyacentes = 0; indicePaisesAdyacentes < pais->paisesAdyacente.size(); indicePaisesAdyacentes++)
        if(pais->paisesAdyacente[indicePaisesAdyacentes]->colorBT != -1 && pais->paisesAdyacente[indicePaisesAdyacentes]->colorBT != cantidadColores + 1)
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
*/
/*
BTColor* AlgoritmoBT::realizarSolucionesBTColores(Pais* pais, BTColor* resultadoAnterior, vector<Pais*> camino, int posicion)
{
    BTColor* mejorRespuesta = nullptr;
    //for(auto iteradorPaisesAdyacentes = pais->paisesAdyacente.begin(); iteradorPaisesAdyacentes != pais->paisesAdyacente.end(); iteradorPaisesAdyacentes++)
    
    {
        if(cantidadBlancosTotal <= resultadoAnterior->getCantidadBlancos())
            return nullptr;

        if((*iteradorPaisesAdyacentes)->fueVisitadoBT() == false)
        {
            BTColor* colorActual = realizarSolucionesBT(*iteradorPaisesAdyacentes, paisesVisitados, resultadoAnterior);
            if(colorActual != nullptr)
            {
                if(mejorRespuesta == nullptr)
                    mejorRespuesta = colorActual;
                else
                {
                    if(mejorRespuesta->existePaisEnLosCambios(colorActual->getPaisAPintar()) == false)
                    {
                        mejorRespuesta->push_back(colorActual);
                        if(colorActual->getColor() == -1)
                            mejorRespuesta->setCantidadBlancos(mejorRespuesta->getCantidadBlancos() + colorActual->getCantidadBlancos() - 1);
                        else
                            mejorRespuesta->setCantidadBlancos(mejorRespuesta->getCantidadBlancos() + colorActual->getCantidadBlancos());
                        mejorRespuesta->setCantidadVisitados(mejorRespuesta->getPaisesVisitados() + colorActual->getPaisesVisitados() - 1);
                        if(mejorRespuesta->getPaisesVisitados() == tamanoRegionActual)
                        {
                            cantidadBlancosTotal = mejorRespuesta->getCantidadBlancos();
                        }
                    }
                    else if(mejorRespuesta->getCantidadBlancos() > colorActual->getCantidadBlancos())
                    {
                        delete mejorRespuesta;
                        mejorRespuesta = colorActual;
                    }
                }
            }
            if(mejorRespuesta->getCantidadBlancos() == resultadoAnterior->getCantidadBlancos())
                return mejorRespuesta;
        }
    }
    return mejorRespuesta;
}
*/
BTColor* AlgoritmoBT::realizarSolucionesBT(Pais* pais, BTColor* resultadoAnterior, int posicion)
{
    pais->setVisitadoBT(true);
    std::vector<int> coloresPosibles(cantidadColores);
    std::iota(std::begin(coloresPosibles), std::end(coloresPosibles), 0);
    //Se busca cuales colores hay alreadedor, talvez hacerlo metodo si tengo tiempo
    for(int indicePaisesAdyacentes = 0; indicePaisesAdyacentes < pais->paisesAdyacente.size(); indicePaisesAdyacentes++)
    {
        if(pais->paisesAdyacente[indicePaisesAdyacentes]->colorBT != -1)
            coloresPosibles[pais->paisesAdyacente[indicePaisesAdyacentes]->colorBT] = -1;
    }
    //Se elije uno de los colores que no contenga ninguno de los otros paises adyacentes
    BTColor* mejorResultado = nullptr;
    for(auto colorPosible: coloresPosibles)
    {   
        if(resultadoAnterior != nullptr && cantidadBlancosTotal <= resultadoAnterior->getCantidadBlancos())
            return nullptr;

        if(colorPosible != -1)
        {
            pais->colorBT = colorPosible;
            BTColor* colorActual;
            colorActual = new BTColor(pais, colorPosible, 0, 0);
            if(resultadoAnterior != nullptr)
            {
                colorActual->setCantidadBlancos(resultadoAnterior->getCantidadBlancos());
                //colorActual->setCantidadVisitados(resultadoAnterior->getPaisesVisitados());
                colorActual->push_back(resultadoAnterior);
            }
            if(posicion + 1 < camino.size())
                colorActual = realizarSolucionesBT(camino[++posicion], colorActual, posicion);
            if(mejorResultado == nullptr || mejorResultado->getCantidadBlancos() > colorActual->getCantidadBlancos())
                delete mejorResultado;
                mejorResultado = colorActual;
            if(resultadoAnterior != nullptr && mejorResultado != nullptr && mejorResultado->getCantidadBlancos() == resultadoAnterior->getCantidadBlancos())
                break;
        }
    }
    if(mejorResultado == nullptr)
    {
        if(resultadoAnterior == nullptr)
            mejorResultado = new BTColor(pais, -1, 1, 0);

        else
        {
            mejorResultado = new BTColor(pais, -1, resultadoAnterior->getCantidadBlancos() + 1, 0);
            mejorResultado->push_back(resultadoAnterior);
        }
    }
    if(camino.size() - 1 == posicion)
    {
        if(mejorBT == NULL || mejorBT->getCantidadBlancos() > mejorResultado->getCantidadBlancos())
            mejorBT = mejorResultado;
    }
    pais->colorBT = -1;
    pais->setVisitadoBT(false);
    return mejorResultado;
}


/*
void AlgoritmoBT::crearPosiblesCombinaciones(Pais* pais, int paisesVisitados)
{
    paisesVisitados++;
    std::vector<int> coloresPosibles(cantidadColores);
    std::iota(std::begin(coloresPosibles), std::end(coloresPosibles), 0);
    pais->pasadoBTProcess = true;
    //Se busca cuales colores hay alreadedor, talvez hacerlo metodo si tengo tiempo
    for(int indicePaisesAdyacentes = 0; indicePaisesAdyacentes < pais->paisesAdyacente.size(); indicePaisesAdyacentes++)
    {
        if(pais->paisesAdyacente[indicePaisesAdyacentes]->colorBT != -1)
            coloresPosibles[pais->paisesAdyacente[indicePaisesAdyacentes]->colorBT] = -1;
    }

    for(auto colorPosible: coloresPosibles)
    {
        if(colorPosible != -1)
        {
            vectorAuxiliar[pais->indexBT] = colorPosible;
            for(int indicePaisesAdyacentes = 0; indicePaisesAdyacentes < pais->paisesAdyacente.size(); indicePaisesAdyacentes++)
            {
                if(pais->paisesAdyacente[indicePaisesAdyacentes]->pasadoBTProcess == false)
                {
                    crearPosiblesCombinaciones(pais->paisesAdyacente[indicePaisesAdyacentes], paisesVisitados);
                }
            }
        }
        if(paisesVisitados)
    }
    pais->pasadoBTProcess = false;
}

void AlgoritmoBT::crearPCBase(Pais* pais)
{
    //Se busca cuales colores hay alreadedor, talvez hacerlo metodo si tengo tiempo
    for(auto iteradorPaisesRegion = paisesDeRegion.begin(); iteradorPaisesRegion != paisesDeRegion.end(); iteradorPaisesRegion++)
    {
        if((*iteradorPaisesRegion)->pasadoBTProcess == false)
        {
            crearPosiblesCombinaciones((*iteradorPaisesRegion), 0);
        }
    }
}

void AlgoritmoBT::realizarBT()
{
    std::vector<BTColor*> respuestas;
    for(int indiceRegiones = 0; indiceRegiones < mundo->getSizeRegiones(); indiceRegiones++)
    {
        conseguirPaisesRegion(mundo->getRegion(indiceRegiones));
        coloresRegiones[indiceRegiones](tamanoRegionActual);
        vectorAuxiliar(tamanoRegion);
        crearPosiblesCombinaciones(mundo->getRegion(indiceRegiones));
    }
} 
*/

void AlgoritmoBT::realizarBT()
{
    std::vector<BTColor*> respuestas;
    for(int indiceRegiones = 0; indiceRegiones < mundo->getSizeRegiones(); indiceRegiones++)
    {
        conseguirPaisesRegion(mundo->getRegion(indiceRegiones), 0);
        for(auto iteradorPaisesRegion = paisesDeRegion.begin(); iteradorPaisesRegion < paisesDeRegion.end(); iteradorPaisesRegion++)
        {
            if((*iteradorPaisesRegion)->esCamino == false)
            {
                crearCamino(*iteradorPaisesRegion);
                realizarSolucionesBT(*iteradorPaisesRegion, nullptr, 0);
                respuestas.push_back(mejorBT);
                mejorBT = nullptr;
                for(auto iteradorCamino = camino.begin(); iteradorCamino != camino.end(); iteradorCamino++)
                {
                    (*iteradorCamino)->setVisitadoBT(true);
                    (*iteradorCamino)->esCamino = true;
                }
                camino.clear();
            }
        }
        
    }
} 

void AlgoritmoBT::crearCamino(Pais* pais)
{
    Pais* aux = pais;
    pais->esCamino = true;
    camino.push_back(pais);
    for(int indicePaisesAdyacentes = 0; indicePaisesAdyacentes < pais->paisesAdyacente.size(); indicePaisesAdyacentes++)
    {
        if(pais->paisesAdyacente[indicePaisesAdyacentes]->esCamino == false)
        {
            crearCamino(pais->paisesAdyacente[indicePaisesAdyacentes]);
            break;
        }
    }
}

void AlgoritmoBT::conseguirPaisesRegion(Pais* pais, int indice)
{
    paisesDeRegion.push_back(pais);
    pais->indexBT = indice;
    indice++;
    pais->setVisitadoBT(true);
    for(int indicePaisesAdyacentes = 0; indicePaisesAdyacentes < pais->paisesAdyacente.size(); indicePaisesAdyacentes++)
        if(pais->paisesAdyacente[indicePaisesAdyacentes]->fueVisitadoBT() == false)
        {
            conseguirPaisesRegion(pais->paisesAdyacente[indicePaisesAdyacentes], indice);    
        }

}

void AlgoritmoBT::lazyWritting(BTColor* colores)
{
    while(colores != NULL)
    {
        colores->getPaisAPintar()->pintarPaisBT(todosLosColores[colores->getColor()]);
        colores = colores->getSiguienteColor();
    }
}