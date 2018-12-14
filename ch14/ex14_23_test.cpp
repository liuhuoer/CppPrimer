#include "ex14_23.cpp"

int main()
{
	StrVec sv1 = {"I ", "like ", "this ", "world."};
	for(auto begin = sv1.begin(); begin != sv1.end(); ++begin)
		std::cout << *begin; 
	std::cout << std::endl; 

	return 0;
}
