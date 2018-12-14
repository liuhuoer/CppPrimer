#include "ex14_21.h"

/*************************************************************
 *			constructors
 *
 * **********************************************************/
Sales_data::Sales_data(std::istream& is) : Sales_data()
{
	is >> *this;
}

/************************************************************
 *			operators
 * 
 * *********************************************************/

istream & operator>>(istream & is, Sales_data & item)
{
	double price=0;
	is >> item.book_no >> item.count >> price;
	item.revenue = price * item.count;
	return is;
}

ostream & operator<<(ostream & os, const Sales_data & item)
{
	os << item.isbn() << " " << item.count << " " << item.revenue;
	return os;
}

Sales_data operator+(const Sales_data & lhs, const Sales_data & rhs)
{
	Sales_data sum = lhs;
	sum.count += rhs.count;
	sum.revenue += rhs.revenue;

	return sum;
}

Sales_data& Sales_data::operator+=(const Sales_data& rhs)
{
	Sales_data sum = *this;
	*this = sum + rhs;
	return *this;
}

/************************************************************
 *			member_functions
 *
 * *********************************************************/

double Sales_data::avg_price() const
{
	return count ? revenue / count : 0;
}

