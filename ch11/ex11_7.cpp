#include <iostream>
#include <map>
#include <vector>
#include <string>

using std::cin;using std::cout;using std::endl;using std::map;using std::vector;using std::string;using family=map<string,vector<string>>;

auto add_families()							//rewrite_:return auto;
{
	family f;
	//add families
	for(string in;cout<<"last name:",cin>>in&&in!="!q";)		//rewrite_:condition is used to output and input;
		//add children
		for(string in_2;cout<<"first name:",cin>>in_2&&in_2!="!q";)
			f[in].push_back(in_2);				//rewrite_:format about inputing data to map
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
			cout<<"first name:"<<s<<endl;
		cout<<endl;
	}
}

int main()
{
	myprint(add_families());

	return 0;
}
