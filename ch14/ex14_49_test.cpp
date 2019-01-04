#include "ex14_49.cpp"

int main()
{
	Book book1(201801, "PP", "liu", "2018", 3);
	Book&& book2 = std::move(book1);
	Book book3 = book1;

	std::cout << book2 << std::endl;
	std::cout << book3 << std::endl;
	std::cout << static_cast<bool>(book1) << std::endl;
	
	return 0;
}
