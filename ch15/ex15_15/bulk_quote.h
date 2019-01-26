#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H 

#include "disc_quote.h"

class Bulk_quote : public Disc_quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(string bookNo_, double price_, std::size_t min_qty_, double discount_)
		: Disc_quote(bookNo_, price_, min_qty_, discount_)
	{ }

	double net_price(std::size_t n) const override;
	void debug() const override;
private:
};

#endif
