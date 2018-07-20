#include <iostream>
#include <sstream>
#include <string>

using std::istream;
using std::cin;
using std::cout;
using std::endl;
using std::istringstream;
using std::string;

void func(istream & is)
{
	string buf;
	while(is>>buf)
		cout<<buf<<endl;
	is.clear();
}

int main()
{
	istringstream iss("I love you !");
	func(iss);
	return 0;
}
