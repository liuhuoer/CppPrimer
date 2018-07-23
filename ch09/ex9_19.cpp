#include <iostream>
#include <list>

using std::cin;using std::cout;using std::endl;using std::list;using std::string;

int main()
{
	string word;
	list<string> ds; 
	
	while(cin>>word)
		ds.push_back(word);
	
	for(auto i:ds)
		cout<<i;
	cout<<endl;

	for(auto ds_i=ds.begin();ds_i!=ds.end();++ds_i)
		cout<<*ds_i;
	cout<<endl;

	return 0;
}
