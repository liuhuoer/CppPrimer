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
	for(char n=0;n<str.size();n++)
		str[n]='X';
//	for(char &c:str)
//		c='X';
	cout<<str<<endl;

	return 0;
}
