#ifndef WORDQUERY_H
#define WORDQUERY_H

#include "query_base.h"

class WordQuery : public Query_base
{
	friend class Query;

	WordQuery(const std::string& s) : query_word(s)
	{ std::cout << "WordQuery(const string&)" << std::endl;}
	QueryResult eval(const TextQuery& t) const
	{ return t.query(query_word);}
	std::string rep() const
	{
		std::cout << "WordQuery::rep()" << std::endl;
		return query_word;
	}
	std::string query_word;
};

#endif
