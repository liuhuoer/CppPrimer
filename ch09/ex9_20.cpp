#include <iostream> 
#include <list>
#include <deque>

using std::cout;using std::endl;using std::list;using std::deque;

int main()
{
	list<int> li={1,2,3,4,5,6};
	deque<int> di1,di2;

	for(auto i:li)
		i%2!=0?di1.push_back(i):di2.push_back(i);

	for(auto i:di1)
		cout<<i;
	cout<<endl;

	for(auto i:di2)
		cout<<i;
	cout<<endl;
	
	return 0;
}
