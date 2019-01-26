#ifndef PRIV_DERIV_H
#define PRIV_DERIV_H

#include "base.h"

class Priv_Deriv : private Base
{
public:
	void memfcn(Base& bas) { bas = *this;}
};

#endif
