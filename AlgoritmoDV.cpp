#include "AlgoritmoDV.h"


using namespace std;

AlgoritmoDV::AlgoritmoDV(Mundo* mundo)
{
    this->mundo = mundo;
}


void AlgoritmoDV::realizarDV(){

    std::vector<int> ColoresPos{1,2,3,0};
	std::vector<int> ReinicioColoresPos = ColoresPos;
	int indiceRegion = mundo->getSizeRegiones();

	
	int comprobar,comprobar2,comprobarColor;
	Pais* actual;
	
	std::stack<Pais*> pila;
	std::vector<Pais*> lista;
	std::vector<Pais*>::iterator i;
	std::vector<int>::iterator new_end;
	
		
	for (int indiceForRegion = 0; indiceForRegion < indiceRegion; indiceForRegion++){

		Pais* PrimerPais = mundo->getRegion(indiceForRegion);
		pila.push(PrimerPais);

		while (!pila.empty()){
        comprobar = 0;

		actual = pila.top();
		pila.pop();

		for (i=lista.begin(); i!=lista.end(); i++){

			if(*i == actual){
                comprobar = 1;
            }
        }
		if (comprobar == 0){

			cout<< actual->nombre<< ", ";
			for (int i = 0; i < actual->paisesAdyacente.size(); i++){

                new_end = remove(ColoresPos.begin(), ColoresPos.end(), actual->paisesAdyacente[i]->colorBT);

            }
				
			lista.push_back(actual);
			actual->colorBT=ColoresPos[0];
			cout<< actual->colorBT<< ", ";
			ColoresPos=ReinicioColoresPos;
			//Aux para 
			int aux;
            int indiceAux = 0;
			aux = actual->paisesAdyacente.size();

			while (indiceAux < aux){

				comprobar2 = 0;
				for ( i=lista.begin(); i!=lista.end(); i++){

					if(*i == actual->paisesAdyacente[indiceAux]){
						comprobar2 = 1;
                        }
				}
				if (comprobar2 == 0){

					pila.push(actual->paisesAdyacente[indiceAux]);
                    }

				indiceAux++;
				}
			}
		}
	}
	
}

