#include "basket.h"

double Basket::total_receipt(std::ostream& os) const
{
	double sum = 0.0;
	for(auto cbg = items.cbegin();
			cbg != items.cend();
			cbg = items.upper_bound(*cbg))
		sum += print_total(os, **cbg, items.count(*cbg));
	os << "sum = " << sum << endl;
	return sum;

}
