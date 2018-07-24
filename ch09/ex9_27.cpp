#include <iostream>
#include <forward_list>

using std::cin;using std::cout;using std::endl;using std::forward_list;

void input_ints(auto & ints)
{
	int ii=0;
	auto prev=ints.before_begin();
	while(cin>>ii)
		prev=ints.insert_after(prev,ii);
}

void deal_ints(auto & ints)
{
	auto prev2=ints.before_begin();
	auto curr=ints.begin();
	while(curr!=ints.end())
		if(*curr&0x1)
			curr=ints.erase_after(prev2);
		else
		{
			prev2=curr;
			++curr;
		}
}

int main()
{
	forward_list<int> fli;
	
	input_ints(fli); 
	deal_ints(fli);
	
	for(auto i:fli)
		cout<<i;
	cout<<endl;

	return 0;
}
