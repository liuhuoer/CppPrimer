#ifndef ex13_31_h
#define ex13_31_h

#include <iostream>
#include <string>
#include <vector>

using std::string;using std::vector;

class HasPtr
{
public:
	friend void swap(HasPtr & lhp,HasPtr & rhp);
	friend bool operator<(const HasPtr &,const HasPtr &);
	HasPtr(const string & s=string()):ps(new string(s)),i(0){}
	HasPtr(const HasPtr &hp):ps(new string(*hp.ps)),i(hp.i){}
	HasPtr & operator=(HasPtr rhp);
	void output();
	void swap(HasPtr & rhp)
	{
		using std::swap;
		swap(ps,rhp.ps);
		swap(i,rhp.i);
		std::cout<<"swqp(HasPtr)"<<std::endl;
	}

	~HasPtr();
private:
	int i;
	string *ps;
};

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
bool operator<(const HasPtr & lhp,const HasPtr & rhp)
{
	std::cout<<"<"<<std::endl;
	return *lhp.ps < *rhp.ps;
}

//rewrite_:(const HasPtr &) change to (HasPtr rhp)
HasPtr & HasPtr::operator=(HasPtr rhp)
{
	std::cout<<"="<<std::endl;
	this->swap(rhp);

	return *this;
}

void HasPtr::output()
{
	std::cout<<*ps<<std::endl;
}


#endif
