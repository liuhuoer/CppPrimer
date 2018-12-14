#include "ex14_18_StrVec.cpp"

int main()
{
	StrVec sv1 = {"I ", "like ", "this ", "world."};
	StrVec sv2 = {"I ", "like ", "your ", "world."};
	for(auto begin = sv1.begin(); begin != sv1.end(); ++begin)
		std::cout << *begin; 
	std::cout << std::endl; 
	for(const auto& result : sv2)
		std::cout << result;
	std::cout << std::endl; 
	if(sv1 < sv2)
		std::cout << "sv1 < sv2" << std::endl;

	return 0;
}
