#include "notquery.h"

Query operator~(const Query& operand)
{
	return shared_ptr<Query_base>(new NotQuery(operand));
}

