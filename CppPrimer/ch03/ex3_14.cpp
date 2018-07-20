#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
	int i=0;
	vector<int> vi;
	while(cin>>i)
		vi.push_back(i);
	for(auto c:vi)
		cout<<c;
	return 0;
}
