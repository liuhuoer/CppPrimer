#ifndef QUOTE_H
#define QUOTE_H

#include <string>
#include <iostream>

using std::string;
using std::cout;using std::endl;
using std::ostream;

class Quote
{
	friend bool operator!=(const Quote& lhs, const Quote& rhs);
public:
	Quote()
	{ cout << "Quote()" << endl;}
	Quote(const string& s, double d) : bookNo(s), price(d)
	{ cout << "Quote(4)" << endl;} 
	Quote(const Quote& quo) : bookNo(quo.bookNo), price(quo.price)
	{ cout << "Quote(const Quote&) " << endl;}
	Quote(Quote&& quo) noexcept : bookNo(std::move(quo.bookNo)), price(std::move(quo.price))
	{ cout << "Quote(Quote&&) " << endl;}
	Quote& operator=(const Quote& rhs) 
	{
		if(rhs != *this)
		{
			bookNo = rhs.bookNo;
			price = rhs.price;
		}
		cout << "operator=(const Quote&)" << endl;
		return *this; 
	}
	Quote& operator=(Quote&& rhs) noexcept 
	{
		if(rhs != *this)
		{
			bookNo = std::move(rhs.bookNo);
			price = std::move(rhs.price);
		}
		cout << "operator=(Quote&&)" << endl;
		return *this;
	}

	virtual ~Quote()
	{ cout << "~Quote()" << endl;}

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

#endif
