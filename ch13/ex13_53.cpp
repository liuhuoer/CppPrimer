#include "ex13_53.h"
#include <algorithm>

inline	//rewrite_:add inline to optimized code;
void swap(HasPtr & lhp,HasPtr & rhp)
{
	std::cout<<"swap(HasPtr,HasPtr)"<<std::endl;
	lhp.swap(rhp);
}

inline
HasPtr::~HasPtr()
{
	delete ps;
}

//rewrite_:chang HasPtr:: to friend function;
bool HasPtr::operator<(const HasPtr & rhp)
{
	std::cout<<"<"<<std::endl;
	return *ps < *rhp.ps;
}

//rewrite_:(const HasPtr &) change to (HasPtr rhp)
HasPtr & HasPtr::operator=(HasPtr rhp)
{
	std::cout<<"="<<std::endl;
	this->swap(rhp);

	return *this;
}

/*
HasPtr & HasPtr::operator=(HasPtr&& rhp)
{
	std::cout<<"=_move"<<std::endl;
	this->swap(rhp);

	return *this;
}
*/

void HasPtr::output()
{
	std::cout<<*ps<<std::endl;
}


int main()
{
	HasPtr hp1("hello"),hp2("world");
	cout<<"\noriginal:"<<endl;
	hp1=hp2;
	cout<<"\nmove:"<<endl;
	hp1=std::move(hp2);
	return 0;
}
