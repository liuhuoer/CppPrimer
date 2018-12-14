#include "ex14_26_StrBlob.cpp"

int main()
{
	StrBlob s1 = {"hello ", "eason"};
	for(auto begin = s1.begin(); begin < s1.end(); begin.incr())
		std::cout << begin.deref();
	std::cout << std::endl;

	std::cout << s1[1];

	return 0;
}
