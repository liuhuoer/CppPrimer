#include <iostream>

int main()
{
	//ex1_9:
	std::cout <<"ex1_9"<< std::endl;
	int sum = 0;
	for (int i = 50; i <= 100; ++i)
		sum += i;
	std::cout << "the sum is: " << sum << std::endl;
	//ex1_10:
	std::cout <<"ex1_10"<< std::endl;
	sum = 0;
	for (int i = 10; i >= 0; --i)
		std::cout << i << std::endl;
	//ex1_11:
	std::cout <<"ex1_11"<< std::endl;
	sum = 0;
	std::cout << "please input two integers:\n";
	int small = 0, big = 0;
	std::cin >> small >> big;

	if (small > big)
	{
		int tmp = small;
		small = big;
		big = tmp;
	}

	for (int i = small; i != big; ++i)
		std::cout << i << std::endl;
	return 0;
}
