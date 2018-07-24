#include <iostream>
#include <forward_list>

using std::cout;using std::endl;using std::forward_list;using std::advance;

void remove_even_double_odd(forward_list<int> & li)
{
	auto curr= li.begin(); 
	auto prev= li.before_begin();
	for(;curr!=li.end();)
		if(*curr&0x1)
		{
			curr=li.insert_after(prev,*curr);
			advance(curr,2);		//rewrite_1:use advance();
			advance(prev,2);
		}
		else
			curr=li.erase_after(prev);

}

int main()
{
	forward_list<int> li={0,1,2,3,4,5,6,7,8,9}; 
	remove_even_double_odd(li);
	for(auto i:li)
		cout<<i;
	cout<<endl;
	return 0;
}
