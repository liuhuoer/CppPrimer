#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H

#include "quote.h"

class Disc_quote : public Quote
{
	friend bool operator!=(const Disc_quote&, const Disc_quote&);
public:
	Disc_quote() = default;
	Disc_quote(const string& bookNo_, double price_, std::size_t qty_, double disc_)
		: Quote(bookNo_, price_), qty(qty_), disc(disc_)
	{ }
	Disc_quote(const Disc_quote& disc_quo) 
		: Quote(disc_quo), qty(disc_quo.qty), disc(disc_quo.disc)
	{ }
	Disc_quote(Disc_quote&& disc_quo) noexcept 
		: Quote(std::move(disc_quo)), qty(std::move(disc_quo.qty)), disc(std::move(disc_quo.disc))
	{ }
	Disc_quote& operator=(const Disc_quote& rhs)
	{
		if(rhs != *this)
		{
			Quote::operator=(rhs);
			qty = rhs.qty;
			disc = rhs.disc;
		}
		return *this;
	}
	Disc_quote& operator=(Disc_quote&& rhs) noexcept
	{
		if(rhs != *this)
		{
			Quote::operator=(std::move(rhs));
			qty = std::move(rhs.qty);
			disc = std::move(rhs.disc);
		}
		return *this;
	}
	~Disc_quote()
	{ }

	double net_price(std::size_t) const override = 0;

protected:
	std::size_t qty = 0;
	double disc = 0.0;
};

inline 
bool operator!=(const Disc_quote&, const Disc_quote&);

#endif
