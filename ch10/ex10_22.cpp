#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <functional>

using namespace std::placeholders;using std::cout;using std::endl;using std::vector;using std::string;using std::ifstream;

bool judge_size(const string & s,int sz)
{
	return s.size()<sz;
}

void biggies(vector<string> & vs,int sz)
{
	//calculate the nums of these word; 
	auto count=count_if(vs.begin(),vs.end(),bind(judge_size,_1,sz));
	auto word_s=[count](const string & word,const string & s){return (count>1)?word+s:word;};

	//print;
	cout<<"there are "<<count<<" "<<word_s("word","s")<<" of length "<<sz-1<<" or shorter."<<endl;
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

	biggies(vs,6);

	return 0;
}
