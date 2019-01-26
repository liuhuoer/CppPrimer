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

