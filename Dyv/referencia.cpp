#include "vaca.h"
#include "referencia.h"

referencia::referencia(const vaca &v):
	p(&v)
{}

referencia::referencia():
	p(nullptr)
{}

referencia::referencia(const referencia &other){
	p = other.p;
}

const vaca &referencia::getVaca() const{
	return *p;
}

float referencia::distancia(const referencia &other) const{
	return getVaca().distancia(other.getVaca());
}
