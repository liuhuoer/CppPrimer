#ifndef DERIVED_FROM_PRIVATE_H
#define DERIVED_FROM_PRIVATE_H

#include "priv_deriv.h"

struct Derived_from_Private : public Priv_Deriv
{
	//void memfcn(Base& bas) { bas = *this;}
};

#endif
