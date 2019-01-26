#include "quote.h"

inline
bool operator!=(const Quote& lhs, const Quote& rhs)
{
	return (lhs.bookNo != rhs.bookNo) && (lhs.price != rhs.price);
}
void Quote::debug() const
{ 
	cout << "quote------\nISBN : " << bookNo << "\nprice : " << price << endl;
}

double print_total(ostream& os, const Quote& quo, std::size_t n)
{
	double prices = quo.net_price(n);
	os << "isbn = " << quo.isbn() << "\nn =  " << n 
		<< "\nprices = "<< prices 
		<< "\n***********************" << endl;
	return prices;
}

