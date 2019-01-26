#include <iostream>

class Test
{
public:
	Test()
	{ std::cout << "Test()" << std::endl;}
	void t()
	{ std::cout << "t()" << std::endl;}
	int i;
};

int main()
{
	Test * tes;
	tes->t();
	return 0;
}
