#include <iostream>
#include <string>
#include <string.h>

using std::cout;using std::endl;using std::string;

int main()
{
	//concatenate char[];
	//rewrite_:strlen("hello ""world")-2;
	char* cat_str=new char[strlen("hello ""world")-2]();
	//rewrite_:use char * strcat(char *dest,char *src);
	strcat(cat_str,"hello ");
	strcat(cat_str,"world");
	//rewrite_:directly use cat_str to output;
	cout<<cat_str<<endl;
	delete []cat_str;

	//concatenate string;
	string s1="hello ",s2="world";
	cout<<s1+s2<<endl;

	return 0;
}
