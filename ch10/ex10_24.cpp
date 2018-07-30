#include <iostream>
#include <string>
#include <vector>
#include <functional> 
#include <algorithm> 

using std::cout;using std::endl;using std::string;using std::vector;using namespace std::placeholders;

bool check_size(int i,string::size_type si)
{
	return (i>si)?true:false;
}

int main() 
{
	vector<int> vi={1,2,8,9,10,11,22,33,32};
	string s="C++ Primer";
	auto i=find_if(vi.begin(),vi.end(),bind(check_size,_1,s.size()));
	cout<<*i<<endl;
	return 0;
}
