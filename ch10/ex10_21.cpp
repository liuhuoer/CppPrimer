#include <iostream>
#include <string>

using std::cout;using std::endl;using std::string;using std::boolalpha;

int main()
{
	int i=10;
	auto is_zero=[&i]()->bool{return i>0?!--i:!i;};
	while(i)
	{
		cout<<i<<endl;	//when i=1;
		cout<<"The number of "<<i<<" is 0?"<<boolalpha<<is_zero()<<endl;	//but there i=0; cout is calculate from right to left; 
	}

	return 0;
}
