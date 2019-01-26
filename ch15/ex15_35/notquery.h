#ifndef NOTQUERY_H
#define NOTQUERY_H

#include "query.h"

class NotQuery : public Query_base
{
	friend Query operator~(const Query&);

	NotQuery(const Query& q) : query(q)
	{ cout << "NotQuery(const Query&)" << endl;}
	QueryResult eval(const TextQuery& t) const; 
	std::string rep() const
	{ 
		cout << "NotQuery::rep()" << endl;
		return "~(" + query.rep() + ")";
	}

	Query query;
};

Query operator~(const Query&);

#endif
