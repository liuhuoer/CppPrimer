#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

bool have_capital(const string & s)
{
	for(auto x:s)
	{
		if(isupper(x))
			return true;
		else
			return false;
	}
}

void to_lower(string & s)
{
	for(auto &x:s)
		x=tolower(x);
}

int main()
{
	string str="I love you!";
	cout<<"\""<<str<<"\" has capital ( "<<have_capital(str)<<" )"<<endl;
	to_lower(str);
	cout<<str<<endl;
	return 0;
}
