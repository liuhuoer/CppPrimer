#include <iostream>
#include <string>
#include <cstring>

using std::cout;
using std::endl;
using std::string;

int main()
{
	const char c1[]="I love you";
	const char c2[]="I don't think so";
	if(strcmp(c1,c2))
		cout<<"c1 = c2"<<endl;
	else
		cout<<"c1 != c2"<<endl;
	string st1="I love you";
	string st2="I don't think so";
	if(st1==st2)
		cout<<"st1 = st2";
	else
		cout<<"st1 = st2";
	return 0;
}
