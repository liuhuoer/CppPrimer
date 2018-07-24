#include <iostream>
#include <list>

using std::cout;using std::endl;using std::list;using std::advance;

void remove_even_double_odd(list<int> & li)
{
	auto curr= li.begin(); 
	for(;curr!=li.end();)
		if(*curr&0x1)
		{
			curr=li.insert(curr,*curr);
			advance(curr,2);		//rewrite_1:use advance();
		}
		else
			curr=li.erase(curr);

}

int main()
{
	list<int> li={0,1,2,3,4,5,6,7,8,9}; 
	remove_even_double_odd(li);
	for(auto i:li)
		cout<<i;
	cout<<endl;
	return 0;
}
