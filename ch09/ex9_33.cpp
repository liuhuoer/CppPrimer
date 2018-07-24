#include <iostream>
#include <vector>
using std::cout;using std::endl;using std::vector;
void test(vector<int> & li)
{
	auto begin=li.begin();
	while(begin!=li.end())
	{
		++begin;
		li.insert(begin,42);
		++begin;
	}
}
int main()
{
	vector<int> li(10,1);
	test(li);
	for(auto i:li)
		cout<<i;
	cout<<endl;
	return 0;
}
