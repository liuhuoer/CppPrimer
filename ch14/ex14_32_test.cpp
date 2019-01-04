#include "ex14_32.cpp"

int main()
{
	StrBlob sb = {"hello ", "world"};
	StrBlobPtr sbp(sb);
	StrBlobPtrPtr sbpp(sbp);
	std::cout << **sbpp << std::endl;
	return 0;
}
