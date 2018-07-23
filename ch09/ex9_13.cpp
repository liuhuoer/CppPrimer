#include <iostream>
#include <vector>
#include <list>

using std::cout;using std::endl;using std::vector;using std::list;

int main ()
{
	list<int> li(5,5);
	vector<int> vi(5,6);

	vector<double> vd(li.begin(),li.end());
	for(auto i:li)
		cout<<i;
	cout<<endl;
	for(auto i:vd)
		cout<<i;
	cout<<endl;

	vector<double> vd2(vi.begin(),vi.end());
	for(auto i:vi)
		cout<<i;
	cout<<endl;
	
	for(auto i:vd2)
		cout<<i;
	cout<<endl;
	return 0;
}
