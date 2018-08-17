#ifndef ex13_21_h
#define ex13_21_h

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <memory>
#include <fstream>

using std::ostream;using std::size_t;using std::cin;using std::cout;using std::endl;using std::string;using std::vector;using std::map;using std::set;using std::istringstream;using std::shared_ptr;using std::ifstream;using line_no=StrBlob::size_type;using ResultIter=set<line_no>::iterator;

class QueryResult;

class TextQuery
{
public:
	TextQuery(ifstream & ifs);
	QueryResult query(const string &) const;
	TextQuery(const TextQuery&)=delete;
	TextQuery& operator=(const TextQuery&)=delete;
private:
	//StrBlob file;
	shared_ptr<StrBlob> file;
	map<string,shared_ptr<set<line_no>>> wm;
};

class QueryResult
{
friend ostream & print(ostream &,const QueryResult &);
public:
	QueryResult(string s,
			shared_ptr<set<line_no>> ss,
			shared_ptr<StrBlob> sv):
		word(s),lines(ss),file(sv){ }
	QueryResult(const QueryResult& q)=delete;
	QueryResult& operator=(const QueryResult& q)=delete; 
	QueryResutl(QueryResult &&)=default;//rewrite_:move constructor;
	/*https://github.com/Mooophy/Cpp-Primer/issues/304#issuecomment-124081395*/

	ResultIter begin()const{return lines->begin();}
	ResultIter end()const{return lines->end();}
	shared_ptr<StrBlob> get_file()const{return file;}
private:
	string word;
	shared_ptr<set<line_no>> lines;
	shared_ptr<StrBlob> file;
};

#endif
