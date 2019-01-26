#ifndef PROT_DERIV_H
#define PROT_DERIV_H

#include "base.h"

class Prot_Deriv : protected Base
{
public:
	void memfcn(Base& bas) { bas = *this;}

};

#endif
