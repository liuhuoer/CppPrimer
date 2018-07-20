#include <iostream>

using std::cout;
using std::endl;

int eve_num(int x)
{
	x=(x%2!=0)?0:x;
	static int sum=0;
	return sum+=x;
}

int main()
{
	for(int x=0;x<10;++x)
		cout<<"The sum ofeven number:"<<eve_num(x)<<endl;
	return 0;
}
