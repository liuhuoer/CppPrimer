#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <utility>

using std::cin;using std::cout;using std::endl;using std::map;using std::vector;using std::string;using std::pair;using family=map<string,vector<pair<string,string>>>;

auto add_families()				//rewrite_:return auto;
{
	family f;
	//add families
	for(string in;cout<<"last name:",cin>>in&&in!="!q";)	//rewrite_:condition is used to output and input;
		//add children;(conditon's cout with auto \n)
		for(string in_f_name,in_bir;cout<<"first name:",cin>>in_f_name&&in_f_name!="!q";)
		{
			cout<<"birthday:";
			cin>>in_bir;
			f[in].push_back({in_f_name,in_bir});	//rewrite_:format about inputing data to map
		}
	cout<<endl;
	return f;
}

//myprint
auto myprint(family f)
{
	for(auto a:f)				//rewrite_:use for(auto a:A) to iterate;
	{
		cout<<"last name:"<<a.first<<endl;
		for(auto s:a.second)
			cout<<"first name:"<<s.first<<"\nbirthday:"<<s.second<<endl;
		cout<<endl;
	}
}

int main()
{
	myprint(add_families());

	return 0;
}
