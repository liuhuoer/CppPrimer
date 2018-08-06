#include <iostream>
#include <memory>

int main()
{
	auto sp=std::make_shared<int>();
	auto p=sp.get();
	//sp will become dangling pointer;
	delete p;
	
	return 0;
}
