#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> vi={1,2,3,4,5};
	int a[5];
	for(int i=0;i<vi.size();++i)
		a[i]=vi[i];
	for(auto x:a)
		cout<<x;
	cout<<endl;
	return 0;
}

