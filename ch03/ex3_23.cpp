#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
	//int i;
	//vector<int> vi;
	//while(cin>>i)
	//	vi.push_back(i);
	vector<int> vi={1,2,3,4,5,6,7,8,9,10};
	for(auto it=vi.begin();it!=vi.end();++it)
	{
		*it=(*it)*2;
		cout<<*it<<endl;
	}
	return 0;
}
