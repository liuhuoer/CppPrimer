#include <iostream>

using std::cout;
using std::endl;

int reset(int & x)
{
	return x=0;
}

int main()
{
	int x=8;
	cout<<reset(x)<<endl;
	return 0;
}
