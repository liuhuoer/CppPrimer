#include <iostream>
#include <vector>
#include <list>

using std::cout;using std::endl;using std::vector;using std::list;

int main()
{
	int ia[]={0,1,1,2,3,5,8,13,21,55,89};
	vector<int> vi;
	list<int> li;

	for(auto i:ia)
	{
		vi.push_back(i);
		li.push_back(i);
	}

	auto it=vi.begin();
	while(it!=vi.end())
	{
		if(!(*it%2))
			vi.erase(it);
	}

	auto it2=li.begin();
	while(it2!=li.end())
	{
		if(*it2%2)
			li.erase(it2);
	}

	for(auto i:vi)
		cout<<i;
	cout<<endl;

	for(auto i:li)
		cout<<i;
	cout<<endl;

	return 0;
}
