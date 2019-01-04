#ifndef EX14_43
#define EX14_43

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using std::vector;
using std::cout;using std::endl;
using std::bind;
using namespace std::placeholders;
 
int main()
{
	vector<int> vi = {1, 10, 100, 1000, 10000};
	int value;
	std::cin >> value;
	std::modulus<int> mod;
	auto util_mod = [&](int i){return 0 == mod(value, i);};

	/*
	auto result1 = std::find_if_not(vi.cbegin(), vi.cend(), [&](int i){ return 0 == mod(value, i);});
	cout << (result1 == vi.end()? "yes" : "no") <<endl;
	*/

	auto result = std::all_of(vi.begin(), vi.end(), util_mod);
	cout << (result? "yes" : "no") << endl;

	return 0;
}

#endif
