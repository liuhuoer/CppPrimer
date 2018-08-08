#include <iostream>

using std::cin;using std::cout;using std::endl;

int main()
{
	int size;
	cin>>size;
	char *p=new char[size+1]();
	//rewrite_:use cin.ignore;
	cin.ignore();
	//rewrite_:use cin.get();
	cin.get(p,size+1);
	cout<<p;
	delete [] p;
	short i=(0x7FFF+1);
	cout<<i<<endl;

	return 0;
}
