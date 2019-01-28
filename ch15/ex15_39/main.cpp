#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>

#include "query.cpp"
#include "textquery.cpp"

int main()
{
	std::ifstream ifs("../../data/text_query.txt");
	TextQuery tQuery(ifs);
	Query test = Query("I") & Query("have") & Query("a") & Query("dream");

//	std::cout << test.eval(tQuery) << std::endl;

	return 0;
}

