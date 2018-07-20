//this program is so bad, you can see another,ex3_24.cpp
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
	int i;
	vector<int> vi;
	while(cin>>i)
	{
		//add to vector
		vi.push_back(i);
	}
	//first add next
	cout<<"the first version"<<endl;
	for(decltype(vi.size()) i=0; i<vi.size(); i++, i++)
	{
		if(vi.size()==(i+1))
			cout<<"you just have the last number"<<vi[i]<<endl;
		else
			cout<<i+1<<"st number+"<<i+2<<"st number ="<<vi[i]+vi[i+1]<<endl;
	}
	//first add last
	cout<<"the second version"<<endl;
	for(decltype(vi.size()) i=0; i<(double)vi.size()/2; i++)
	{
		if(2*(i+1)>vi.size())
			cout<<"you just have the last number"<<vi[i]<<endl;
		else
			cout<<i+1<<"st number+"<<vi.size()-i<<"st number ="<<vi[i]+vi[vi.size()-1-i]<<endl;
	}
	return 0;
}
