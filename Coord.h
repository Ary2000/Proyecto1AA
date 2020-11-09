#pragma once

#include "Pais.hpp"

class Coord
{
//private:
public:
	int coordX;
	int coordY;
	Pais* paisOriginal;


	Coord(int coordX, int coordY, Pais* paisOriginal);
	void linkPais(Pais* paisAdyacente);

	friend struct OrdenadoPorX;
	friend struct OrdenadoPorY;
};

