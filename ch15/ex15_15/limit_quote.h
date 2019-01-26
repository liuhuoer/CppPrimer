#ifndef LIMIT_QUOTE_H
#define LIMIT_QUOTE_H 

#include "disc_quote.h"

class Limit_quote : public Disc_quote
{
public:
	Limit_quote() = default;
	Limit_quote(string bookNo_, double price_, std::size_t qty_,
			double disc_)
		: Disc_quote(bookNo_, price_, qty_, disc_)
	{ }

	double net_price(std::size_t n) const override;
	void debug() const override;
private:
};

#endif
