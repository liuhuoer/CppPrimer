#ifndef DERIVED_FROM_PUBLIC_H
#define DERIVED_FROM_PUBLIC_H

#include "pub_deriv.h"

struct Derived_from_Public : public Pub_Deriv
{
	void memfcn(Base& bas) { bas = *this;}
};

#endif
