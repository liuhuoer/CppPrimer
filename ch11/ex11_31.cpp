#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using std::cout;using std::endl;using std::multimap;using std::string;

void myprint(const multimap<string,string> & ms)
{
	for(auto a:ms)
		cout<<a.first<<" "<<a.second<<endl;
	cout<<endl;
}

int main()
{
	multimap<string,string> author_book{{"s","DB"},{"s","OS"},{"t","Math"},{"t","English"}};

	cout<<"origin:"<<endl;
	myprint(author_book);

	auto range=author_book.equal_range("s");
	author_book.erase(range.first,range.second);
	cout<<"erase:"<<endl;
	myprint(author_book);

	auto range_test=author_book.equal_range("k");
	author_book.erase(range_test.first,range_test.second);
	cout<<"erase:(test)"<<endl;
	myprint(author_book);
	
	return 0;
}
