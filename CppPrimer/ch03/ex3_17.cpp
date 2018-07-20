#include <iostream>
#include <vector>
#include <string>
#include <cctype>

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
	{
		//to upper
		for(auto &c:i)
			c=toupper(c);
		//add to vector
		vi.push_back(i);
	}
	//print
	for(auto c:vi)
		cout<<c<<endl;
	return 0;
}
