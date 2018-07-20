#include <iostream>
#include <vector>

using std::vector;
int test(int x,int y);

using pf1=decltype(test)*;
using pf2=int(*)(int a,int b);
typedef decltype(test) *pf3;
typedef int(*pf4)(int a,int b);

int main()
{
	vector<decltype(test)*> vf;
	vector<pf1> vf1;
	vector<pf2> vf2;
	vector<pf3> vf3;
	vector<pf4> vf4;
	return 0;
}
