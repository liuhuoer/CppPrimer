#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string text="i love you";
	for(auto i=text.begin();i!=text.end();++i)
	{
		*i=toupper(*i);
		cout<<*i;
	}
	return 0;
}
