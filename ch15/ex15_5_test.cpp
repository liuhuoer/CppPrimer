#include "ex15_5.cpp"

double print_total(ostream& os, const Quote& quo, std::size_t n)
{
	double prices = quo.net_price(n);
	os << quo.isbn() << " " << prices << endl;
	return prices;
}

int main()
{
	Quote quo("DB", 9.9);
	Bulk_quote bulk_quo("DB", 9.9, 10, 0.5);
	print_total(cout, quo, 1);
	print_total(cout, bulk_quo, 10);

	return 0;
}
