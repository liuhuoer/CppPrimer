#include "ex7_41.cpp"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	cout<<"1:"<<endl;
	Sales_data s1;
	cout<<"2:"<<endl;
	Sales_data s2("CPP-Primer-5th");
	cout<<"3:"<<endl;
	Sales_data s3("CPP-Primer-5th",3,25.8);
	cout<<"4:"<<endl;
	Sales_data s4(std::cin);
	return 0;
}
