#ifndef ex13_42_h
#define ex13_42_h

#include "ex13_42_StrVec.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <memory>
#include <fstream>

using std::ostream;using std::size_t;using std::cin;using std::cout;using std::endl;using std::string;using std::vector;using std::map;using std::set;using std::istringstream;using std::shared_ptr;using std::ifstream;

class QueryResult;

class TextQuery
{
public:
	TextQuery(ifstream & ifs);
	QueryResult query(const string &) const;
private:
	//vector<line_strings>
	shared_ptr<StrVec> file;
	//map<word, set<line_number>>
	map<string,shared_ptr<set<size_t>>> wm;
};

class QueryResult
{
friend	ostream & print(ostream &,const QueryResult &);
public:
	QueryResult(string s,shared_ptr<set<size_t>> ss,shared_ptr<StrVec> sv):word(s),lines(ss),file(sv){ }
private:
	string word;
	//set<line_number>
	shared_ptr<set<size_t>> lines;
	//vector<line_strings>
	shared_ptr<StrVec> file;
};

#endif
