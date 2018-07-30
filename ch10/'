#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using std::cout;using std::endl;using std::vector;using std::string;using std::stable_sort;using std::ifstream;

void biggies(vector<string> & vs,int sz)
{
	//calculate the word of size 6 or longer;
	auto count=count_if(vs.begin(),vs.end(),[sz](const string & s){return s.size()>sz;});
	auto word_s=[count](const string & word,const string & s){return (count>1)?word+s:word;};

	//print;
	cout<<"there are "<<count<<" "<<word_s("word","s")<<" of length "<<sz<<" or longer."<<endl;
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
