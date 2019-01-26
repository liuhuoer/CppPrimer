#include "ex15_3.h"

double print_total(ostream& os, const Quote& quo, std::size_t n)
{
	double prices = quo.net_price(n);
	os << quo.isbn() << " " << prices << endl;
	return prices;
}

int main()
{
	Quote quo("DB", 9.9);
	print_total(cout, quo, 1);

	return 0;
}
