#include <iostream> 
#include <fstream>
#include <string>
#include <map>
#include <stdexcept>
#include <sstream>

using std::cout;using std::endl;using std::ifstream;using std::map;using std::string;using std::runtime_error;using std::istringstream;

map<string,string> build_map(ifstream & rule)	//rewrite_:cosnt ifstream can't use ">>";
{
	map<string,string> ms;
	string key;
	string word;
	//get key and word from ifstream;
	while(rule>>key&&getline(rule,word))
	{
		//delete blank ahead of word;
		if(word.size()>1)
			ms[key]=word.substr(1);
		else
			throw runtime_error("no rule for "+key);
	}

	return ms;
}

const string & transform(const string & word,const map<string,string> & ms)
{
	//check word belong to trans_map
	auto check=ms.find(word);

	if(check!=ms.end())
		return check->second;
		//rewrite_:return ms[word];
	else
		return word;
}

void word_transform(ifstream & rule,ifstream & content)
{
	//save rule data;
	auto trans_map=build_map(rule);
	//transform content;
	//get line from article;
	string line; 
	while(getline(content,line))		//rewrite_:no getline(istream &,string &), so content is't const ifstream &;
	{
		//get words from line;
		istringstream s_stream(line);	//rewrite_:using istringstream to get words;
		string word;
		bool first_word=true;		//rewrite_:words is partition with blank besides first one;
		while(s_stream>>word)
		{
			if(first_word)
				first_word=false;
			else
				cout<<" ";
			cout<<transform(word,trans_map);
		}
		cout<<endl;
	}
}

int main()
{
	ifstream rule("../data/rule.txt"),content("../data/content.txt");
	word_transform(rule,content);

	return 0;
}
