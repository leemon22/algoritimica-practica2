#ifndef __ESPECIFICO_H__
#define __ESPECIFICO_H__

#include <vector>
#include <utility>
#include <float.h>
#include "referencia.h"
#include "vaca.h"

using namespace std;

pair<referencia, referencia> algoritmoEspecifico(const vector<referencia> referencias);

bool menorEjeX(referencia i, referencia j);
bool menorEjeY(referencia i, referencia j);
bool igualesEjeX(referencia i, referencia j);
bool igualesEjeY(referencia i, referencia j);
bool iguales(referencia i, referencia j);

typedef pair<vaca, vaca> par_vacas;
typedef pair<referencia, referencia> par_referencias;

par_vacas algoritmoDyV(const vector<vaca> &vacas, const int UMBRAL);
par_referencias algoritmoDyVOrdenado(const vector<referencia> &vx, const vector<referencia> &vy, const int UMBRAL);

#endif
