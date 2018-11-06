#ifndef EX14_13_H
#define Ex14_13_H
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
	friend Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs);
	friend Sales_data operator-(const Sales_data& lhs, const Sales_data& rhs);
	friend istream& operator>>(istream& is, Sales_data& item);
	friend ostream& operator<<(ostream& os, const Sales_data& item);


public:
	Sales_data():Sales_data("",0,0.0f){}
	Sales_data(const string & s):Sales_data(s,0,0.0f){}
	Sales_data(const string & s,unsigned n,double p):
		book_no(s),count(n),revenue(p*n){}
	Sales_data(std::istream & is);

	Sales_data& operator+=(const Sales_data& rhs);
	Sales_data& operator-=(const Sales_data& rhs);
	string isbn()const{return book_no;};
	inline double avg_price()const;

private:
	string book_no;
	unsigned count=0;
	double revenue=0.0;

};

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs);
Sales_data operator-(const Sales_data& lhs, const Sales_data& rhs);
istream& operator>>(istream& is, Sales_data& item);
ostream& operator<<(ostream& os, const Sales_data& item);

#endif
