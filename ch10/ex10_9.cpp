#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using std::cout;using std::endl;using std::vector;using std::string;using std::ifstream;using std::sort;

void myprint(const string & s,vector<string> & vs)
{
	cout<<s<<"(size="<<vs.size()<<")"<<endl;
	for(auto a:vs)
		cout<<a<<" ";
	cout<<endl;
	cout<<vs.back()<<endl;
}

void elimDups(vector<string> & vs)
{
	myprint("original: ",vs);
	sort(vs.begin(),vs.end());
	myprint("sort: ",vs);
	auto end_unique=unique(vs.begin(),vs.end());
	myprint("unique: ",vs);
	vs.erase(end_unique,vs.end());
	myprint("erase: ",vs);
}

int main()
{
	ifstream ifs("../data/unique.txt");
	vector<string> vs;
	string s;

	if(!ifs)
		return -1;
	while(ifs>>s)
		vs.push_back(s);
	elimDups(vs);

	return 0;
}
