#include <iostream>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::invalid_argument;

int main()
{
	int i1,i2;
	while(cin>>i1>>i2)
	{
		if(i2==0)
			throw invalid_argument("0 can't be used here");
		else{
			cout<<"i1/i2="<<i1/i2<<endl;
			break;
		}
	}
	return 0;
}
