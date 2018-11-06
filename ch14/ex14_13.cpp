#include "ex14_13.h"

Sales_data::Sales_data(std::istream & is):Sales_data()
{
	is>>*this;
}

double Sales_data::avg_price()const
{
	return count?revenue/count:0;
}

Sales_data operator+(const Sales_data & lhs, const Sales_data & rhs)
{
	Sales_data sum=lhs;
	sum+=rhs;
	return sum;
}

Sales_data operator-(const Sales_data & lhs, const Sales_data & rhs)
{
	Sales_data sum = lhs;
	sum -= rhs;
	return sum;
}


istream & operator>>(istream & is,Sales_data & item)
{
	double price;
	is>>item.book_no>>item.count>>price;
	if(is)
		item.revenue=price*item.count;
	else
		item=Sales_data();
	return is;
}

ostream & operator<<(ostream & os, const Sales_data & item)
{
	os<<item.isbn()<<" "<<item.count<<" "<<item.revenue;
	return os;
}

Sales_data& Sales_data::operator+=(const Sales_data& rhs)
{
	count+=rhs.count;
	revenue+=rhs.revenue;
	return *this;
}

Sales_data& Sales_data::operator-=(const Sales_data& rhs)
{
	count-=rhs.count;
	revenue-=rhs.revenue;
	return *this;
}

