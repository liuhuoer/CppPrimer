#include <iostream>
#include <vector>
#include <numeric>

using std::cout;using std::endl;using std::accumulate;using std::vector;

int main()
{
	vector<int> vs={1,2,3,4,5};
	int sum=accumulate(vs.begin(),vs.end(),0);
	cout<<sum<<endl;
	return 0;
}
