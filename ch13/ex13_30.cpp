#include "ex13_30.h"

//rewrite_:(const HasPtr &) change to (HasPtr rhp)
HasPtr & HasPtr::operator=(const HasPtr & rhp)
{
	//swap(*this,rhp);	//rewrite_:use swap();
	auto temp=new string(*rhp.ps);
	delete ps;
	ps=temp;
	i=rhp.i;

	return *this;
}

