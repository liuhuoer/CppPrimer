#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cin;using std::cout;using std::endl;using std::vector;using std::string;

int main()
{
	vector<string> vs;
	//input a word;
	for(string word;cout<<"input word:",cin>>word&&word!="!q";)
		if(find(vs.begin(),vs.end(),word)==vs.end())
			//check is_repetition, if no then input;
			vs.push_back(word);
		else
			continue;
	
	for(const auto & a:vs)
		cout<<a<<endl;
	cout<<endl;
	return 0;
}
