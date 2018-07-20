#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
	int iarray[10],iarray2[10];
	cout<<"the firs version"<<endl;
	for (size_t x=0; x<10; ++x)
	{
		iarray[x]=x;
		iarray2[x]=iarray[x];
		cout<<iarray[x];
	}
	cout<<endl;

	cout<<"the second version"<<endl;
	vector<int> iv,iv2;
	for(int x=0; x!=10; ++x)
	{
		iv.push_back(x);
	}
	iv2=iv;
	for(auto x:iv2)
		cout<<x<<" ";
	cout<<endl;
	return 0;
}
