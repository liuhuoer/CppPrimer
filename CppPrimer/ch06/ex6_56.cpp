#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using pf=int(*)(int,int);

int add(int x,int y)
{
	return x+y;
}

int subtract(int x,int y)
{
	return x-y;
}

int multiply(int x,int y)
{
	return x*y;
}

int divide(int x,int y)
{
	return (y!=0)?x/y:-1;
}

int main()
{
	vector<pf> vf={add,subtract,multiply,divide};

	for(auto c:vf)
		cout<<c(2,3)<<endl;

	return 0;
}
