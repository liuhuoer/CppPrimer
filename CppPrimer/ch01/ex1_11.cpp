//Print all integers between a and b.
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int sum(int a, int b)
{
	int t=0,sum=0;
	if(a>b)
	{
		t=a;
		a=b;
		b=t;
	}
	while(a<=b)
		cout<<a++<<endl;
}

int main()
{
	int a=0;
	int b=0;
	cin>>a>>b;
	sum(a,b);
}
