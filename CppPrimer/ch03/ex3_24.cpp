#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> vi;
	for(int i; cin>>i; vi.push_back(i));

	for(auto it=vi.cbegin(); it!=vi.cend() ;++it)
		cout<<*it+*(it+1)<<" ";
	cout<<endl;

	for(auto fit=vi.cbegin(), lit=vi.cend()-1; fit<=lit; ++fit, --lit)
		cout<<*fit+*lit<<" ";
	cout<<endl;
	return 0;
}
