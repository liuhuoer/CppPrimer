#include <iostream>
using std::cout;using std::endl;

class Base
{
public:
	virtual int fcn()
	{ 
		cout << "Base::fcn()\n";
		return 0;
	}
};

class D1 : public Base
{
public:
	int fcn() override	
	{
		cout << "D1::fcn()\n";
		return 0;
	}
	virtual void f2()
	{ cout << "D1::f2()\n";}
};

class D2 : public D1
{
public:
	int fcn() override
	{ 
		cout << "D2::fcn()\n";
		return 0;
	}
	int fcn(int);
	void f2()
	{ cout << "D2::f2()\n";}
};

int main()
{
	Base bobj;
	D1 d1obj;
	D2 d2obj;

	Base* bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
	bp1->fcn();
	bp2->fcn();
	bp3->fcn();

	D1* dp1 = &d1obj, *dp2 = &d2obj;
	dp1->f2();
	dp2->f2();

	return 0;
}
