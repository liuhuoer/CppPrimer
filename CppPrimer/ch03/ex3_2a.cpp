#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

int main()
{
	for (string str;getline(cin,str);cout<<str<<endl);
	return 0;
}
