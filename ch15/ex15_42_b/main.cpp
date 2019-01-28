#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>

#include "query.cpp"
#include "textquery.cpp"
#include "queryhistory.cpp"

int main()
{
	std::ifstream ifs("../../data/text_query.txt");
	TextQuery tQuery(ifs);
	QueryHistory qHistory;
	Query test = Query("I") & Query("have") & Query("a") & Query("dream");

	std::cout << "size : " << qHistory.add_query(test) 
		<< "\n" << test.eval(tQuery) <<std::endl;
	test = qHistory[0] & Query("hills");
	std::cout << test.eval(tQuery) <<std::endl;

	return 0;
}

