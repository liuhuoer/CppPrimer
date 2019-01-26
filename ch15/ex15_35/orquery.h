#ifndef ORQUERY_H
#define ORQUERY_H

#include "binaryquery.h"

class OrQuery : public BinaryQuery
{
	friend Query operator|(const Query& lhs, const Query& rhs);

	OrQuery(const Query& lhs, const Query& rhs) : BinaryQuery(lhs, rhs, "|")
	{ cout << "OrQuery(const query&, const query&)" << endl;}
	QueryResult eval(const TextQuery& t) const override
	{ 
	Query test = Query("fiery") & Query("bird") | Query("wind");
		//must add this function body
	}

};

Query operator|(const Query& lhs, const Query& rhs)
{
	return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

#endif
