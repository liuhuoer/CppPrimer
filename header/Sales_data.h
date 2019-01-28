#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istream;
using std::ostream;


class Sales_data
{
	friend bool compareIsbn(const Sales_data & lhs,const Sales_data & rhs);
	friend istream & operator >>(istream & in,Sales_data & s);
	friend ostream & operator <<(ostream & out,const Sales_data & s);
//	friend Sales_data add(const Sales_data & lhs,const Sales_data & rhs);
//	friend istream & read(istream & is,Sales_data & item);
//	friend ostream & print(ostream & os, Sales_data & item);

public:
	Sales_data()=default;
	Sales_data(const string & s):book_no(s){}
	Sales_data(const string & s,unsigned n,double p):
		book_no(s),count(n),revenue(p*n){}
//	Sales_data(istream & is){read(is,*this);}

	Sales_data & operator +=(const Sales_data & rhs);

	string isbn()const{return book_no;};
	unsigned get_count()const{return count;};
	double get_revenue()const{return revenue;};
//	Sales_data & combine(const Sales_data &);

private:
	string book_no;
	unsigned count=0;
	double revenue=0.0;

};

bool compareIsbn(const Sales_data & lhs,const Sales_data & rhs)
{
	return lhs.isbn()<rhs.isbn();
}

Sales_data & Sales_data::operator +=(const Sales_data & rhs)
{
	this->count+=rhs.count;
	this->revenue+=rhs.revenue;
	return *this;
}

//rewrite_: operator + and >> is not Sales_data’s member function
Sales_data operator +(const Sales_data & lhs,const Sales_data & rhs)
{
	Sales_data sum(lhs);
	sum+=rhs;
	return sum;
}

istream & operator >>(istream & in,Sales_data & s)
{
	double price=0.0;
	if(!in)		//rewrite_: check the inputs succeed;
		s=Sales_data();
	else
	{
		in>>s.book_no>>s.count>>price;
		s.revenue=s.count*price;
	}
	
	return in;
}
ostream & operator <<(ostream & out,const Sales_data & s)
{
	out<<s.isbn()<<" "<<s.count<<" "<<s.revenue;

	return out;
}

//Sales_data & Sales_data::combine(const Sales_data & add_sum)
//{
//	count+=add_sum.count;
//	revenue+=add_sum.revenue;
//	return *this;
//}
//
//Sales_data add(const Sales_data & lhs,const Sales_data & rhs)
//{
//	Sales_data sum=lhs;
//	sum.combine(rhs);
//	return sum;
//}
//
//istream & read(istream & is,Sales_data & item)
//{
//	double price=0;
//	is>>item.book_no>>item.count>>price;
//	item.revenue=price*item.count;
//	return is;
//}
//
//ostream & print(ostream & os, Sales_data & item)
//{
//	os<<item.isbn()<<" "<<item.count<<" "<<item.revenue;
//	return os;
//}

#endif
