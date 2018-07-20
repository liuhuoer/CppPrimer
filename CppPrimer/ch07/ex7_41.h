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

class Sales_data
{
	friend Sales_data add(const Sales_data & lhs,const Sales_data & rhs);
	friend istream & read(istream & is,Sales_data & item);
	friend ostream & print(ostream & os, Sales_data & item);

public:
	Sales_data():Sales_data("",0,0.0f)
	{cout<<"Sales_data()"<<endl;}

	Sales_data(const string & s):Sales_data(s,0,0.0f)
	{cout<<"Sales_data(const std::string &)"<<endl;}

	Sales_data(const string & s,unsigned n,double p):
		book_no(s),count(n),revenue(p*n)
	{cout<<"Sales_data(const string & s,unsigned n,double p)"<<endl;}

	Sales_data(std::istream & is);

	string isbn()const{return book_no;};
	Sales_data & combine(const Sales_data &);
	inline double avg_price()const;

private:
	string book_no;
	unsigned count=0;
	double revenue=0.0;

};

Sales_data add(const Sales_data & lhs,const Sales_data & rhs);

istream & read(istream & is,Sales_data & item);

ostream & print(ostream & os, Sales_data & item);

#endif
