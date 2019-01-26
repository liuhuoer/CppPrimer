#include "bulk_quote.h"
inline
bool operator!=(const Bulk_quote& lhs, const Bulk_quote& rhs)
{ return (Quote(lhs) != Quote(rhs)) && (lhs.qty != rhs.qty) 
		&& (lhs.price != rhs.price);}

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
