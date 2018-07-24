#include <iostream>
#include <vector>
using std::cout;using std::endl;using std::vector;
void test(vector<int> & li)
{
	auto begin=li.begin();
	while(begin!=li.end())
	{
		if(*begin&0x1)
			begin=li.insert(begin,*begin);
		++begin;
		if(li.size()>5)
			break;

	}
}
int main()
{
	vector<int> li={1,6};
	test(li);
	for(auto i:li)
		cout<<i;
	cout<<endl;
	return 0;
}
