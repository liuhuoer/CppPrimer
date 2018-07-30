#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using std::list;using std::cout;using std::endl;using std::vector;using std::copy;using std::for_each;

int main()
{
	vector<int> vi{1,2,3,4,5};
	list<int> li1,li2,li3;
	copy(vi.begin(),vi.end(),back_inserter(li1));
	copy(vi.begin(),vi.end(),front_inserter(li2));
	copy(vi.begin(),vi.end(),inserter(li3,li3.end()));

	cout<<"li1:"<<endl;
	for_each(vi.begin(),vi.end(),[](int i){cout<<i<<endl;});
	cout<<"li2:"<<endl;
	for(auto a:li2)
		cout<<a<<endl;
	cout<<"li3:"<<endl;
	for(auto a:li3)
		cout<<a<<endl;

	return 0;
}
