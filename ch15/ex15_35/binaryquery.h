#ifndef BINARYQUERY_H
#define BINARYQUERY_H

#include "query_base.h"
#include "query.h"

class BinaryQuery : public Query_base
{
protected:
	BinaryQuery(const Query& lhs_, const Query& rhs_, std::string s) 
		: lhs(lhs_), rhs(rhs_), opt(s)
	{ cout << "BinaryQuery(const Query&, const Query&, string)" << endl;}

	std::string rep() const override
	{ 
		cout << "BinaryQuery::rep()" << endl;
		return "(" + lhs.rep() + " " + opt + " " + rhs.rep() + ")";
	}
	//@bug@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//private:
	Query lhs, rhs;
	std::string opt;
};

#endif
