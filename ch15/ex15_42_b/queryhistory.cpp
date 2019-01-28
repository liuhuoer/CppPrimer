#include "queryhistory.h"

size_t QueryHistory::add_query(const Query& q)
{
	vQuery.push_back(make_shared<Query>(q));
	return vQuery.size() - 1;
}

