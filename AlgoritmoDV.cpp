#include "AlgoritmoDV.h"


using namespace std;

AlgoritmoDV::AlgoritmoDV(Mundo* mundo,int pNumColores,std::vector<std::string> todosLosColores, ManejadorDocs* manejador)
{
    this->mundo = mundo;
	this->pNumColores = pNumColores;
	this->todosLosColores = todosLosColores;
	this->manejador = manejador;
	
}


std::vector<int> AlgoritmoDV::hacerVectorColores(int pNumColores){

	std::vector<int> vectorColores{};

	for (int i = 1; i <= pNumColores; i++)
	{
		vectorColores.push_back(i);
	}
	vectorColores.push_back(0);
	return vectorColores;
}

void AlgoritmoDV::realizarDV(){

    std::vector<int> ColoresPos{};
	ColoresPos = hacerVectorColores(pNumColores);
	std::vector<int> ReinicioColoresPos = ColoresPos;
	int indiceRegion = mundo->getSizeRegiones();
	int contadorBlancos=0;

	
	int comprobar,comprobar2,comprobarColor;
	Pais* actual;
	Pais* actualBuffer;
	
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

			//cout<< actual->nombre<< ", ";
			for (int i = 0; i < actual->paisesAdyacente.size(); i++){

                new_end = remove(ColoresPos.begin(), ColoresPos.end(), actual->paisesAdyacente[i]->colorBT);

            }
				
			lista.push_back(actual);
			actual->colorBT=ColoresPos[0];
			//cout<< actual->colorBT<< ", ";

			if (actual->colorBT==0)
			{
				contadorBlancos++;
			}
			
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
		//lazy writting
		for (i=lista.begin(); i!=lista.end(); i++){
			actualBuffer=*i;
			if (actualBuffer->colorBT!=0)
			{
				actualBuffer->pintarPaisDV(todosLosColores[actualBuffer->colorBT-1]);
				manejador->docDV.save_file("worldDivideVenceras.svg");
			}
		}
		lista={};
	}
	cout << "Total de Paises en Blanco Algoritmo Programacion Divide y Venceras " << contadorBlancos <<endl;

}

