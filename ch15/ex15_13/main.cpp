#include "base.cpp"
#include "derived.cpp"

int main()
{
	Base bas;
	Derived der;
	Base* bas_ptr = &der;
	Base& bas2 = der;

	bas.print(cout);
	(*bas_ptr).print(cout);
	bas2.print(cout);
	der.print(cout);

	return 0;
}
