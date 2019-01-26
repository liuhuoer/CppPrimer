#ifndef QUOTE_H
#define QUOTE_H

#include <string>
#include <iostream>

using std::string;
using std::cout;using std::endl;
using std::ostream;

class Quote
{
public:
	Quote() = default;
	Quote(const string& s, double d) : bookNo(s), price(d)
	{ }
	virtual ~Quote() = default;

	string isbn() const
	{ return bookNo;}

	virtual double net_price(std::size_t n) const
	{ return price * n;}

private:	
	string bookNo;
protected:
	double price;
};


#endif
