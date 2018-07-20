#include <iostream>

using std::cin;
using std::cout;
using std::endl;

unsigned int abs_(int x)
{
	unsigned result=0;
	if(x<0)
		result=-x;
	else
		result=x;
	return result;
}

int main()
{
	int x;
	cin>>x;
	cout<<abs_(x)<<endl;
	return 0;
}
