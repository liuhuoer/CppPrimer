
#include <iostream>
#include <string>
#include "ex7_06.h"

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::string;

int main()
{
	Sales_data total;
	if(read(cin,total))
	{
		Sales_data trans;
		while(read(cin,trans))
		{
			if(total.isbn()==trans.isbn())
			{
				total.combine(trans);
			}
			else
			{
				print(cout,total)<<endl;
				total=trans;
			}
		}
		print(cout,total)<<endl;
	}
	else
	{
		cerr<<"There is no data"<<endl;
		return -1;
	}
	return 0;
}
