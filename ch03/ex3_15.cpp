#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
	string i;
	vector<string> vi;
	while(cin>>i)
		vi.push_back(i);
	for(auto c:vi)
		cout<<c;
	return 0;
}
