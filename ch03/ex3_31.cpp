#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int iarray[10];
	for(size_t x=0; x<10; ++x)
	{
		iarray[x]=x;
		cout<<iarray[x];
	}
	cout<<endl;
	return 0;
}
