#include "ex14_26_StrVec.h"

allocator<string> StrVec::alloc;

/*************************************************************
 *				operator_friend
 * **********************************************************/
bool operator==(const StrVec& lhs, const StrVec& rhs)
{
	return (lhs.size() == rhs.size()) && (std::equal(lhs.begin(), lhs.end(), lhs.begin()));
}

bool operator!=(const StrVec& lhs, const StrVec& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const StrVec& lhs, const StrVec& rhs)
{
	return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

bool operator>(const StrVec& lhs, const StrVec& rhs)
{
	return rhs < lhs;
}

bool operator<=(const StrVec& lhs, const StrVec& rhs)
{
	return !(lhs > rhs);
}

bool operator>=(const StrVec& lhs, const StrVec& rhs)
{
	return !(lhs < rhs);
}

/*************************************************************
 *				constructors
 * **********************************************************/

StrVec::StrVec(const StrVec & s)
{
	range_initialize(s.begin(), s.end());
}

StrVec::StrVec(initializer_list<string> ils)
{
	range_initialize(ils.begin(), ils.end());
}

void StrVec::range_initialize(const string *b, const string *e)
{
	auto newdata = alloc_n_copy(b,e);
	elements = newdata.first;
	first_free = cap = newdata.second;
}

//move()
StrVec::StrVec(StrVec && s)noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	s.elements = s.first_free = s.cap = nullptr;
}

StrVec& StrVec::operator=(StrVec&& rhs)noexcept
{
	if(this != &rhs)
	{
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}
/**/

StrVec::~StrVec()
{
	free();
}

StrVec& StrVec::operator=(const StrVec &rhs)
{
	//rewrite_:copy must before free(copy itself);
	auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = newdata.first;
	first_free = cap = newdata.second;
	return *this;
}

/*****************************************************************
 *			member_function
 * **************************************************************/
void StrVec::push_back(const string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++,s);
}

void StrVec::reallocate()
{
	//allocate;
	auto newcapacity = elements? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	//construct;
	auto elem_new = newdata;
	auto elem_old = elements;
	for(int i = 0; i < size(); ++i)
		alloc.construct(elem_new++, std::move(*elem_old++));
	free();
	//update ptr;
	elements = newdata;
	first_free = elem_new;
	cap = elements + newcapacity;
}

pair<string*, string*> StrVec::alloc_n_copy(const string* b, const string* e)
{
	auto b_newdata = alloc.allocate(e - b);
	return {b_newdata, std::uninitialized_copy(b, e, b_newdata)};
}

void StrVec::free()
{
	if(elements)
	{
		for(auto p=first_free; p != elements; )
			alloc.destroy(--p);
		alloc.deallocate(elements, cap-elements);
	}
}

