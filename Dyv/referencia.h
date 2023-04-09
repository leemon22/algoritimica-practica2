#ifndef __REFERENCIA_H__
#define __REFERENCIA_H__

#include "vaca.h"

class referencia{

private:
	const vaca *p;

public:

	referencia(const vaca &v);
	referencia();
	referencia(const referencia &r);

	const vaca &getVaca() const;
	float distancia(const referencia &other) const;
};

#endif
