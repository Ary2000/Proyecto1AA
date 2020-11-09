#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include "pugixml.hpp"
#include "ParserCordenadas.h"
#include "Pais.hpp"
#include "Coord.h"
#include "Pais.cpp"		//?
#include "Coord.cpp"	//?

//#include "Pais.h"
//#include "Coord.h"
using namespace std;

struct OrdenadoPorX
{
	inline bool operator() (Coord* struct1, Coord* struct2)
	{
		return (struct1->coordX < struct2->coordX);
	}
};

struct OrdenadoPorY
{
	inline bool operator() (Coord* struct1, Coord* struct2)
	{
		return (struct1->coordY < struct2->coordY);
	}
};

void linkAdyacentes(int posIzqAdyacentes, int posDerAdyacentes, vector<Coord*> coordenadas)
{
	for (int posPrimerPais = posIzqAdyacentes; posPrimerPais < posDerAdyacentes + 1; posPrimerPais++)
	{
		for (int posSegundoPais = posPrimerPais + 1; posSegundoPais < posDerAdyacentes + 1; posSegundoPais++)
		{
			//Se linkean los paises adyacentes
			//coordenadas[posPrimerPais]->paisOriginal->paisesAdyacente.push_back(coordenadas[posSegundoPais]->paisOriginal);
			//coordenadas[posSegundoPais]->paisOriginal->paisesAdyacente.push_back(coordenadas[posPrimerPais]->paisOriginal);
			coordenadas[posPrimerPais]->paisOriginal->anadirPaisAdyacente(coordenadas[posSegundoPais]->paisOriginal);
			coordenadas[posSegundoPais]->paisOriginal->anadirPaisAdyacente(coordenadas[posPrimerPais]->paisOriginal);
		}
	}
}

void revisarAdyacentes(int posIzq, int posDer, vector<Coord*> coordenadas)
{
	int primerPPAdyacente = 0;
	int ultimoPPAdyacente = 0;
	int posIzqAdyacentes = posIzq;
	int posDerAdyacentes = posIzq;
	sort(coordenadas.begin() + posIzq, coordenadas.begin() + posDer, OrdenadoPorY());
	int coordenadaYBase = coordenadas[posIzq]->coordY;
	for (int posCoordenadaActual = posIzq; posCoordenadaActual < posDer; posCoordenadaActual++)
	{
		if (coordenadas[posCoordenadaActual]->coordY == coordenadaYBase)
			posDerAdyacentes++;

		else 
		{	
			if (posIzqAdyacentes != posDerAdyacentes)
				linkAdyacentes(posIzqAdyacentes, posDerAdyacentes, coordenadas);
			posIzqAdyacentes = posDerAdyacentes = posCoordenadaActual;
			
		}
	}
	if (posIzqAdyacentes != posDerAdyacentes)
	{
		linkAdyacentes(posIzqAdyacentes, posDerAdyacentes, coordenadas);
	}
}

void contarPosiblesAdyacentes(vector<Coord*> coordenadas)
{
	int posIzq = 0;
	int posDer = 0;
	int coordXPrincipal = coordenadas[0]->coordX;
	for (int coordenadaActual = 1; coordenadaActual < coordenadas.size(); coordenadaActual++)
	{
		if (coordenadas[coordenadaActual]->coordX == coordXPrincipal)
			posDer++;

		else
		{
			//Se envian las coordenadas que contengan 
			if (posIzq != posDer)
				revisarAdyacentes(posIzq, posDer, coordenadas);
			posIzq = posDer = coordenadaActual;
			coordXPrincipal = coordenadas[coordenadaActual]->coordX;
		}
	}
	if(posDer != posIzq)
		revisarAdyacentes(posIzq, posDer, coordenadas);
}

int main()
{

	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("world.svg");
	pugi::xml_node pais1 = doc.child("svg").child("path");
	cout << "Load result: " << result.description() << endl << endl;

	std::tuple<std::vector<float>, std::vector<float>> CordenadasPais{};
	std::vector<float> CoX{};
	std::vector<float> CoY{};
	
	vector<Coord*> coordenadas;
	std::string pruebaCo;

	while(pais1 != NULL)
	{
		cout << pais1.attribute("id").value() << endl;
		pruebaCo = pais1.attribute("d").value();
		CordenadasPais = ParserCordenadasXY(pruebaCo);
		CoX = std::get<0>(CordenadasPais);
		CoY = std::get<1>(CordenadasPais);
		Pais* paisActual = new Pais(pais1.attribute("data-name").value());
		for (int i = 0; i < CoX.size(); i++)
				coordenadas.push_back(new Coord(CoX.at(i), CoY.at(i), paisActual));
		pais1 = pais1.next_sibling();
	}

	sort(coordenadas.begin(), coordenadas.end(), OrdenadoPorX());
	cout << coordenadas.size() << endl;
	contarPosiblesAdyacentes(coordenadas);
	return 0;


}