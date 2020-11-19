#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <tuple>

#include "pugixml.hpp"
#include "ParserCordenadas.h"
#include "Pais.h"
#include "Coord.h"
#include "Mundo.h"
#include "AlgoritmoBT.h"
#include "CrearWorld.h"

#include "Pais.cpp"
#include "Coord.cpp"
#include "Mundo.cpp"
#include "AlgoritmoBT.cpp"
#include "BTColor.cpp"



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
			if(coordenadas[posPrimerPais]->paisOriginal->nombre == "Russia" && coordenadas[posSegundoPais]->paisOriginal->nombre == "Canada")
			{
				
				Coord* coordenada1 = coordenadas[posPrimerPais];
				Coord* coordenada2 = coordenadas[posSegundoPais];
				std::cout << "Encontrado" << std::endl;
			}
			if(coordenadas[posPrimerPais]->paisOriginal != coordenadas[posSegundoPais]->paisOriginal)
			{
				coordenadas[posPrimerPais]->paisOriginal->anadirPaisAdyacente(coordenadas[posSegundoPais]->paisOriginal);
				coordenadas[posSegundoPais]->paisOriginal->anadirPaisAdyacente(coordenadas[posPrimerPais]->paisOriginal);
			}
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
	double coordenadaYBase = coordenadas[posIzq]->coordY;
	for (int posCoordenadaActual = posIzq + 1; posCoordenadaActual <= posDer; posCoordenadaActual++)
	{
		
		if (coordenadas[posCoordenadaActual]->coordY == coordenadaYBase)
			posDerAdyacentes++;

		else 
		{	
			if (posIzqAdyacentes != posDerAdyacentes)
				linkAdyacentes(posIzqAdyacentes, posDerAdyacentes, coordenadas);
			posIzqAdyacentes = posDerAdyacentes = posCoordenadaActual;
			coordenadaYBase = coordenadas[posCoordenadaActual]->coordY;
			
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
	double coordXPrincipal = coordenadas[0]->coordX;
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

	std::tuple<std::vector<double>, std::vector<double>> CordenadasPais{};
	std::vector<double> CoX{};
	std::vector<double> CoY{};
	
	vector<Coord*> coordenadas;
	std::string pruebaCo;

	crearCopiasWorld();

	pugi::xml_document docDV;
	pugi::xml_parse_result resultDV = docDV.load_file("worldDvideVenceras.svg");
	pugi::xml_node paisDV = docDV.child("svg").child("path");

	pugi::xml_document docPD;
	pugi::xml_parse_result resultPD = docPD.load_file("worldProgDinamica.svg");
	pugi::xml_node paisPD = docPD.child("svg").child("path");

	pugi::xml_document docBacktracking;
	pugi::xml_parse_result resultBT = docBacktracking.load_file("worldBackTracking.svg");
	pugi::xml_node paisBT = docBacktracking.child("svg").child("path");

	Mundo* mundo = new Mundo();

	while(pais1 != NULL)
	{
		pruebaCo = pais1.attribute("d").value();
		CordenadasPais = ParserCordenadasXY(pruebaCo);
		CoX = std::get<0>(CordenadasPais);
		CoY = std::get<1>(CordenadasPais);
		Pais* paisActual = new Pais(pais1.attribute("data-name").value(), paisDV, paisPD, paisBT);
		for (int i = 0; i < CoX.size(); i++)
			coordenadas.push_back(new Coord(CoX.at(i), CoY.at(i), paisActual));
		mundo->anadirPais(paisActual);
		pais1 = pais1.next_sibling();
		paisDV = paisDV.next_sibling();
		paisPD = paisPD.next_sibling();
		paisBT = paisBT.next_sibling();
	}

	sort(coordenadas.begin(), coordenadas.end(), OrdenadoPorX());
	cout << coordenadas.size() << endl;
	contarPosiblesAdyacentes(coordenadas);
	mundo->realizarRegiones();
	AlgoritmoBT algoritmoBT(mundo);
	algoritmoBT.realizarBT();
	return 0;
}