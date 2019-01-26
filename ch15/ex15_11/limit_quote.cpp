#include "limit_quote.h"

double Limit_quote::net_price(std::size_t n) const
{
	return n * price * (n <= max_qty? (1 - discount) : 1);
}

void Limit_quote::debug() const
{ 
	cout << "Limit_quote------\nISBN : " << isbn() << 
		"\nprice : " << price <<
		"\nmax_qty : " << max_qty <<
		"\ndiscount : " << discount << endl;
}
