#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <iostream>
#include <string>

struct Sales_data
{
	std::string bookNo;
	std::string bookName;
	unsigned salesCount;//before C++11
	double price;//before C++11
};
#endif
