#include <iostream>
#include <vector>

using std::cout;using std::endl;using std::vector;

int main()
{
	vector<int> vi;
	cout<<vi.at(0);
	cout<<vi[0];
	cout<<vi.front();
	cout<<*vi.begin();

	return 0;
}
