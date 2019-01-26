#include "quote.cpp"
#include "disc_quote.cpp"
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
	//Quote quo("DB", 9.9);
	Bulk_quote bulk_quo("DB", 9.9, 10, 0.5);
	
	Bulk_quote bulk_quo_cp(bulk_quo);
	
	return 0;
}
