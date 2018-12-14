#ifndef EX14_21_H
#define Ex14_21_H
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
	friend istream& operator>>(istream&, Sales_data&);
	friend ostream& operator<<(ostream&, const Sales_data&);

	friend Sales_data operator+(const Sales_data&, const Sales_data&);

public:
	//constructors
	Sales_data() : Sales_data("", 0, 0.0f) {}

	Sales_data(const string & s) : Sales_data(s, 0, 0.0f) {}

	Sales_data(const string & s, unsigned n, double p):
		book_no(s), count(n), revenue(p * n) {}

	Sales_data(std::istream & is);

	//operators
	Sales_data& operator+=(const Sales_data& rhs);

	//member_functions
	string isbn() const {return book_no;};
	Sales_data & combine(const Sales_data &);
	inline double avg_price() const;

private:
	string book_no;
	unsigned count=0;
	double revenue=0.0;
};

istream& operator>>(istream& is, Sales_data& item);
ostream& operator<<(ostream& os, const Sales_data& item);

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs);

#endif
