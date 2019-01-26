#include "bulk_quote.h"

double Bulk_quote::net_price(std::size_t n) const
{
	return n * price * (n >= qty? (1 - disc) : 1);
}

void Bulk_quote::debug() const
{ 
	cout << "Bulk_quote------\nISBN : " << isbn() << 
		"\nprice : " << price <<
		"\nquantity : " << qty <<
		"\ndiscount : " << disc << endl;
}
