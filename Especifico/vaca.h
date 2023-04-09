#ifndef __VACA_H__
#define __VACA_H__

#include <cmath>

class vaca{

private:
	float x;
	float y;

public:

	vaca(const float x, const float y);

	vaca();
	
	vaca(const vaca &other);

	float getX() const;

	float getY() const;

	float distancia(const vaca other) const;

	float distanciaReal(const vaca other) const;
};

#endif
