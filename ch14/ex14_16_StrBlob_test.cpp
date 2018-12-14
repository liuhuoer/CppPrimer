#include "ex14_16_StrBlob.cpp"

int main()
{
	StrBlob sb = {"I ", "like ", "this", "world"};
	for(auto begin = sb.begin(); begin != sb.end(); begin.incr())
		std::cout<<begin.deref()<<std::endl;
	
	return 0;
}
