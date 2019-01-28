#ifndef _QUERYHISTORY_
#define _QUERYHISTORY_

#include "query.h"
#include <vector>

class QueryHistory
{
public:
	Query& operator[](size_t n)
	{ return *(vQuery[n]);}
	size_t add_query(const Query&);
private:
	std::vector<std::shared_ptr<Query>> vQuery;
};

#endif
