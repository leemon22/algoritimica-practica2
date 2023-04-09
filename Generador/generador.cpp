#include "generador.h"

using namespace std;

vector<pair<float, float>> generadorCoords(int numVacas){
	
	const float TMN = 100;
	
	random_device rd;
    	mt19937 gen(rd());
    	uniform_real_distribution<> dis(0.0, TMN);
	
	vector<pair<float, float>> ret;
	pair<float, float> p;
	
	for(int i = 0 ; i < numVacas ; i++){
		p.first = dis(gen);
		p.second = dis(gen);
		ret.push_back(p);
	}
	
	return ret;
	
}
