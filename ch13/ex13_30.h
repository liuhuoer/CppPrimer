#ifndef ex13_30_h
#define ex13_30_h

#include <iostream>
#include <string>

using std::string;

class HasPtr
{
public:
	friend void swap(HasPtr & lhp,HasPtr & rhp);
	HasPtr(const string & s=string()):ps(new string(s)),i(0){}
	HasPtr(const HasPtr &hp):ps(hp.ps),i(hp.i){}
	HasPtr & operator=(const HasPtr & rhp);
	~HasPtr();
private:
	int i;
	string *ps;
};

inline 	//rewrite_:add inline to optimized code;
void swap(HasPtr & lhp,HasPtr & rhp)
{
	using std::swap;
	swap(lhp.ps,rhp.ps);
	swap(lhp.i,rhp.i);
	std::cout<<"void swap(HasPtr & lhp,HasPtr & rhp)"<<std::endl;
}


inline
~HasPtr()
{
	delete ps;
}
#endif
