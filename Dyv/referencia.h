#ifndef __REFERENCIA_H__
#define __REFERENCIA_H__

#include "vaca.h"

class referencia{

private:
	vaca *p;

public:

	referencia(const vaca &v);
	referencia(const referencia &r);

	vaca getVaca();
	float distancia(const referencia &other) const;
};

#endif
