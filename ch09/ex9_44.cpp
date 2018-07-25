#include <iostream>
#include <string>

using std::cout;using std::endl;using std::string;

void find_replace(string & s,const string & old_val,const string & new_val)
{
	for(size_t i=0;i<=s.size()-old_val.size();)		//rewrite_1:chang int to size_t
	{
		if(old_val==s.substr(i,old_val.size()))		//rewrite_2:string(s,i,old_val.size()) => s.substr(i,old_val.size()) 
		{
			s.replace(i,old_val.size(),new_val);
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
