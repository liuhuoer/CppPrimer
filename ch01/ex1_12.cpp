//Calculate the sum of all integers between -100 and 100.
#include <iostream>

int main()
{
	int sum = 0;
	for (int i = -100; i <= 100; ++i)
		sum += i;
	std::cout<<sum<<std::endl;
}

