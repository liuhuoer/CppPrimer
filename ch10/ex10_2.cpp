#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using std::cin;using std::cout;using std::endl;using std::list;using std::count;using std::string;

int main()
{
	list<string> li;
	string t;

	while(cin>>t)
		li.push_back(t);
	cout<<count(li.cbegin(),li.cend(),"I")<<endl;

	return 0;
}
