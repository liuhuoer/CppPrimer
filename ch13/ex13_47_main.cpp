#include "ex13_47.cpp"
#include <iostream>

using std::cout;using std::endl;

void print(const String& s)
{
	auto b=s.begin();
	for(int i=0;i<s.size();++b,++i)
		cout<<*b;
	cout<<endl;
}

int main()
{
	//=
	String s0;
	s0="Hello s0";
	print(s0);

	//S S(const S&)
	String s1("Hello s1");
	print(s1);

	return 0;
}
