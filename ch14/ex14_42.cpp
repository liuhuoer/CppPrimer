#ifndef EX14_42
#define EX14_42

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using std::vector;
using std::string;
using std::cout;using std::endl;
using std::bind;
using namespace std::placeholders;
 
int main()
{
	vector<int> vi = {1, 10, 100, 1000, 10000};
	auto result1 = std::count_if(vi.cbegin(), vi.cend(), bind(std::greater<int>(), _1, 1024));
	cout << "result1 = " << result1 <<endl;

	vector<string> vs = {"ppp", "pooh", "p"};
	auto result2 = std::find_if(vs.cbegin(), vs.cend(), bind(std::not_equal_to<string>(), _1, "pooh"));
	cout << "result2 = " << *result2 << endl;

	std::transform(vi.begin(), vi.end(), vi.begin(), bind(std::multiplies<int>(), _1, 2));
	cout << "result3" << endl;
	for(auto a : vi)
		cout << a << " ";

	return 0;
}

#endif
