#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using std::cin;using std::cout;using std::endl;using std::vector;using std::list;using std::back_inserter;

int main()
{
	vector<int> vec;
	list<int> lst;
	int i;
	//a:
	while(cin>>i)
		lst.push_back(i);

	copy(lst.begin(),lst.end(),back_inserter(vec));		//fixed_1:change vec.begin() to back_inserter(vec).

	//b:	
	vector<int> vi;
	//vi.reserve(20);		//notice_1:this line make the capacity become 20, but only 10 2's is initialized.
	vi.resize(10);			//fixed_2:resize() can init vi with 0, but reserve() can't.
	cout<<"capacity="<<vi.capacity()<<endl;

	fill_n(vi.begin(),30,2);	//notice_2:anticipate init 11 2's, but the capacity of vi is 10, so only 10 2's is initialized; or chang vi.begin() to back_inserter(vi).
	cout<<"size="<<vi.size()<<" capacity2="<<vi.capacity()<<endl;

	for(auto a:vi)
		cout<<a<<" ";
	cout<<endl;

	return 0;
}
