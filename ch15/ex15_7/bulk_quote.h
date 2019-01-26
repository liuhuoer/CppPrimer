#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H 

#include "quote.h"

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
