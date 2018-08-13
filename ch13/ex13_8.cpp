#include "ex13_8.h"
#include <iostream>
#include <string>

using std::cout;using std::endl;using std::string;

int main()
{
	HasPtr hp1("test");
	HasPtr hp2;
	hp2=hp1;
	hp1.printOther(hp2);
	
	return 0;
}

