#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

struct Sales_data
{
	std::string bookNo;
	std::string bookName;
	unsigned salesCount=0;
	double revenue=0.0;
	double price=0.0;
};
int main()
{
	Sales_data total;
	if(cin>>total.bookNo>>total.salesCount>>total.revenue)
	{
		Sales_data trans;
		while(cin>>trans.bookNo>>trans.salesCount>>trans.revenue)
		{
			if(total.bookNo==trans.bookNo)
			{
				total.salesCount+=trans.salesCount;
			}
			else
			{
				cout<<"bookNo="<<total.bookNo<<"; Count="<<total.salesCount<<"; revenue="<<total.revenue<<endl;			//error maybe
				total=trans;
			}
		}
		cout<<"bookNo="<<total.bookNo<<"; Count="<<total.salesCount<<"; revenue="<<total.revenue<<endl;
	}
	else
	{
		cerr<<"There is no data"<<endl;
		return -1;
	}
	return 0;
}
