#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using std::cin;using std::cout;using std::endl;using std::istream_iterator;using std::ostream_iterator;using std::vector;

int main()
{
	//input;
	vector<int> vi;
	istream_iterator<int> in(cin),eof;
	//copy;
	unique_copy(in,eof,back_inserter(vi));
	//sort;
	sort(vi.begin(),vi.end(),[](int i1,int i2){return i1<i2?true:false;});
	//output;
	copy(vi.begin(),vi.end(),ostream_iterator<int>(cout,"\n"));

	return 0;
}
