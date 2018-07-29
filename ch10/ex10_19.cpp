#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using std::cout;using std::endl;using std::vector;using std::string;using std::stable_sort;using std::ifstream;

void elimDups(vector<string> & vs)
{
	sort(vs.begin(),vs.end());
	auto end_unique=unique(vs.begin(),vs.end());
	vs.erase(end_unique,vs.end());
}

string make_plural(int count,const string & word,const string & s)
{
	return (count>1)?word+s:word;	
}

void biggies(vector<string> & vs,int sz)
{
	//lexicographical order;
	elimDups(vs);
	//size order;
	stable_sort(vs.begin(),vs.end(),[](const string & s1,const string & s2){return s1.size()<s2.size();});
	//find the first position that size is big enough;
	auto wc=stable_partition(vs.begin(),vs.end(),[sz](const string & s){return s.size()<sz;});
	//calculate the nums of these string;
	auto count=vs.end()-wc;
	//print;
	cout<<"there are "<<count<<" "<<make_plural(count,"word","s")<<" of length "<<sz<<" or longer."<<endl;
	for_each(wc,vs.end(),[](const string & s){cout<<s<<" "<<endl;});
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

	biggies(vs,5);

	return 0;
}
