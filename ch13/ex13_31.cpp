#include "ex13_31.h"
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

void HasPtr::output()
{
	std::cout<<*ps<<std::endl;
}


int main()
{
	//input;
	HasPtr a("c"),b("b"),c("a");
	vector<HasPtr> vh{a,b,c};
	//vector<HasPtr> vh;
	//for(string s;std::cin>>s;)
	//	vh.emplace_back(s);

	//sort;
	std::sort(vh.begin(),vh.end());

	//output;
	for(auto a:vh)
		a.output();

	return 0;
}
