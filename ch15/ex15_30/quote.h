#ifndef QUOTE_H
#define QUOTE_H

#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::cout;using std::endl;
using std::ostream;
using std::vector;

class Quote
{
	friend bool operator!=(const Quote& lhs, const Quote& rhs);
public:
	Quote() = default;
	Quote(const string& s, double d) : bookNo(s), price(d)
	{ }
	Quote(const Quote& quo) : bookNo(quo.bookNo), price(quo.price)
	{ }
	Quote(Quote&& quo) noexcept : bookNo(std::move(quo.bookNo)), price(std::move(quo.price))
	{ }
	Quote& operator=(const Quote& rhs) 
	{
		if(rhs != *this)
		{
			bookNo = rhs.bookNo;
			price = rhs.price;
		}
		return *this; 
	}
	Quote& operator=(Quote&& rhs) noexcept 
	{
		if(rhs != *this)
		{
			bookNo = std::move(rhs.bookNo);
			price = std::move(rhs.price);
		}
		return *this;
	}

	virtual ~Quote()
	{ }

	virtual Quote* clone() const& 
	{ return new Quote(*this);}
	virtual Quote* clone() && 
	{ return new Quote(std::move(*this));}

	string isbn() const
	{ return bookNo;}

	virtual double net_price(std::size_t n) const
	{ return price * n;}
	virtual void debug() const;

private:	
	string bookNo;
protected:
	double price;
};

bool operator!=(const Quote& lhs, const Quote& rhs);

double print_total(ostream& os, const Quote& quo, std::size_t n);

#endif
