#ifndef EX14_37
#define EX14_37

#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;using std::cout;using std::endl;

class IsEqual 
{
public:
	IsEqual(int i) : value(i) 
	{ cout << "IsEqual(int)" << value<< endl;}
	bool operator () (int t)
	{ return value == t ? true : false;}
private:
	int value;
};

int main()
{
	vector<int> vi = {1, 2, 3, 3, 3, 3, 3, 3, 4, 5};
	cout<< "oral = ";
	for(auto a: vi)
		cout<< a<< " ";
	std::replace_if(vi.begin(), vi.end(), IsEqual(3), 0);

	cout<< "now = ";
	for(auto a: vi)
		cout<< a<< " ";

	return 0;
}
#endif
