#include <iostream>

using std::cout;
using std::endl;

int compare(int x1,int * x2)
{
	if(x1>*x2)
		return x1;
	else
		return *x2;
}

int main()
{
	int x1=1,x2=2;
	cout<<compare(x1,&x2)<<endl;
	return 0;
}
