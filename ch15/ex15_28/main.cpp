#include "quote.cpp"
#include "disc_quote.cpp"
#include "bulk_quote.cpp"
#include "limit_quote.cpp"
#include <memory>

double print_total(ostream& os, const Quote& quo, std::size_t n)
{
	double prices = quo.net_price(n);
	os << quo.isbn() << " " << prices << endl;
	return prices;
}

int main()
{
	vector<Quote*> vq;
	Quote quo("DB", 5);
	Bulk_quote bul("OS", 20, 10, 0.5);

	//vq.push_back(std::make_shared<Quote>("DB", 5));
	//vq.push_back(std::make_shared<Bulk_Quote>("OS", 20, 10, 0.5));
	vq.push_back(&quo);
	vq.push_back(&bul);
	
	int sum = 0;
	for(auto a : vq)
		sum += a->net_price(10);
	cout << "sum = " << sum << endl;
	
	return 0;
}
