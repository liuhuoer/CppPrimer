#include <iostream>
#include <vector> 
#include <string> 
#include <fstream>
#include <algorithm>

using std::cout;using std::endl;using std::vector;using std::string;using std::partition;using std::ifstream;

bool compare_size(const string & s)
{
	if(s.size()>=5)
		return true;
	return  false;
}

int main()
{	
	string s;
	vector<string> vs;
	ifstream ifs("../data/unique.txt");
	if(!ifs)
		return -1;
	while(ifs>>s)
		vs.push_back(s);
	auto end_partition=partition(vs.begin(),vs.end(),compare_size);
	for(auto a:vs)
		cout<<a<<" ";
	cout<<endl;
	return 0;
}
