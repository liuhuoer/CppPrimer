#ifndef ex13_53_h
#define ex13_53_h

#include <iostream>
#include <string>
#include <vector>

using std::string;using std::vector;using std::cout;using std::endl;

class HasPtr
{
public:
	friend void swap(HasPtr & lhp,HasPtr & rhp);
	bool operator<(const HasPtr &);
	HasPtr(const string & s=string()):ps(new string(s)),i(0)
	{
		cout<<"HasPtr(const stirng &)"<<endl;
	}

	HasPtr(const HasPtr &hp):ps(new string(*hp.ps)),i(hp.i)
	{
		cout<<"HasPtr(const HasPtr &)"<<endl;
	}

	HasPtr(HasPtr&& hp):ps(new string(*hp.ps)),i(hp.i)
	{
		cout<<"HasPtr(HasPtr&&)"<<endl;
	}

	HasPtr & operator=(HasPtr rhp);
	HasPtr & operator=(HasPtr&& rhp);
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

#endif
