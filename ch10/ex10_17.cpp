#include "../ch07/ex7_21.h" 
#include <vector>
#include <algorithm> 

using std::vector;using std::sort;

int main()
{
	Sales_data s1("20180727",2,5),s2("20180726",3,10);
	vector<Sales_data> vs;
	vs.push_back(s1);
	vs.push_back(s2);
	 
	sort(vs.begin(),vs.end(),[](Sales_data s1,Sales_data s2){return s1.isbn()<s2.isbn();});

	for(auto a:vs)
	{
		print(cout,a);
		cout<<endl;
	}
	return 0; 
}
