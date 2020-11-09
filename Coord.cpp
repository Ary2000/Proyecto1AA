#include "Coord.h"

Coord::Coord(int coordX, int coordY, Pais* paisOriginal) 
{
	this->coordX = coordX;
	this->coordY = coordY;
	this->paisOriginal = paisOriginal;
}

void Coord::linkPais(Pais* paisAdyacente) { paisOriginal->anadirPaisAdyacente(paisAdyacente); }