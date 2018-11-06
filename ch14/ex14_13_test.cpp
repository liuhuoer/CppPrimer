#include "ex14_13.cpp"

int main()
{
	Sales_data sd("2018-1",10,1.23);
	Sales_data sd2("2018-1",1,1.23);
	Sales_data sd3;
	sd3 = sd - sd2;
	cout<<sd3<<endl;
	return 0;
}
