#include "Sales_data.h"

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

int main()
{
	Sales_data data1,data2;
	//input the data1 and data2;
	std::cin>>data1.bookNo>>data1.bookName>>data1.salesCount>>data1.price;
	std::cin>>data2.bookNo>>data2.bookName>>data2.salesCount>>data2.price;
	//compare data1 and data2;
	if(data1.bookNo==data2.bookNo)
	{
		
		//calculate the sum of data1 and data2;
		unsigned totalSalesCount=data1.salesCount+data2.salesCount;
		double revenue=data1.salesCount*data1.price+data2.salesCount*data2.price;
		double averagePrice=0.0;
		if(totalSalesCount!=0)
		{
			averagePrice=revenue/totalSalesCount;
			std::cout<<data1.bookNo<<" "<<data1.bookName<<" "<<totalSalesCount<<" "<<averagePrice<<std::endl;
		}
		else
		{
			std::cerr<<"no data!"<<std::endl;
		}
	}
	else
	{
		return -1;
	}
	return 0;
}
