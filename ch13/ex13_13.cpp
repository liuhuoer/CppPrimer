#include <iostream>
#include <string>
#include <vector>
#include <memory>

using std::cout;using std::endl;using std::string;using std::vector;

struct X
{
	X(){cout<<"X()"<<endl;}
	X(const X &){cout<<"X(const X &)"<<endl;}
	X & operator=(const X &){cout<<"operator="<<endl;return *this;}
	~X(){cout<<"~X()"<<endl;}
};
int main()
{
	X x1;
	X x2(x1);
	X x3=x1;
	X x4;
	x4=x1;
	X *x5=new X(x1);

	auto x6=std::make_shared<X>();

	vector<X> vx;
	vx.push_back(x1);
	delete x5;

	return 0;
}
