#include <iostream>
#include <vector>
using std::cout;using std::endl;using std::vector;
int main()
{
	vector<int> vi;
	cout<<vi.capacity()<<endl;
	vi.insert(vi.begin(),1048,6);
	cout<<vi.capacity()<<endl;
	vi.insert(vi.end(),1,3);
	cout<<vi.capacity()<<endl;
	return 0;
}
