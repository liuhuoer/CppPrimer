#include <iostream>
//using std::cin;
using std::cout;
using std::endl;

int main()
{
	int count=0,val=0,currVal=0;
	if(std::cin>>currVal)
	{
		count=1;
		while(std::cin>>val)
		{
			if(currVal==val)
				++count;
			else
			{
				cout<<currVal<<" has "<<count<<" times "<<endl;
				currVal=val;
				count=1;
			}
		}
		cout<<currVal<<" has "<<count<<" times "<<endl;
	}
	return 0;
}
