#ifndef QUERY_H
#define QUERY_H

#include <iostream>
#include <string>
#include <memory>

#include "textquery.h"

using std::make_shared;
/* 
 * Query_base
 * */

class Query_base
{
	friend class Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;

private:
	virtual QueryResult eval(const TextQuery &) const = 0;
	virtual std::string rep() const = 0;
};

/*
 * WordQuery
 * */

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

/*
 * Query 
 * */
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
	Query(Query_base* query) : q(query)
	{ std::cout << "Query(*Query_base)" << std::endl;}
	Query_base* q;
};

ostream& operator<<(std::ostream& os, const Query& q)
{
	return os << q.rep();
}

/*
 * BinaryQuery
 * */

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

	Query lhs, rhs;
	std::string opt;
};

/*
 * AndQuery
 * */

class AndQuery : public BinaryQuery
{
	friend Query operator&(const Query&, const Query&);

	AndQuery(const Query& lhs, const Query& rhs) : BinaryQuery(lhs, rhs, "&")
	{ cout << "AndQuery(const string&, const string&)" << endl;}

	QueryResult eval(const TextQuery&) const override;
};

Query operator&(const Query& lhs, const Query& rhs)
{
	AndQuery aQuery(lhs, rhs);
	Query_base* result = & aQuery;
	return result;
}

/*
 * OrQuery
 * */

class OrQuery : public BinaryQuery
{
	friend Query operator|(const Query& lhs, const Query& rhs);

	OrQuery(const Query& lhs, const Query& rhs) : BinaryQuery(lhs, rhs, "|")
	{ cout << "OrQuery(const query&, const query&)" << endl;}

	QueryResult eval(const TextQuery&) const override;

};

Query operator|(const Query& lhs, const Query& rhs)
{
	OrQuery oQuery(lhs, rhs);
	Query_base* result = & oQuery;
	return result;
}


/*
 * NotQuery
 * */

class NotQuery : public Query_base
{
	friend Query operator~(const Query&);

	NotQuery(const Query& q) : query(q)
	{ cout << "NotQuery(const Query&)" << endl;}
	QueryResult eval(const TextQuery&) const override; 
	std::string rep() const
	{ 
		cout << "NotQuery::rep()" << endl;
		return "~(" + query.rep() + ")";
	}

	Query query;
};

Query operator~(const Query& operand)
{
	NotQuery nQuery(operand);
	Query_base* result = & nQuery;
	return result;
}


#endif
