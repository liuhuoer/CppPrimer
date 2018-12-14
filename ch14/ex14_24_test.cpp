#include "ex14_24.cpp"

int main()
{
	Book book1(201801, "PP", "liu", "2018", 3);
	Book&& book2 = std::move(book1);
	Book book3 = book1;

	std::cout << book2 << std::endl;
	std::cout << book3 << std::endl;
	
	return 0;
}
