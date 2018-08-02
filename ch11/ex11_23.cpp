#include <iostream>
#include <map>
#include <string>

using std::cin;using std::cout;using std::endl;using std::multimap;using std::string;

int main()
{
	multimap<string,string> mms;
	for(string f_name,l_name;cin>>l_name&&l_name!="!q";)
	{
		cin>>f_name;
		mms.insert({l_name,f_name});
	}
	for(const auto & a:mms)
		cout<<a.second<<" "<<a.first<<endl;

	return 0;
}
