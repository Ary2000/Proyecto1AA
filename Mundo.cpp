#include "Mundo.h"

Mundo::Mundo()
{

}

void Mundo::realizarRegiones()
{
    for(auto iteradorPaises = paises.begin(); iteradorPaises != paises.end(); iteradorPaises++)
    {
        if((*iteradorPaises)->haSidoVisitado() == false)
        {
            regiones.push_back(*iteradorPaises);
            (*iteradorPaises)->marcarAdyacentes();
        }
    }
}

void Mundo::visitarAdyacentes(Pais* pais)
{
    for(auto iteradorPaises = paises.begin(); iteradorPaises != paises.end(); iteradorPaises++)
        if((*iteradorPaises)->haSidoVisitado() == false)
        {
            regiones.push_back(*iteradorPaises);
            (*iteradorPaises)->marcarAdyacentes();
        }
}