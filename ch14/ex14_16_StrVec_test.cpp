#include "ex14_16_StrVec.cpp"

int main()
{
	StrVec sv1 = {"I ", "like ", "this ", "world."};
	StrVec sv2 = {"I ", "like ", "this ", "world."};
	for(auto begin = sv1.begin(); begin != sv1.end(); ++begin)
		std::cout << *begin << std::endl;
	for(const auto& result : sv2)
		std::cout << result << std::endl;
	if(sv1 == sv2)
		std::cout << "sv1 == sv2" << std::endl;

	return 0;
}
