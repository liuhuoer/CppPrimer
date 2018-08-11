#ifndef ex12_32_h
#define ex12_32_h

#include "ex12_22.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <memory>
#include <fstream>

using std::ostream;using std::size_t;using std::cin;using std::cout;using std::endl;using std::string;using std::vector;using std::map;using std::set;using std::istringstream;using std::shared_ptr;using std::ifstream;using line_no=StrBlob::size_type;

class QueryResult;

class TextQuery
{
public:
	TextQuery(ifstream & ifs);
	QueryResult query(const string &) const;
private:
	//StrBlob file;
	shared_ptr<StrBlob> file;
	map<string,shared_ptr<set<line_no>>> wm;
};

class QueryResult
{
friend ostream & print(ostream &,const QueryResult &);
public:
	QueryResult(string s,shared_ptr<set<line_no>> ss,shared_ptr<StrBlob> sv):word(s),lines(ss),file(sv){ }
private:
	string word;
	shared_ptr<set<line_no>> lines;
	shared_ptr<StrBlob> file;
};

#endif
