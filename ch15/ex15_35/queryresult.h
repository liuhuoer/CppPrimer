#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include "textquery.h"

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
