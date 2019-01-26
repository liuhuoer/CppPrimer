#include "derived.h"

void Derived::print(std::ostream& os)
{
	Base::print(os);
	os << "i : " << i << endl;
}
