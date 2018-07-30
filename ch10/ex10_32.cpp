#include "../ch07/ex7_21.h" 
#include <vector>
#include <iterator>

using std::vector;using std::istream_iterator;

bool compareIsbn(const Sales_data & s1,const Sales_data & s2)
{
	return s1.isbn()<s2.isbn();
}

int main()
{
	istream_iterator<Sales_data> in(in),eof;
	vector<Sales_data> vs;

	copy(in,eof,back_inserter(vs));

	
	while(in!=eof)
		if()
	for(auto a:vs)
	{
		print(cout,a);
		cout<<endl;
	}
	return 0; 
}
