#include <iostream>

using std::cout;
using std::endl;

void exchange(int *& x1,int *& x2)
{
	auto t=x1;
	x1=x2;
	x2=t;
}

int main()
{
	int x1=1,x2=2;
	auto * px1=&x1,* px2=&x2;
	exchange(px1,px2);//there is a function about exchange two pointer;
	cout<<*px1<<" "<<*px2<<endl;
	return 0;
}
