#ifndef EX15_5_H
#define EX15_5_H

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

class Bulk_quote : public Quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(string bookNo_, double price_, std::size_t min_qty_, double discount_)
		: Quote(bookNo_, price_), min_qty(min_qty_), discount(discount_)
	{ }
	virtual double net_price(std::size_t n) const override;
private:
	std::size_t min_qty;
	double discount;
};

#endif
