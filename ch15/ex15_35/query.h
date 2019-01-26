#ifndef QUERY_H
#define QUERY_H

#include <iostream>
#include <string>
#include <memory>


#include "query_base.h"
#include "textquery.h"
#include "queryresult.h"
#include "wordquery.h"

//using std::cout;using std::endl;

class Query
{
	friend Query operator~(const Query&);
	friend Query operator&(const Query&, const Query&);
	friend Query operator|(const Query&, const Query&);
public:
	Query(const std::string& s) : q(new WordQuery(s))
	{ std::cout << "Query(const std::string&)" << std::endl;}

	QueryResult eval(const TextQuery& t) const
	{ return q->eval(t);}

	std::string rep() const
	{ 
		std::cout << "Query::rep()" << std::endl;
		return q->rep();
	}
private:
	Query(std::shared_ptr<Query_base> query) : q(query)
	{ std::cout << "Query(shared_ptr<Query_base>)" << std::endl;}
	std::shared_ptr<Query_base> q;
};

ostream& operator<<(std::ostream& os, const Query& q)
{
	return os << q.rep();
}

#endif
