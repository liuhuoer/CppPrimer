#include "ex14_26_String.h"

/***********************************************
 *		operator - friend
 * ********************************************/

std::istream& operator>>(std::istream& is, String& s)
{
	for(char c; (c = is.get()) != '\n';)
		s.push_back(c);
	return is;
}

std::ostream& operator<<(std::ostream& os, const String& s)
{
	os << s.c_str();
	return os;
}

bool operator==(const String& lhs, const String& rhs)
{
	return (lhs.size() == rhs.size()) && (std::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

bool operator!=(const String& lhs, const String& rhs)
{
	return !(lhs == rhs);
}



/**********************************************
 * 		constructors
 * *******************************************/

String::String(const char* c_const)		//rewrite_:
{
	char* c = const_cast<char*>(c_const);
	while(*c)		//when *c == '\0', stop
		++c;
	range_initializer(c_const, ++c);
}


String::String(const String& s)
{
	range_initializer(s.begin(), s.end());
}

String& String::operator=(const String& s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	free();
	elements = newdata.first;
	first_free = newdata.second;
	return *this;
}


String::String(String&& s)noexcept : elements(s.elements), first_free(first_free)
{
	s.elements = s.first_free = nullptr;
}

String& String::operator=(String&& rhs)noexcept
{
	if(this != &rhs)
	{
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		rhs.elements = rhs.first_free = nullptr;
	}
	return *this;
}

String::~String()
{
	free();
}

/*****************************************************
 *			member functions
 * **************************************************/

void String::push_back(const char c)
{
	chk_n_alloc();
	char * last_elem = first_free - 1;
	*last_elem = c;
	alloc.construct(first_free++, '\0');
}
	
pair<char*, char*> String::alloc_n_copy(const char* b, const char* e)
{
	auto newdata = alloc.allocate(e - b);
	return {newdata, std::uninitialized_copy(b, e, newdata)};
}

void String::range_initializer(const char* b, const char* e)
{
	auto newdata = alloc_n_copy(b, e);
	elements = newdata.first;
	first_free = newdata.second;
}


void String::free()
{
	if(elements)
	{
		std::for_each(elements, first_free, [](const char& c){alloc.destroy(&c);});
		alloc.deallocate(elements, cap - elements);
	}
}

void String::reallocate()
{
	//allocate;
	auto newcapacity = size() ? 2 * (size() + 1) : 2;
	auto newdata = alloc.allocate(newcapacity);
	//construct;
	auto ele_new = newdata;
	auto ele_old = elements;
	for(int i = 0; i < size(); ++i)
		alloc.construct(ele_new++, std::move(*ele_old++));
	free();
	//ptr;
	elements = newdata;
	first_free = ele_new;
	cap = newdata + newcapacity;
}

