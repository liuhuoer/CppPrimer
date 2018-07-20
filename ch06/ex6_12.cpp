#include <iostream>

using std::cout;
using std::endl;

int exchange(int & x1,int & x2)
{
	int t;
	t=x1;
	x1=x2;
	x2=t;
	return 0;
}

int main()
{
	int x1=1,x2=2;
	exchange(x1,x2);
	cout<<x1<<" "<<x2<<endl;
	return 0;
}
