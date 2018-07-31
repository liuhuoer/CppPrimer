#include "../header/Sales_data.h" 
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>

using std::cin;using std::vector;using std::istream_iterator;

int main()
{
	istream_iterator<Sales_data> in(cin),eof;
	vector<Sales_data> vs;

	//copy from stream to vs;
	copy(in,eof,back_inserter(vs));
	//sort;
	sort(vs.begin(),vs.end(),compareIsbn);

	//calculate sum;
	auto beg=vs.begin(),curr=beg;
	for(;beg!=vs.end();beg=curr)
	{
		//find the position of diffierent isbn;
		curr=find_if(beg,vs.end(),[beg](const Sales_data & sd){return beg->isbn()!=sd.isbn();});
		//calculate sum of same isbn, and output;
		cout<<accumulate(beg,curr,Sales_data(beg->isbn()))<<endl;	//rewrite_: change to beg->isbn();
	}
	
	return 0; 
}
