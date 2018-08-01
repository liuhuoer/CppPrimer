#include <iostream>
#include <map> 
#include <set> 
#include <string>
#include <fstream>
#include <iterator>

using std::cout;using std::endl;using std::map;using std::set;using std::string;using std::ifstream;using std::istream_iterator;

int main(int argc,char **argv)
{
	//init map and set;
	map<string,size_t> ms;
	set<string> ss{"the","a","an","I","you","and","but"};
	//input words to iterator;
	if(argc!=2)
		return -1;
	ifstream ifs(argv[1]);
	istream_iterator<string> i_iter(ifs),eof;
	//count the number of words;
	for(;i_iter!=eof;++i_iter)
	{
		//remove some special words;
		if(ss.find(*i_iter)==ss.end())
		{
			++ms[*i_iter];
		}
	}
	//output the result;
	for(auto a:ms)
		cout<<a.first<<" occurs "<<a.second<<(a.second>1?"times":"time")<<endl;

	return 0;
}
