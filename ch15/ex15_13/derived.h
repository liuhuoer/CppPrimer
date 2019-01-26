#ifndef DERIVED_H
#define DERIVED_H

#include "base.h"

class Derived : public Base
{
public:
	void print(std::ostream& os) override;
private:
	int i = 1;
};

#endif
