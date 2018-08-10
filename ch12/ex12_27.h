#ifndef ex12_27_h
#define ex12_27_h

#include <iostream>
#include <string>
#include <vector>
#include <map> 
#include <set>
#include <fstream>
#include <sstream>
#include <memory>

using std::cout;using std::endl;using std::string;using std::vector;using std::map;using std::set;using std::ifstream;using std::istringstream;using std::shared_ptr;using std::size_t;
/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
class TextQuery
{
public:
	//init v_line and word_number;
	TextQuery(ifstream & ifs);
	//get one word's word_number;
	shared_ptr<map<size_t,string>> query(string & s);
private:
	vector<string> v_line;
	//all words's line_numbers;
	map<string,set<size_t>> word_number;
};
/**/
TextQuery::TextQuery(ifstream & ifs)
{
	size_t line_num=0;
	for(string s_line;std::getline(ifs,s_line);++line_num)
	{
		set<size_t> ss={line_num};
		istringstream is(s_line);
		//init v_line;
		v_line.push_back(s_line);
		for(string word;is>>word;)
		{
			//init word_number;
			auto curr=word_number.insert(std::make_pair(word,ss));
			//check word repeatedly insert;
			if(!curr.second)
				(curr.first->second).insert(line_num);
		}
	}
}
/**/
shared_ptr<map<size_t,string>> TextQuery::query(string & s)
{
	//shared_ptr(line_number,line);
	shared_ptr<map<size_t,string>> sp_result=std::make_shared<map<size_t,string>>();
	//copy set<size_t> in word_number to shared_ptr;
	auto curr=word_number.find(s);
	if(curr==word_number.end())
		return 0;
	auto set_it=(curr->second).begin();
	for(;set_it!=(curr->second).end();++set_it)
	{
		//*set_it is line_number;
		sp_result->insert(std::make_pair(*set_it,v_line[*set_it]));
	}
	return sp_result;
}

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
class QueryResult
{
public:
	QueryResult(shared_ptr<map<size_t,string>> sp_result):result(sp_result){ };
	std::ostream & print(std::ostream & out);
private:
	shared_ptr<map<size_t,string>> result;
	//
};

/**/
std::ostream & QueryResult::print(std::ostream & out)
{
	for(auto map_it=result->begin();map_it!=result->end();++map_it)
	{
		out<<"(line "<<(map_it->first)+1<<") "<<map_it->second<<endl;
	}

	return out;
}
#endif
