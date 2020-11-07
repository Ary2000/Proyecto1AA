#include "Pais.h"

Pais::Pais(std::string nombre) { this->nombre = nombre; }

void Pais::anadirPaisAdyacente(Pais* paisAdyacente) 
{
	if (paisesAdyacente.size() != 0)
	{
		bool seEncontroSimilar = false;
		for (int posicionRevision = 0; posicionRevision < paisesAdyacente.size(); posicionRevision++)
		{
			if (paisesAdyacente[posicionRevision] == paisAdyacente)
			{
				seEncontroSimilar = true;
				break;
			}
		}
		if (!seEncontroSimilar)
			paisesAdyacente.push_back(paisAdyacente);
	}
	else
		paisesAdyacente.push_back(paisAdyacente);
}