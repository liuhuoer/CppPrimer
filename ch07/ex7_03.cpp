#include <iostream>
#include <string>
#include "ex7_02.h"

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::string;

int main()
{
	Sales_data total;
	if(cin>>total.bookNo>>total.salesCount>>total.revenue)
	{
		Sales_data trans;
		while(cin>>trans.bookNo>>trans.salesCount>>trans.revenue)
		{
			if(total.isbn()==trans.isbn())
			{
				total.combine(trans);
			}
			else
			{
				cout<<"bookNo="<<total.bookNo
					<<"; Count="<<total.salesCount
					<<"; revenue="<<total.revenue<<endl;			//error maybe
				total=trans;
			}
		}
		cout<<"bookNo="<<total.bookNo<<"; Count="<<total.salesCount<<"; revenue="<<total.revenue<<endl;
	}
	else
	{
		cerr<<"There is no data"<<endl;
		return -1;
	}
	return 0;
}
