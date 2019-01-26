#include "base.cpp"
#include "pub_deriv.cpp"
#include "priv_deriv.cpp"
#include "prot_deriv.cpp"
#include "derived_from_public.cpp"
#include "derived_from_private.cpp"
#include "derived_from_protected.cpp"

int main()
{
	Pub_Deriv d1;
	Priv_Deriv d2;
	Prot_Deriv d3;
	Derived_from_Public dd1;
	Derived_from_Private dd2;
	Derived_from_Protected dd3;

	Base *p = &d1;
	//p = &d2;
	//p = &d3;
	p = &dd1;
	//p = &dd2;
	//p = &dd3;

	return 0;
}
