#ifndef BASKET_H
#define BASKET_H

#include "bulk_quote.h"
#include <set>
#include <memory>
using std::shared_ptr;using std::make_shared;
using std::multiset;

class Basket
{
public:
	void add_item(const shared_ptr<Quote>& sale)
	{ items.insert(sale);}
	void add_item(const Quote& sale)
	{ items.insert(shared_ptr<Quote>(sale.clone()));}
	void add_item(Quote&& sale)
	{ items.insert(shared_ptr<Quote>(std::move(sale).clone()));}

	//sum of all book's prices
	double total_receipt(std::ostream&) const;

private:
	static bool compare(const shared_ptr<Quote>& lhs, const shared_ptr<Quote>& rhs)
	{ return lhs->isbn() < rhs->isbn();}
	multiset<shared_ptr<Quote>, decltype(compare)*> items{compare};
};

#endif
