#include <iostream>
#include <vector>

using std::cout;using std::endl;using std::vector;

int main()
{
	vector<int> vi1(3,3);
	vector<int> vi2(3,2);
	vector<int> vi3(3,3);

	cout<<(vi1==vi2?"vi1==vi2":"vi1!=vi2")<<endl;	
	cout<<(vi1==vi3?"vi1==vi3":"vi1!=vi3")<<endl;
	 
	return 0;
}
