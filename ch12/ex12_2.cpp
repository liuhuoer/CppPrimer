#include "ex12_2.h"

int main()
{
	//const StrBlob cb{"test1","test2","test3"};
	StrBlob b{"hello"," ","world"};
	//cb.push_back("test4");
	b.push_back("!");
	cout<<b.front()<<b.back()<<endl;
	b.pop_back();
	cout<<b.back()<<endl;
	return 0;
}
