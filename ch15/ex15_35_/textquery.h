#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <memory>
#include <fstream>

#include "strblob.cpp"

using std::ostream;using std::istringstream;using std::ifstream;
using std::size_t;
using std::cin;using std::cout;using std::endl;
using std::string;using std::vector;using std::map;using std::set;
using std::shared_ptr;

class QueryResult;

class TextQuery
{
public:
	using line_no = StrBlob::size_type;

	TextQuery(ifstream & ifs);
	QueryResult query(const string &) const;
private:
	//StrBlob file;
	shared_ptr<StrBlob> file;
	map<string, shared_ptr<set<line_no>>> wm;
};

class QueryResult
{
//bug@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	friend ostream& print(ostream&, const QueryResult&);
public:
	QueryResult(string s, shared_ptr<set<TextQuery::line_no>> ss, shared_ptr<StrBlob> sv) 
		: word(s), lines(ss), file(sv)
	{ }
private:
	string word;
	shared_ptr<set<TextQuery::line_no>> lines;
	shared_ptr<StrBlob> file;
};

ostream& print(ostream&, const QueryResult&);

#endif
