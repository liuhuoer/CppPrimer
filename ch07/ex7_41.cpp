#include "ex7_41.h"

Sales_data::Sales_data(std::istream & is):Sales_data()
{
	cout<<"Sales_data(std::istream & is)"<<endl;
	read(is,*this);
}

double Sales_data::avg_price()const
{
	return count?revenue/count:0;
}

Sales_data & Sales_data::combine(const Sales_data & add_sum)
{
	count+=add_sum.count;
	revenue+=add_sum.revenue;
	return *this;
}

Sales_data add(const Sales_data & lhs,const Sales_data & rhs)
{
	Sales_data sum=lhs;
	sum.combine(rhs);
	return sum;
}

istream & read(istream & is,Sales_data & item)
{
	double price=0;
	is>>item.book_no>>item.count>>price;
	item.revenue=price*item.count;
	return is;
}

ostream & print(ostream & os, Sales_data & item)
{
	os<<item.isbn()<<" "<<item.count<<" "<<item.revenue;
	return os;
}


