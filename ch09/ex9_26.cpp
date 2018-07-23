#include <iostream>
#include <vector>
#include <list>

using std::cout;using std::endl;using std::vector;using std::list;

int main()
{
	int ia[]={0,1,1,2,3,5,8,13,21,55,89};
	vector<int> vi(ia,end(ia));		//rewrite_1
	list<int> li(ia.begin(),ia.end());	//rewrite_2

	auto it=vi.begin();
	while(it!=vi.end())
	{
		if(*it&0x1)			//rewrite_3(if it is real, *it is odd,else *it is even)
			it=vi.erase(it);	//err_1_ever
		else
			++it;			//err_2_ever
	}

	auto it2=li.begin();
	while(it2!=li.end())
	{
		if(!(*it2&0x1))
			it2=li.erase(it2);
		else
			++it2;
	}

	for(auto i:vi)
		cout<<i;
	cout<<endl;

	for(auto i:li)
		cout<<i;
	cout<<endl;

	return 0;
}
