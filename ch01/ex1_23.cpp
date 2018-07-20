#include <iostream>
#include "Sales_item.h"

int main()
{
	Sales_item currItem,item;
	if(std::cin>>currItem)
	{
		int count=1;
		while(std::cin>>item)
		{
			if(compareIsbn(currItem,item))
				++count;
			else
			{
				std::cout<<currItem.isbn()<<" has "<<count<<"logs"<<std::endl;
				currItem=item;
				count=1;
			}
		}
		std::cout<<currItem.isbn()<<" has "<<count<<"logs"<<std::endl;
	}
	else
	{
		std::cerr<<"no data!"<<std::endl;
		return -1;
	}
	return 0;
}
