#include "../ch07/ex7_21.h"

#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::ifstream;
using std::ofstream;

int main(int argc,char * argv[])
{
	ifstream input(argv[1]);

	Sales_data total;
	if(read(input,total))
	{
		Sales_data trans;
		while(read(input,trans))
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
