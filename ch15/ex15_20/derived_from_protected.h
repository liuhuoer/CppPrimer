#ifndef DERIVED_FROM_PROTECTED_H
#define DERIVED_FROM_PROTECTED_H

#include "prot_deriv.h"

struct Derived_from_Protected : public Prot_Deriv
{
	void memfcn(Base& bas) { bas = *this;}
};

#endif
