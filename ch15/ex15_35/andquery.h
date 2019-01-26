#ifndef ANDQUERY_H
#define ANDQUERY_H

#include "binaryquery.h"

class AndQuery : public BinaryQuery
{
	friend Query operator&(const Query&, const Query&);

	AndQuery(const Query& lhs, const Query& rhs) : BinaryQuery(lhs, rhs, "&")
	{ cout << "AndQuery(const string&, const string&)" << endl;}

	QueryResult eval(const TextQuery& t) const override
	{
		//must add this function body (err vtable)
	}

};

Query operator&(const Query& lhs, const Query& rhs)
{
	return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

#endif
