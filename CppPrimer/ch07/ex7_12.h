
#ifndef EX7_06_H
#define Ex7_06_H
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istream;
using std::ostream;



struct Sales_data
{
	string book_no;
	unsigned count=0;
	double revenue=0.0;
public:
	Sales_data()=default;
	Sales_data(const string & s):book_no(s){}
	Sales_data(const string & s,unsigned n,double p):
		book_no(s),count(n),revenue(p*n){}
	Sales_data(std::istream & is){read(is,*this);}
	string isbn()const{return book_no;};
	Sales_data & combine(const Sales_data &);
	
};



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

#endif
