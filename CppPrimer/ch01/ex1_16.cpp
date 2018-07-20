//Calculate the sum of some numbers from cin.
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int i=0,sum=0;
	while(cin>>i)
	{
		sum+=i;
		cout<<"sum="<<sum<<endl;
	}
}
