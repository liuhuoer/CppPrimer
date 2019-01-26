#ifndef LIMIT_QUOTE_H
#define LIMIT_QUOTE_H 

#include "quote.h"

class Limit_quote : public Quote
{
public:
	Limit_quote() = default;
	Limit_quote(string bookNo_, double price_, std::size_t max_qty_,
			double discount_)
		: Quote(bookNo_, price_), max_qty(max_qty_), discount(discount_)
	{ }
	virtual double net_price(std::size_t n) const override;
private:
	std::size_t max_qty;
	double discount;
};

#endif
