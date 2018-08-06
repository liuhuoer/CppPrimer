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
	//copy si to the parameter s,so si.use_count+1;
	//process(si);
	//but below not occur copying,just use this temporary variable;
	process(Spi(si));
	cout<<"main1():"<<si.use_count()<<endl;

	return 0;
}
