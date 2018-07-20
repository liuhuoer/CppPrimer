#include "ex7_11.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	Sales_data s;
	print(cout,s)<<endl;

	Sales_data s1("2018-1");
	print(cout,s1)<<endl;

	Sales_data s2("2018-2",3,5);
	print(cout,s2)<<endl;

	Sales_data s3(cin);
	print(cout,s3)<<endl;

	return 0;
}
