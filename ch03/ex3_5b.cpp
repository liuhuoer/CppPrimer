#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string sum;
	for(string str;cin>>str;)
		sum+=str+" ";
	cout<<sum<<endl;
	return 0;
}
