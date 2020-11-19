#include "AlgoritmoProgDina.h"


using namespace std;

AlgoritmoProgDina::AlgoritmoProgDina(Mundo* mundo,int pNumColores)
{
    this->mundo = mundo;
	this->pNumColores = pNumColores;
}

std::vector<int> AlgoritmoProgDina::hacerVectorColores(int pNumColores){

	std::vector<int> vectorColores{};

	for (int i = 1; i <= pNumColores; i++)
	{
		vectorColores.push_back(i);
	}
	vectorColores.push_back(0);
	return vectorColores;
}

std::tuple<int, std::vector<int>> AlgoritmoProgDina::asignarMejorColor(std::vector<int> pColoresUsar,std::vector<int> pContadorColores){

	//Ej : {1,2,3,0} ,{0,0,0,0,0,0,0,0,0,0,0}
	std::tuple<int, std::vector<int>> respuestaColor{};
	int indiceRevisar = 0;
	int menorAparecion = 0;
	int colorUsar =0;
	if (pColoresUsar[0]==0)
	{
		pContadorColores[11]= pContadorColores[11]+1;
	}
	
	if (pColoresUsar[0]!=0)
	{
		menorAparecion=pContadorColores[0];
	}
	
	while (indiceRevisar<pColoresUsar.size()){
		switch (pColoresUsar[indiceRevisar])
		{
		case 1:
			if (pContadorColores[0]<=menorAparecion)
			{
				colorUsar=pColoresUsar[indiceRevisar];
				menorAparecion=pContadorColores[0];
			}
			break;
		case 2:
			if (pContadorColores[1]<=menorAparecion)
			{
				colorUsar=pColoresUsar[indiceRevisar];
				menorAparecion=pContadorColores[1];
			}
			break;
		case 3:
			if (pContadorColores[2]<=menorAparecion)
			{
				colorUsar=pColoresUsar[indiceRevisar];
				menorAparecion=pContadorColores[2];
			}
			break;
		case 4:
			if (pContadorColores[3]<=menorAparecion)
			{
				colorUsar=pColoresUsar[indiceRevisar];
				menorAparecion=pContadorColores[3];
			}
			break;
		case 5:
			if (pContadorColores[4]<=menorAparecion)
			{
				colorUsar=pColoresUsar[indiceRevisar];
				menorAparecion=pContadorColores[4];
			}
			break;
		case 6:
			if (pContadorColores[5]<=menorAparecion)
			{
				colorUsar=pColoresUsar[indiceRevisar];
				menorAparecion=pContadorColores[5];
			}
			break;
		case 7:
			if (pContadorColores[6]<=menorAparecion)
			{
				colorUsar=pColoresUsar[indiceRevisar];
				menorAparecion=pContadorColores[6];
			}
			break;
		case 8:
			if (pContadorColores[7]<=menorAparecion)
			{
				colorUsar=pColoresUsar[indiceRevisar];
				menorAparecion=pContadorColores[7];
			}
			break;
		case 9:
			if (pContadorColores[8]<=menorAparecion)
			{
				colorUsar=pColoresUsar[indiceRevisar];
				menorAparecion=pContadorColores[8];
			}
			break;
		case 10:
			if (pContadorColores[9]<=menorAparecion)
			{
				colorUsar=pColoresUsar[indiceRevisar];
				menorAparecion=pContadorColores[9];
			}
			break;
		case 11:
			if (pContadorColores[10]<=menorAparecion)
			{
				colorUsar=pColoresUsar[indiceRevisar];
				menorAparecion=pContadorColores[10];
			}
			break;
		

		default:
			break;
		}

		indiceRevisar++;
	}
	
	menorAparecion++;
	pContadorColores[colorUsar-1] = menorAparecion;
	
	respuestaColor = make_tuple(colorUsar,pContadorColores);
    return respuestaColor;

}

void AlgoritmoProgDina::realizarProgDina(){


	
	std::vector<int> ColoresPos{};
	ColoresPos = hacerVectorColores(pNumColores);
	std::vector<int> ColoresUsados{0,0,0,0,0,0,0,0,0,0,0,0};;
	std::vector<int> ReinicioColoresPos = ColoresPos;
	std::tuple<int, std::vector<int>> RespuestasColores{};

	int comprobar,comprobar2,comprobarColor;
	int indiceRegion = mundo->getSizeRegiones();
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

			for (i=lista.begin(); i!=lista.end(); i++)
			{
				if(*i == actual){
					comprobar = 1;
				}
			}
			if (comprobar == 0)
			{
				cout<< actual->nombre<< ", ";
				for (int i = 0; i < actual->paisesAdyacente.size(); i++)
				{
					new_end = remove(ColoresPos.begin(), ColoresPos.end(), actual->paisesAdyacente[i]->colorBT);
				}
				
				lista.push_back(actual);
				//Asignacion del Color
				RespuestasColores=asignarMejorColor(ColoresPos,ColoresUsados);
				ColoresUsados = std::get<1>(RespuestasColores);


				actual->colorBT=std::get<0>(RespuestasColores);
				ColoresPos=ReinicioColoresPos;
				//Aux para 
				int aux;
                int indiceAux = 0;
				aux = actual->paisesAdyacente.size();

				while (indiceAux < aux)
				{
					comprobar2 = 0;
					for ( i=lista.begin(); i!=lista.end(); i++)
					{
						if(*i == actual->paisesAdyacente[indiceAux]){
							comprobar2 = 1;
                            
						}
					}
					if (comprobar2 == 0)
					{
						pila.push(actual->paisesAdyacente[indiceAux]);
					}
					indiceAux++;
				}
				

			}
			
		}
	}
	


	for (int i = 0; i < lista.size(); i++)
	{
		cout << lista[i]->nombre << " codigo del pais ";
		cout << lista[i]->colorBT << endl;
	}

		
	
}
