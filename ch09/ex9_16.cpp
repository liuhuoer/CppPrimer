#include <iostream>
#include <vector>
#include <list>

using std::cout;using std::endl;using std::vector;using std::list;

int main()
{
	vector<int> vi1(3,3);
	list<int> vi2(3,2);
	list<int> vi3(3,3);

	cout<<(list<int>(vi1.cbegin(),vi1.cend())==vi2?"vi1==vi2":"vi1!=vi2")<<endl;	
	cout<<(list<int>(vi1.cbegin(),vi1.cend())==vi3?"vi1==vi3":"vi1!=vi3")<<endl;
	 
	return 0;
}
