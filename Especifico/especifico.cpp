#include "especifico.h"
#include <cstddef>
#include <float.h>

using namespace std;

pair<vaca, vaca> algoritmoEspecifico(const vector<vaca> vacas){
	
	pair<vaca, vaca> resultado;
	float distancia_actual = FLT_MAX;
	float distancia_nueva;

	for(size_t i = 0; i < vacas.size(); i++){
		for(size_t j = i + 1; j < vacas.size(); j++){
			
			distancia_nueva = vacas[i].distancia(vacas[j]);

			if(distancia_nueva < distancia_actual){
				distancia_actual = distancia_nueva;
				resultado = {vacas[i], vacas[j]};
			}
		}
	}

	return resultado;
}
