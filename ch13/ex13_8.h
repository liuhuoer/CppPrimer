#ifndef ex13_8_h
#define ex13_8_h

#include <string>
#include <iostream>
using std::cout;using std::endl;

class HasPtr
{
public:
	HasPtr(const std::string &s=std::string()):ps(new std::string(s)),i(0){ }
	HasPtr(const HasPtr & hp):ps(new std::string(*hp.ps)),i(hp.i){ }
	HasPtr & operator=(const HasPtr & rh_hp);

	printOther(const HasPtr & hp){cout<<*hp.ps<<" "<<hp.i<<endl;}
private:
	std::string *ps;
	int i;
};

HasPtr & HasPtr::operator=(const HasPtr & rh_hp)
{
	if(this!=&rh_hp)	//rewrite_:add check !=
	{
		//rewrite_:delete init ps memory first;
		*ps=*rh_hp.ps;
		i=rh_hp.i;
	}
	return *this;
}

#endif
