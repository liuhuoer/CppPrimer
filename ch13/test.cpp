#include "ex13_39.h"
StrVec::StrVec(const StrVec & s)
{
	auto newdata=alloc_n_copy(s.begin(),s.end());
	elements=newdata.first;
	first_free=cap=newdata.second;
}

StrVec::~StrVec()
{
	free();
}

StrVec& StrVec::operator=(const StrVec &rhs)
{
	//rewrite_:copy must before free(copy itself);
	auto newdata=alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements=newdata.first;
	first_free=cap=newdata.second;
	return *this;
}

void StrVec::push_back(const string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++,s);
}

void StrVec::reallocate()
{
	//allocate;
	auto newcapacity=elements?2*size():1;
	auto newdata=alloc.allocate(newcapacity);
	//construct;
	auto elem_new=newdata;
	auto elem_old=elements;
	for(int i=0;i<size();++i)
		alloc.construct(elem_new++,std::move(*elem_old++));
	free();
	//update ptr;
	elements=newdata;
	first_free=elem_new;
	cap=elements+newcapacity;
}

pair<string*, string*> StrVec::alloc_n_copy(string* b, string* e)
{
	auto b_newdata=alloc.allocate(e-b);
	return {b_newdata,uninitialized_copy(b,e,b_newdata)};
}

void StrVec::free()
{
	if(elements)
	{
		for(auto p=first_free; p!=elements; )
			alloc.destroy(--p);
		alloc.deallocate(elements,cap-elements);
	}
}

int main()
{
	return 0;
}
//
//
//
//
//
//
