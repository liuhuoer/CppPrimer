#include "ex14_20.h"

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
	sum += rhs;
	return sum;
}

Sales_data& Sales_data::operator+=(const Sales_data& rhs)
{
	count += rhs.count;
	revenue += rhs.revenue;
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

