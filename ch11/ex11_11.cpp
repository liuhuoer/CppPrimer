#include "../header/Sales_data.h"
#include <iostream>
#include <set>

using std::cout;using std::endl;using std::multiset;

int main()
{
	using p_compareIsbn=bool (*) (const Sales_data &,const Sales_data &);
	multiset<Sales_data,p_compareIsbn> ms(compareIsbn);

	return 0;
}
