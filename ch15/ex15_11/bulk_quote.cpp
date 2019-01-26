#include "bulk_quote.h"

double Bulk_quote::net_price(std::size_t n) const
{
	return n * price * (n >= min_qty? (1 - discount) : 1);
}

void Bulk_quote::debug() const
{ 
	cout << "Bulk_quote------\nISBN : " << isbn() << 
		"\nprice : " << price <<
		"\nmin_qty : " << min_qty <<
		"\ndiscount : " << discount << endl;
}
