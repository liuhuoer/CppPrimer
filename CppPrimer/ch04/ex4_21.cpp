#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> vi{1,2,3,4,5};
	for(auto &x:vi)
		cout<<((x&0x1)?(2*x):x)<<" ";
	cout<<endl;
	return 0;
}

