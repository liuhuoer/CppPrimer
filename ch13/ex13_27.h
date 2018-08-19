#ifndef ex13_27_h
#define ex13_27_h

#include <string>

using std::string;

class HasPtr
{
public:
	HasPtr(const string & s=string()):ps(new string(s)),i(0),use(new size_t(1)){};
	HasPtr(const HasPtr &hp):ps(hp.ps),i(hp.i),use(hp.use){++*use;}
	HasPtr & operator=(const HasPtr & hp);
	~HasPtr();
private:
	size_t *use;
	int i;
	string *ps;
};

HasPtr & HasPtr::operator=(const HasPtr & rhp)
{
	++*rhp.use;
	if(--*use==0)
	{
		delete use;
		delete ps;
	}
	ps=rhp.ps;
	i=rhp.i;
	use=rhs.use;

	return *this;
}

~HasPtr()
{
	if(--*use==0)
	{
		delete use;
		delete ps;
	}
}
#endif
