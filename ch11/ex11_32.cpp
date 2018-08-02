#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>

using std::cout;using std::endl;using std::map;using std::multimap;using std::string;using std::vector;using std::multiset;

void myprint(const multimap<string,string> & ms)
{
	for(auto a:ms)
		cout<<a.first<<" "<<a.second<<endl;
	cout<<endl;
}

int main()
{
	multimap<string,string> author_book{{"s","DB"},{"s","OS"},{"t","Math"},{"t","English"}};
	map<string,vector<string>> order_a_b;	//rewrite_:change to map<string,multiset<string>>; and change push_back() to insert at later;
	
	//order;
	for(const auto & a:author_book)
		order_a_b[a.first].push_back(a.second);
	//output;
	for(const auto & a:order_a_b)
	{
		cout<<"author:"<<a.first<<endl;
		for(const auto & b:a.second)
			cout<<"book:"<<b<<endl;
		cout<<endl;
	}

	return 0;
}
