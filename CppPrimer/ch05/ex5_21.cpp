#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string buf,pre;
	while(cin>>buf&&!buf.empty())
		if(buf==pre&&isupper(buf[0]))
		{
			cout<<buf<<" is same.";
			break;
		}
		else
			pre=buf;
	return 0;
}
