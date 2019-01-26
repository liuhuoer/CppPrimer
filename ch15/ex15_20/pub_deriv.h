#ifndef PUB_DERIV_H
#define PUB_DERIV_H

#include "base.h"

class Pub_Deriv : public Base
{
public:
	void memfcn(Base& bas) { bas = *this;}

};

#endif
