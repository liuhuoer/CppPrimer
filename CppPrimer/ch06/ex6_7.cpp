#include <iostream>

using std::cout;
using std::endl;

int cout_()
{
	static int c=0;
	return c++;
}

int main()
{
	for(int x=0;x<5;++x)
		cout<<cout_()<<endl;
	return 0;
}
