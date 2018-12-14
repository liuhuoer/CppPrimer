#include "ex14_26_StrVec.cpp"

int main()
{
	StrVec sv1 = {"I ", "like ", "this ", "world."};
	for(auto begin = sv1.begin(); begin != sv1.end(); ++begin)
		std::cout << *begin; 
	std::cout << std::endl; 
	
	std::cout << sv1[1] << std::endl;

	return 0;
}
