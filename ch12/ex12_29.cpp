#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <sstream>

using std::cin;using std::cout;using std::endl;using std::vector;using std::string;using std::map;using std::set;using std::ifstream;using std::istringstream;using std::size_t;

int main()
{
	//deal input file and init map;
	ifstream ifs("../data/text_query.txt");
	vector<string> v_line;
	map<string,set<size_t>> word_line;
	size_t num=0;//line number;
	for(string line;std::getline(ifs,line);++num)
	{
		v_line.push_back(line);
		istringstream is(line);
		for(string word;is>>word;)
		{
			set<size_t> ss={num};
			auto succ=word_line.insert({word,ss});
			if(!succ.second)
				(succ.first->second).insert(num);
		}
	}
	//query word;
	string word;
	do
	{
		cout<<"Please input a word to query."<<endl;
		if(!(cin>>word)||word=="!q")
			break;
		auto curr=word_line.find(word);
		if(curr==word_line.end())
		{
			cout<<"Not find."<<endl;
			continue;
		}
		auto s_iter=(curr->second).begin();
		for(;s_iter!=(curr->second).end();++s_iter)
		{
			cout<<"(line "<<*s_iter+1<<") "<<v_line[*s_iter]<<endl;
		}
	}while(true);//rewrite_:add";"
	//output line number;
	return 0;
}
