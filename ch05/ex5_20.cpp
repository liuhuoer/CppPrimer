#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
//	string str,pre;
//	while(cin>>str)
//		if(str==pre)
//			break;
//		else
//			pre=str;
//
//	if(cin.eof())
//		cout<<"There is no datas."<<endl;
//	else
//		cout<<str<<" is same."<<endl;
	string buf,pre;
	while(cin>>buf&&!buf.empty())
		if(buf==pre)
		{
			cout<<buf<<" is same.";
			break;
		}
		else
			pre=buf;
//	int sum=0,val=1;
//	cout<<endl,++val;
	return 0;
}
