#include "ex14_28.cpp"

int main()
{
	StrBlob s1 = {"hello ", "eason"};
	(s1.begin() + 1).deref() = "world";
	std::cout << (s1.begin() + 1).deref() << std::endl;
	for(auto begin = s1.begin(); begin < s1.end(); begin = begin + 1) 
		std::cout << begin.deref() << std::endl;

	return 0;
}
