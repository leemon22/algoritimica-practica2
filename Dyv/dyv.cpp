#include <cmath>
#include <cstddef>
#include <float.h>
#include <vector>
#include <algorithm>
#include "dyv.h"
#include "referencia.h"

#include <iostream>

using namespace std;

pair<referencia, referencia> algoritmoEspecifico(const vector<referencia> referencias){
	
	pair<referencia, referencia> resultado;
	float distancia_actual = FLT_MAX;
	float distancia_nueva;

	for(size_t i = 0; i < referencias.size(); i++){
		for(size_t j = i + 1; j < referencias.size(); j++){
			
			distancia_nueva = referencias[i].distancia(referencias[j]);

			if(distancia_nueva < distancia_actual){
				distancia_actual = distancia_nueva;
				resultado = {referencias[i], referencias[j]};
			}
		}
	}

	return resultado;
}

bool menorEjeX(referencia i, referencia j){
	if(!igualesEjeX(i,j)){
		return i.getVaca().getX() < j.getVaca().getX();
	}
	else{
		return i.getVaca().getY() < j.getVaca().getY();
	}
}

bool menorEjeY(referencia i, referencia j){
	if(!igualesEjeY(i,j)){
		return i.getVaca().getY() < j.getVaca().getY();
	}
	else{
		return i.getVaca().getX() < j.getVaca().getX();
	}
}

bool igualesEjeX(referencia i, referencia j){
	return i.getVaca().getX() == j.getVaca().getX();
}

bool igualesEjeY(referencia i, referencia j){
	return i.getVaca().getY() == j.getVaca().getY();
}

bool iguales(referencia i, referencia j){
	return igualesEjeX(i, j) && igualesEjeY(i, j);
}

typedef pair<vaca, vaca> par_vacas;
typedef pair<referencia, referencia> par_referencias;

par_vacas algoritmoDyV(const vector<vaca> &vacas, const int UMBRAL){
	// Creo los vectores de referencias
	vector<referencia> vx, vy;
	vx.reserve(vacas.size());
	vy.reserve(vacas.size());
	for(int i = 0; i < vacas.size(); i++){
		referencia r(vacas[i]);
		vx.push_back(r);
		vy.push_back(r);
	}

	// Ordeno los vectores de referencias
	sort(vx.begin(), vx.end(), menorEjeX);
	sort(vy.begin(), vy.end(), menorEjeY);
	
	// Comprobamos que no hay dos vacas iguales
	for(int i = 0; i < vx.size() - 1; i++){
		if(iguales(vx[i], vx[i+1])){
			vaca v = vx[i].getVaca();
			return {v,v};
		}
	}
	
	// Los paso a la función que hace la mayoría del trabajo
	par_referencias par = algoritmoDyVOrdenado(vx, vy, UMBRAL);
	return {par.first.getVaca(), par.second.getVaca()};
}

par_referencias algoritmoDyVOrdenado(const vector<referencia> &vx, const vector<referencia> &vy, const int UMBRAL){

	
	// Si el vector es pequeño devuelvo el resultado usando el algoritmo específico
	if(vx.size() <= UMBRAL)
		return algoritmoEspecifico(vx);

	// Si no, continuo con el algoritmo Divide y Vencerás
	// Separo en dos mitades con el mismo número de elementos
	vector<referencia> vx_superior, vx_inferior, vy_superior, vy_inferior;
	int mitad = vx.size()/2;
	vx_superior.reserve(mitad + 1);
	vx_inferior.reserve(mitad + 1);
	vy_superior.reserve(mitad + 1);
	vy_inferior.reserve(mitad + 1);

	referencia ref_mitad = vx[mitad];

	for(size_t i = 0; i < vx.size(); i++){
		if(menorEjeX(vx[i], ref_mitad)){
			vx_superior.push_back(vx[i]);
		}
		else{
			vx_inferior.push_back(vx[i]);
		}

		if(menorEjeX(vy[i], ref_mitad)){
			vy_superior.push_back(vy[i]);
		}
		else {
			vy_inferior.push_back(vy[i]);
		}
	}

	// Aplico divide y vencerás
	par_referencias par_superior = algoritmoDyVOrdenado(vx_superior, vy_superior, UMBRAL);
	float distancia_superior = par_superior.first.distancia(par_superior.second);
	par_referencias par_inferior = algoritmoDyVOrdenado(vx_inferior, vy_inferior, UMBRAL);
	float distancia_inferior = par_inferior.first.distancia(par_inferior.second);

	par_referencias par;
	float distancia;

	if(distancia_superior < distancia_inferior){
		par = par_superior;
		distancia = distancia_superior;
	}
	else {
		par = par_inferior;
		distancia = distancia_inferior;
	}

	// "Coso" las dos mitades
	float distancia_corregida = sqrt(distancia);
	float coordenada_corte = vx[mitad].getVaca().getX();

	vector<referencia> cercanos_al_corte;
	cercanos_al_corte.reserve(vy.size());

	// Nos quedamos solo con las vacas cercanas al corte
	for(int i = 0; i < vy.size(); i++){
		float distancia_al_corte = abs(vy[i].getVaca().getX() - coordenada_corte);
		if(distancia_al_corte < distancia_corregida)
			cercanos_al_corte.push_back(vy[i]);
	}

	for(int i = 1; i < cercanos_al_corte.size(); i++){
		vaca vaca_i = cercanos_al_corte[i].getVaca();

		int j = i - 1;
		bool suficientemente_cerca;
		do{
			vaca vaca_j = cercanos_al_corte[j].getVaca();
			float distancia_y = vaca_i.getY() - vaca_j.getY();
			suficientemente_cerca = distancia_y < distancia_corregida;

			if(suficientemente_cerca){
				float distancia_nueva = vaca_i.distancia(vaca_j);

				if(distancia_nueva < distancia){
					distancia = distancia_nueva;
					distancia_corregida = sqrt(distancia);
					par = {cercanos_al_corte[i], cercanos_al_corte[j]};
				}

				j--;
			}
		}while(j >= 0 && suficientemente_cerca);
	}
	
	return par;
}
