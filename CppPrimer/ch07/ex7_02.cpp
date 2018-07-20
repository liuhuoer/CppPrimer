#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::string;

struct Sales_data
{
	string isbn()const{return bookNo;};
	Sales_data & combine(const Sales_data &);
	string bookNo;
	unsigned salesCount=0;
	double revenue=0.0;
};

Sales_data & Sales_data::combine(const Sales_data & add_sum)
{
	salesCount+=add_sum.salesCount;
	revenue+=add_sum.revenue;
	return *this;
}

int main()
{
	Sales_data total;
	if(cin>>total.bookNo>>total.salesCount>>total.revenue)
	{
		Sales_data trans;
		while(cin>>trans.bookNo>>trans.salesCount>>trans.revenue)
		{
			if(total.isbn()==trans.isbn())
			{
				total.combine(trans);
			}
			else
			{
				cout<<"bookNo="<<total.bookNo
					<<"; Count="<<total.salesCount
					<<"; revenue="<<total.revenue<<endl;			//error maybe
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
