#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <map>  
#include <sstream>
#include <stdexcept>

using std::cin;using std::cout;using std::endl;using std::unordered_map;using std::string;using std::ifstream;using std::map;using std::istringstream;using std::runtime_error;

auto wordCount()
{
	unordered_map<string,size_t> word_count;
	for(string word;cin>>word&&word!="!q";)
		++word_count[word];
	for(const auto & a:word_count)
		cout<<a.first<<" occurs "<<a.second<<(a.second>1?" words.":" word.")<<endl;
}

auto wordTrans()
{
	//init 2 ifstream;
	ifstream rule("../data/rule.txt"),content("../data/content.txt");
	//get map from ifstream;
	map<string,string> trans_map;
	for(string key,word;rule>>key&&getline(rule,word);)
		if(word.size()>1)
			trans_map[key]=word.substr(1);
		else
			throw runtime_error("no this key:"+key);
	//transformation;
	//get line from ifstream;
	for(string line;getline(content,line);cout<<endl)
	{
		//get word from line(istringstream);
		istringstream s_stream(line);
		bool first_word=true;
		for(string word;s_stream>>word;)
		{
			//transformation word;
			if(first_word)
				first_word=false;
			else
				cout<<" ";
			if(trans_map.find(word)!=trans_map.end())
				cout<<trans_map[word];
			else
				cout<<word;
		}
	}
}

int main()
{
	//wordCount();
	wordTrans();
	return 0;
}
