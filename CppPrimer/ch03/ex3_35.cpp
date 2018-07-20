#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::begin;
using std::end;

int main()
{
	int array[5]={1,2,3,4,5};
	for(int *beg=begin(array), *last=end(array); beg!=last; ++beg)
		*beg=0;
	for(auto x:array)
		cout<<x;
	cout<<endl;
	return 0;
}
