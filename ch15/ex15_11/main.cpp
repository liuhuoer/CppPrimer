#include "quote.cpp"
#include "bulk_quote.cpp"
#include "limit_quote.cpp"

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
	Limit_quote limit_quo("DB", 9.9, 10, 0.5);
	
	quo.debug();
	bulk_quo.debug();
	limit_quo.debug();
	return 0;
}
