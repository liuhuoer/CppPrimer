#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;using std::cout;using std::endl;using std::vector;using std::count;
int main()
{
	vector<int> vi;
	int t;
	while(cin>>t)
		vi.push_back(t);
	cout<<count(vi.cbegin(),vi.cend(),6)<<endl;	//rewrite_1:use cbegin() replace begin()

	return 0;
}
