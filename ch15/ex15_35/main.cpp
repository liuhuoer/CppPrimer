#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>

#include "queryresult.h"
#include "textquery.cpp"
#include "query_base.h"
#include "query.h"
#include "andquery.h"
#include "orquery.h"

int main()
{
	//Query test = Query("fiery") & Query("bird") | Query("wind");
	Query test = Query("fiery") & Query("bird");
	std::cout << "*********************************************\n" << test <<std::endl;
	return 0;
}

