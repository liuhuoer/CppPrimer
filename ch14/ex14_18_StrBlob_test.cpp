#include "ex14_18_StrBlob.cpp"

int main()
{
	StrBlob s1 = {"hello ", "eason"};
	for(auto begin = s1.begin(); begin < s1.end(); begin.incr())
		std::cout << begin.deref();
	std::cout << std::endl;
	//for_each
	StrBlob s2 = {"hello ", "cc"};
	for(auto begin = s2.begin(); begin < s2.end(); begin.incr())
		std::cout << begin.deref();
	std::cout << std::endl;

	if(s1 > s2)
		std::cout << "s1 > s2" << std::endl;
	
	return 0;
}
