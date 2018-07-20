#include <iostream>

using std::istream;
using std::cin;
using std::cout;
using std::endl;

istream & func(istream & is)
{
	std::string buf;
	while(is>>buf)
		cout<<buf<<endl;
	is.clear();
	return is;
}

int main()
{
	istream & is=func(cin);
	bool s=is.rdstate();
	cout<<"Result:"<<std::boolalpha<<s<<endl;
	return 0;
}
