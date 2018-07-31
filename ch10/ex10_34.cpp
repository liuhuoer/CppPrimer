#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using std::cout;using std::endl;using std::vector;using std::list;

int main()
{
	vector<int> vi{1,2,3,4,5};
	//ex10_34
	cout<<"ex10_34"<<endl;
	for(auto a=vi.crbegin();a!=vi.crend();++a)
		cout<<*a<<endl;
	//ex10_35
	cout<<"ex10_35"<<endl;
	for(auto a=vi.cend()-1;a!=vi.cbegin();--a)
		cout<<*a<<endl;
	cout<<*vi.begin()<<endl;
	//ex10_36
	cout<<"ex10_36"<<endl;
	list<int> li{1,2,3,4,0,5,0};
	auto value_0=find(li.crbegin(),li.crend(),0);
	cout<<distance(value_0,li.crbegin())<<endl;
	//ex10_37
	list<int> li_source{0,1,2,3,4,5,6,7,8,9};
	list<int> li_dest;
	copy(li_source.rbegin()+3,li_source.rbegin()+7,back_insert(li_dest));
	for(auto a:li_dest)
		cout<<a<<endl;

	return 0;
}
