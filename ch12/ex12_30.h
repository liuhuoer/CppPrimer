#ifndef ex12_30_h
#define ex12_30_h

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <memory>
#include <fstream>

using std::ostream;using std::size_t;using std::cin;using std::cout;using std::endl;using std::string;using std::vector;using std::map;using std::set;using std::istringstream;using std::shared_ptr;using std::ifstream;using line_no=vector<string>::size_type;

class QueryResult;

class TextQuery
{
public:
	TextQuery(ifstream & ifs);
	QueryResult query(const string &) const;
private:
	shared_ptr<vector<string>> file;
	map<string,shared_ptr<set<line_no>>> wm;
};

class QueryResult
{
friend ostream & print(ostream &,const QueryResult &);
public:
	QueryResult(string s,shared_ptr<set<line_no>> ss,shared_ptr<vector<string>> sv):word(s),lines(ss),file(sv){ }
private:
	string word;
	shared_ptr<set<line_no>> lines;
	shared_ptr<vector<string>> file;
};

#endif
