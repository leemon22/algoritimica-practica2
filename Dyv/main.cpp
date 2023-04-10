#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "vaca.h"
#include "dyv.h"
#include <chrono>

using namespace std;

int leerVacas(vector<vaca> &vacas, char *datos);

int main(int argc, char * argv[]){
	
	/* const int UMBRAL = 10; */

	if(argc != 3){
		return 1;
	}

	int UMBRAL = stoi(argv[1]);

	vector<vaca> vacas;
	int estadoLectura = leerVacas(vacas, argv[2]);
	
	if(estadoLectura != 0){
		return 1;
	}

	std::chrono::high_resolution_clock::time_point t_antes, t_despues;
  	std::chrono::duration<double> transcurrido;
  
 	t_antes = std::chrono::high_resolution_clock::now();
 	
	pair<vaca, vaca> par_mas_cercano = algoritmoDyV(vacas, UMBRAL);
	
	t_despues = std::chrono::high_resolution_clock::now();

	transcurrido = std::chrono::duration_cast<std::chrono::duration<double>>(t_despues - t_antes);
	
	cout << vacas.size() << " " << transcurrido.count() << endl;
	
	
	vaca a = par_mas_cercano.first;
	vaca b = par_mas_cercano.second;
	float distancia = a.distanciaReal(b);
	
	/*
	cout << "PAR DE VACAS MÁS CERCANO USANDO EL ALGORITMO DIVIDE Y VENCERÁS" << endl;
	cout << "Coordenadas de las vacas:" << endl;
	cout << a.getX() << "\t" << a.getY() << endl;
	cout << b.getX() << "\t" << b.getY() << endl;
	cout << "Distancia: " << distancia << endl;
	*/

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
