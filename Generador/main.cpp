#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "generador.h"

using namespace std;

int main(int argc, char * argv[]){

	if(argc != 2){
		cout << "Debe incluir un parámetro: el número de vacas" << endl;
		return 1;
	}
	
	vector<pair<float, float>> v = generadorCoords(stoi(argv[1]));
	
	ofstream o;
	o.open("Vacasgeolocalizadas" + to_string(v.size()) + ".txt");
	
	for(int i = 0 ; i < v.size() ; i++){
		o << v[i].first << "\t" << v[i].second;
		o << "\n";
	}
	
	return 0;
}
