#include <iostream>

using std::cout;
using std::endl;

int exchange(int *p1,int *p2)
{
	int t=0;
	t=*p1;
	*p1=*p2;
	*p2=t;
	return 0;
}

int main()
{
	int x1=1,x2=2;
	exchange(&x1,&x2);
	cout<<x1<<" "<<x2<<endl;
	return 0;
}
