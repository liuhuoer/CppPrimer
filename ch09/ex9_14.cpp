#include <iostream>
#include <string>
#include <vector>
#include <list>

using std::cout;using std::endl;using std::vector;using std::list;using std::string;

int main()
{
	list<const char *> lcp={"I\0","want\0","you\0"};
	vector<string> vs;
	vs.assign(lcp.cbegin(),lcp.cend());

	for(auto i:lcp)
		cout<<i;
	cout<<endl;

	for(auto i:vs)
		cout<<i;
	cout<<endl;

	return 0;
}
