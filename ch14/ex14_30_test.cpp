#include "ex14_30.cpp"

int main()
{
	StrBlob s1 = {"hello ", "eason"};
	ConstStrBlobPtr csp(s1);
	StrBlobPtr sp(s1);
	std::cout << *(s1.begin() + 1) << ", " << *s1.cbegin() << std::endl;
	std::cout << sp->size() << std::endl;
	std::cout << csp->size() << std::endl;

	return 0;
}
