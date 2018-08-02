#include <iostream>
#include <map> 
#include <set> 
#include <string>
#include <fstream>
#include <iterator>
#include <cctype>
#include <algorithm>

using std::cout;using std::endl;using std::map;using std::set;using std::string;using std::ifstream;using std::istream_iterator;

int main(int argc,char **argv)
{
	//init map and set;
	map<string,size_t> ms;
	set<string> ss{"the","a","an","I","you","and","but"};
	//init istream_iterator;
	if(argc!=2)
		return -1;
	ifstream ifs(argv[1]);
	istream_iterator<string> i_iter(ifs),eof;

	//input to map and count the number of words;
	for(string word;i_iter!=eof;++i_iter)
	{
		word=*i_iter;
		//remove punct;
		word.erase(remove_if(word.begin(),word.end(),ispunct),word.end());
		//remove some special words;
		if(ss.find(word)==ss.end())
		{
			//tolower;
			for(auto & a:word)
			{
				tolower(a);
			}
			//ex11_20 :insert the word;
			auto curr=ms.insert({word,1});
			if(!curr.second)
				++curr.first->second;
		}
	}

	//output the result;
	for(auto a:ms)
		cout<<a.first<<" occurs "<<a.second<<(a.second>1?"times":"time")<<endl;

	return 0;
}
