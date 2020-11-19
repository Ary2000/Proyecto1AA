#ifndef COORD_H
#define COORD_H

#include "Pais.h"

class Coord
{
//private:
public:
	int coordX;
	int coordY;
	Pais* paisOriginal;


	Coord(double coordX, double coordY, Pais* paisOriginal);
	void linkPais(Pais* paisAdyacente);

	friend struct OrdenadoPorX;
	friend struct OrdenadoPorY;
};

#endif