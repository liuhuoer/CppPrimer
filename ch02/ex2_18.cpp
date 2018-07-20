#include <iostream>

int main()
{
	int a=1,b=2;
	int *p1=&a;
	//change the value of a pointer;
	p1=&b;
	std::cout<<*p1<<std::endl;
	//change the value of the object which the pointer point to
	*p1=3;
	std::cout<<*p1<<std::endl;
	return 0;
}
