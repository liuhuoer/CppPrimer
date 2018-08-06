#include <iostream>
#include <memory>

using std::cout;using std::endl;using std::shared_ptr;using Spi=shared_ptr<int>;

auto process(Spi s)
{
	cout<<"process():"<<s.use_count()<<endl;
}

int main()
{
	Spi si(new int(3));

	cout<<"main0():"<<si.use_count()<<endl;
	cout<<*si<<endl;
	/*s is not a copy of si,but they point to same address,
	 *so an error will generated("double free or corruption"). 
	 *and si can't be used.
	 */
	process(Spi(si.get()));
	cout<<"main1():"<<si.use_count()<<endl;
	cout<<*si<<endl;

	return 0;
}
