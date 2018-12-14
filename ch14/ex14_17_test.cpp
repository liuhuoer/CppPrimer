#include "ex14_17.cpp"

int main()
{
	Book book1(201801, "PP", "liu", "2018", 3);
	Book book2(201801, "PP", "liu", "2018", 2);

	std::cout << book1 + book2 << std::endl;
	
	return 0;
}
