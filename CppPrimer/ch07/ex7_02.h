#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Sales_data
{
	string isbn()const{return bookNo;};
	Sales_data & combine(const Sales_data &);
	string bookNo;
	unsigned salesCount=0;
	double revenue=0.0;
};

Sales_data & Sales_data::combine(const Sales_data & add_sum)
{
	salesCount+=add_sum.salesCount;
	revenue+=add_sum.revenue;
	return *this;
}


