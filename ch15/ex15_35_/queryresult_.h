/*
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


ostream& print(ostream& out, const QueryResult& qr)
{
	out << qr.word << " occurs " << qr.lines->size() << " "
		<< (qr.lines->size() > 1 ? "times" : "time") << endl;
	for(auto a : *(qr.lines))
	{
		out << "\t(line" << a + 1 << ")";

		auto ptr = qr.file->begin();
		for(; a != 0; a--)
			ptr++;
		out << ptr.deref() << endl;
	}

	return out;
}


#endif
*/
