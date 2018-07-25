#include <iostream>
#include <string>

using std::cout;using std::endl;using std::string;

void find_replace(string & s,const string & old_val,const string & new_val)
{
	for(auto i=s.begin();i<=s.end()-old_val.size();)
	{
		if(old_val==string(i,i+old_val.size()))		//rewrite_1:string(b,e)=> string s(b,e)
		{
			i=s.erase(i,i+old_val.size());
			i=s.insert(i,new_val.begin(),new_val.end());
			i+=new_val.size();
		}
		else
			++i;
	}
}

int main()
{
	string s="66though66thought66through66through66";
	find_replace(s,"though","tho");
	find_replace(s,"through","thru");
	cout<<s<<endl;

	return 0;
}
