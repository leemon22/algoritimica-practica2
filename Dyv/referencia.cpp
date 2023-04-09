#include "vaca.h"
#include "referencia.h"

referencia::referencia(const vaca &v){
	p = &v;
}

referencia::referencia(const referencia &other){
	p = other.p;
}
