#include "limit_quote.h"

double Limit_quote::net_price(std::size_t n) const
{
	return n * price * (n <= qty? (1 - disc) : 1);
}

void Limit_quote::debug() const
{ 
	cout << "Limit_quote------\nISBN : " << isbn() << 
		"\nprice : " << price <<
		"\nquantity : " << qty <<
		"\ndiscount : " << disc << endl;
}
