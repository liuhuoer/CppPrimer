#include "Chapter6.h"
#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

int fac(int x)
{
	if(x<0)
	{
		runtime_error err("Input cannot use a negative number.");
		cout<<err.what()<<endl;
		return -1;
	}
	return x>1?x*fac(x-1):1;
}
