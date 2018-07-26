#include <iostream>
#include <vector>

using std::cout;using std::endl;using std::vector;

int main()
{
	vector<int> vi(10,6);
	fill_n(vi.begin(),10,0);
	for(auto i:vi)
		cout<<i<<" ";
	cout<<endl;
	
	return 0;
}
