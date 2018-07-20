#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

int main()
{
	char c1[]="I love ";
	char c2[]="you";
	char c3[10];
	strcpy(c3,c1);
	strcat(c3,c2);
	for(auto x:c3)
		cout<<x;
	cout<<endl;
	return 0;
}
