#include "query.h"

/*
 * AndQuery
 * */

QueryResult AndQuery::eval(const TextQuery& t) const
{
	auto left = lhs.eval(t), right = rhs.eval(t);
	auto ret_lines = make_shared<set<line_no>>();

	std::set_intersection(left.begin(), left.end(),
			right.begin(), right.end(),
			inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, left.get_file());
}

/*
 * OrQuery
 * */


QueryResult OrQuery::eval(const TextQuery& t) const 
{
	auto left = lhs.eval(t), right = rhs.eval(t);
	auto ret_lines = make_shared<set<line_no>> (left.begin(), right.end());

	ret_lines->insert(right.begin(), right.end());
	return QueryResult(rep(), ret_lines, left.get_file());
}

/*
 * NotQuery
 * */

QueryResult NotQuery::eval(const TextQuery& t) const
{
	auto result = query.eval(t);
	auto ret_lines = make_shared<set<line_no>>();

	auto beg = result.begin(), end = result.end();
	size_t n = result.get_file()->size();
	
	for(size_t i = 0; i != n; ++i)
	{
		if(*beg != i | beg == end)
			ret_lines->insert(i);
		else if (*beg == i)
			++beg;
	}

	return QueryResult(rep(), ret_lines, result.get_file());
}
