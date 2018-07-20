#include <iostream>
#include <vector>
#include <iterator>

using std::cout;
using std::endl;
using std::vector;
using std::begin;
using std::end;

int main()
{
	int arr[5]={1,2,3,4,5};
	vector<int> vi(begin(arr),end(arr));
	for(auto x:vi)
		cout<<x;
	cout<<endl;
	return 0;
}
