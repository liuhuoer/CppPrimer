#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int x=2,y=2;
	//the first version
	//!(y-x)?++x,++y:--x,--y;
	//the second version
	(y-x)?++x,++y:--x,--y;
	//the second version
	cout<<x<<y<<endl;
	return 0;
}
//the first version x=3,y=2
//the second version x=1,y=1
