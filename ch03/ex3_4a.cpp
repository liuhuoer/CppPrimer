#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

int main()
{
	string str1,str2;
	cin>>str1>>str2;
	if(str1==str2)
	{
		cout<<"Their size is equal"<<endl;
	}
	else
	{
		if(str1>str2)
			cout<<str1<<">"<<str2<<endl;
		else
			cout<<str1<<"<"<<str2<<endl;
	}
	return 0;
}
