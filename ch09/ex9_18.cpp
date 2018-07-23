#include <iostream>
#include <deque>

using std::cin;using std::cout;using std::endl;using std::deque;using std::string;

int main()
{
	string word;
	deque<string> ds; 
	
	while(cin>>word)
		ds.push_back(word);
	
	for(auto i:ds)
		cout<<i;
	cout<<endl;

	return 0;
}
