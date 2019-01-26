#include "quote.cpp"
#include "disc_quote.cpp"
#include "bulk_quote.cpp"
#include "limit_quote.cpp"
#include "basket.cpp"

int main()
{
	Basket bask;

	for(int i = 0; i < 10; ++i)
		//bask.add_item(make_shared<Quote>("DB", 5));
		bask.add_item(Quote("DB", 5));
	for( int i = 0; i < 10; ++i) 
		//bask.add_item(make_shared<Bulk_quote>("OS", 20, 10, 0.5));
		bask.add_item(Bulk_quote("OS", 20, 10, 0.5));
	bask.total_receipt(cout);

	/*
	vector<Quote*> vq;
	Quote quo("DB", 5);
	Bulk_quote bul("OS", 20, 10, 0.5);

	//vq.push_back(make_shared<Quote>("DB", 5));
	//vq.push_back(make_shared<Bulk_Quote>("OS", 20, 10, 0.5));
	vq.push_back(&quo);
	vq.push_back(&bul);
	
	int sum = 0;
	for(auto a : vq)
		sum += a->net_price(10);
	cout << "sum = " << sum << endl;
	*/
	
	return 0;
}
