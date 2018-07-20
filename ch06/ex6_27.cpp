#include <iostream>
#include <initializer_list>

using std::cout;
using std::endl;
using std::initializer_list;

int get_sum(const initializer_list<int> & il)
{
	int sum=0;
	for(auto x:il)
		sum+=x;
	return sum;
}

int main()
{
	auto il={1,2,3};
	cout<<get_sum(il)<<endl;
	return 0;
}
