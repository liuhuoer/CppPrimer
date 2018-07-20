#include <iostream>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::runtime_error;

int main()
{
	int i1,i2;
	while(cin>>i1>>i2)
	{
		try{
			if(i2==0)
				throw runtime_error("0 can't be used here");
			else{
				cout<<"i1/i2="<<i1/i2<<endl;
				break;
			}
		}catch(runtime_error err){
			cout<<err.what()
				<<"Do you want try again?(y/n)"
				<<endl;
			char c;
			cin>>c;
			if(!cin||c=='n')
				break;
		}
	}
	return 0;
}
