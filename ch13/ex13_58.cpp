#include "ex13_58.h"
#include <algorithm>
using std::sort;

Foo Foo::sorted()&&
{
	cout<<"&&"<<endl;
	sort(data.begin(),data.end());
	return *this;
}

Foo Foo::sorted()const &
{
	cout<<"const &"<<endl;
	//version_original:
	/*
	Foo ret(*this);
	sort(ret.data.begin(),ret.data.end());
	return ret;
	*/
	
	//version_ex13_56:
	/*
	Foo ret(*this);
	return ret.sorted();
	*/

	//version_ex13_57:
	return Foo(*this).sorted();
}

int main()
{
	//rewrite_:&& version Foo();
	Foo().sorted();	//&&

	Foo f1;
	f1.sorted();	//const &

	return 0;
}
