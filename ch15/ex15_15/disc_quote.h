#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H

#include "quote.h"

class Disc_quote : public Quote
{
public:
	Disc_quote() = default;
	Disc_quote(const string& bookNo_, double price_, std::size_t qty_, double disc_)
		: Quote(bookNo_, price_), qty(qty_), disc(disc_)
	{ }

	double net_price(std::size_t) const override = 0;
protected:
	std::size_t qty = 0;
	double disc = 0.0;
};

#endif
