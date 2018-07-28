#include "../ch07/ex7_21.h" 
#include <vector>

using std::vector;

vector<Sales_data> compareIsbn(Sales_data s1,Sales_data s2)
{
	vector<Sales_data> vs;
	if(s1.isbn()<s2.isbn())
	{
		vs.push_back(s1);
		vs.push_back(s2);
	}
	else
	{ 
		vs.push_back(s2);
		vs.push_back(s1);
	}
	return vs;
}

int main()
{
	Sales_data s1("20180727",2,5),s2("20180726",3,10);
	vector<Sales_data> vs;
	vs=compareIsbn(s1,s2);
	for(auto a:vs)
	{
		print(cout,a);
		cout<<endl;
	}
	return 0; 
}
