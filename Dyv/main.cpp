#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "vaca.h"
#include "dyv.h"

using namespace std;

int leerVacas(vector<vaca> &vacas, char *datos);

int main(int argc, char * argv[]){
	
	const int UMBRAL = 10;

	if(argc != 2){
		return 1;
	}

	vector<vaca> vacas;
	int estadoLectura = leerVacas(vacas, argv[1]);
	
	if(estadoLectura != 0){
		return 1;
	}

	pair<vaca, vaca> par_mas_cercano = algoritmoDyV(vacas, UMBRAL);
	vaca a = par_mas_cercano.first;
	vaca b = par_mas_cercano.second;
	float distancia = a.distanciaReal(b);

	cout << "PAR DE VACAS MÁS CERCANO USANDO EL ALGORITMO DIVIDE Y VENCERÁS" << endl;
	cout << "Coordenadas de las vacas:" << endl;
	cout << a.getX() << "\t" << a.getY() << endl;
	cout << b.getX() << "\t" << b.getY() << endl;
	cout << "Distancia: " << distancia << endl;

	return 0;
}

int leerVacas(vector<vaca> &vacas, char *datos){

	ifstream archivo(datos);
	if(!archivo.is_open())
		return 2;

	float x,y;
	while (archivo >> x >> y){
		if(archivo.fail()){
			archivo.close();
			return 1;
		}
		vacas.push_back(vaca(x,y));
	}

	archivo.close();
	return 0;
}
