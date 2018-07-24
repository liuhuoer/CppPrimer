#include <iostream>
#include <forward_list> 
#include <string>

using std::cout;using std::endl;using std::forward_list;using std::string;

void judge_insert(forward_list<string> & fls,string s1,string s2)
{
	auto pre=fls.before_begin();  
	for(auto i=fls.begin();i!=fls.end();pre=i++)
	{
		if(*i==s1)
		{
			fls.insert_after(i,s2);
			return;
		}
	}
	fls.insert_after(pre,s2);
}

int main()
{
	forward_list<string> fls={"I want you","I hate you"}; 
	string s1="I want you";
	string s2="!!";
	
	judge_insert(fls,s1,s2);

	for(auto i:fls)
		cout<<i;
	cout<<endl;

	return 0;
}
