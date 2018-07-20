#include <iostream>
#include <vector>

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
	return x/y;
}

int main()
{
	vector<pf> vf;
	vf.push_back(add);
	vf.push_back(subtract);
	vf.push_back(multiply);
	vf.push_back(divide);
	return 0;
}
