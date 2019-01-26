#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H 

#include "disc_quote.h"

class Bulk_quote : public Disc_quote
{
	friend bool operator!=(const Bulk_quote&, const Bulk_quote&); 
public:
	Bulk_quote() = default;
	/*
	Bulk_quote(string bookNo_, double price_, std::size_t min_qty_, double discount_)
		: Disc_quote(bookNo_, price_, min_qty_, discount_)
	{ cout << "Bulk_quote(4)" << endl;}
	*/
	using Disc_quote::Disc_quote;

	Bulk_quote(const Bulk_quote& bul) : Disc_quote(bul)
	{ }
	Bulk_quote(Bulk_quote&& bul) noexcept : Disc_quote(std::move(bul)) 
	{ }
	Bulk_quote& operator=(const Bulk_quote& rhs)
	{
		if(rhs != *this)
		{
			Disc_quote::operator=(rhs);
		}
		return *this;
	}
	Bulk_quote& operator=(Bulk_quote&& rhs) noexcept
	{
		if(rhs != *this)
		{
			Disc_quote::operator=(std::move(rhs));
		}
		return *this;
	}
	~Bulk_quote()
	{ } 

	double net_price(std::size_t n) const override;
	void debug() const override;
};

inline
bool operator!=(const Bulk_quote&, const Bulk_quote&);

#endif
