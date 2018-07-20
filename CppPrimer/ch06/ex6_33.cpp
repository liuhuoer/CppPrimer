#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using iter=vector<int>::const_iterator;

void get_value(iter begin,iter end)
{
	if(begin!=end)
	{
		cout<<*begin++<<" ";
		get_value(begin,end);
	}
}

int main()
{
	vector<int> vi={1,2,3};
	get_value(vi.cbegin(),vi.cend());
	return 0;
}
