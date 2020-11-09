#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include "include/Coord.h"
#include "include/Pais.h"

#define CANTIDADCOLORES 4

using namespace std;

/*
class Pais
{
//private:
public:
	std::string nombre;
	std::vector<Pais*> paisesAdyacente;

//public:
	Pais(std::string nombre) { this->nombre = nombre; }
	void anadirPaisAdyacente(Pais* paisAdyacente) { paisesAdyacente.push_back(paisAdyacente); }
};

class Coord
{
//private:
public:
	int coordX;
	int coordY;
	Pais* paisOriginal;


	Coord(int coordX, int coordY, Pais* paisOriginal)
    {
        this->coordX = coordX;
        this->coordY = coordY;
        this->paisOriginal = paisOriginal;
    }

	void linkPais(Pais* paisAdyacente) { paisOriginal->anadirPaisAdyacente(paisAdyacente); }

	friend struct OrdenadoPorX;
	friend struct OrdenadoPorY;
};
*/

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

void unirPaisesNoAdyacentesAux(Pais* paisOriginal, vector<Pais*>& paisesNoAdyacentes)
{

}

void unirPaisesNoAdyacentes(Pais* paisOriginal)
{
	vector<Pais*> paisesNoAdyacentes[CANTIDADCOLORES];
	//unirPaisesNoAdyacentesAux(paisOriginal, paisesNoAdyacentes);
}

int main()
{
	Pais* CostaRica = new Pais("Costa Rica");
	Pais* Nicaragua = new Pais("Nicaragua");
	Pais* Colombia = new Pais("Colombia");
	Pais* Guatemala = new Pais("Guatemala");
	vector<Coord*> coordenadas;
	coordenadas.push_back(new Coord(102, 241, CostaRica));
	coordenadas.push_back(new Coord(102, 241, Nicaragua));
	coordenadas.push_back(new Coord(21, 21, Colombia));
	coordenadas.push_back(new Coord(1, 1, Guatemala));
	coordenadas.push_back(new Coord(1, 1, CostaRica));
	sort(coordenadas.begin(), coordenadas.end(), OrdenadoPorX());
	cout << 7 << endl;
	contarPosiblesAdyacentes(coordenadas);
	return 0;
}