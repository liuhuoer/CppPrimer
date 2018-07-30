#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using std::cout;using std::endl;using std::vector;using std::list;using std::unique_copy;

int main()
{
	vector<int> vi{1,2,3,4,5,5,6};
	list<int> li;
	unique_copy(vi.begin(),vi.end(),back_inserter(li));
	for(auto a:li)
		cout<<a<<endl;

	return 0;
}
