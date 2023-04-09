#include "vaca.h"
#include <cmath>

vaca::vaca(float x, float y):
	x(x), y(y)
{}

vaca::vaca():
	vaca(0.0f,0.0f)
{}

vaca::vaca(const vaca &other):
	vaca(other.x, other.y)
{}

float vaca::getX() const{
	return x;
}

float vaca::getY() const{
	return y;
}

float vaca::distancia(const vaca other) const{
	float x = this->x - other.x;
	float y = this->y - other.y;
	return x*x + y*y;
}

float vaca::distanciaReal(const vaca other) const{
	return sqrt(distancia(other));
}
