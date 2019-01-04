#include "ex14_45.cpp"

int main()
{
	string s= "2018-01";
	Sales_data sd = s;
	cout << sd <<endl;
	cout << static_cast<string>(sd) << endl;
	cout << static_cast<double>(sd) << endl;

	return 0;
}
