#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int fact(int x)
{
	int result=1;
	for(;x>0;--x)
		result*=x;
	return result;
}

int main()
{
	int n=0;
	cin>>n;
	cout<<fact(n)<<endl;
	return 0;
}


