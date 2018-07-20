#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string str;
	cin>>str;
	decltype(str.size()) n;
	//first
	for(n=0;n<str.size();str[n++]='X');
	cout<<str<<endl;
	//second
	n=0;
	while(n<str.size())
		str[n++]='Y';
	cout<<str<<endl;

	return 0;
}
