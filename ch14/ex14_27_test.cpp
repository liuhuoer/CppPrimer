#include "ex14_27.cpp"

int main()
{
	StrBlob s1 = {"hello ", "eason"};
	for(StrBlobPtr begin = s1.begin(); begin < s1.end(); ++begin)
		std::cout << begin.deref();
	std::cout << std::endl;

	return 0;
}
