#include "ex13_44.h"
#include <iostream>

using std::cout;using std::endl;

pair<char*, char*> String::alloc_n_copy(const char* b, const char* e)
{
	auto newdata=alloc.allocate(e-b);
	return {newdata, std::uninitialized_copy(b,e,newdata)};
}

void String::range_initializer(const char* b, const char* e)
{
	auto newdata=alloc_n_copy(b,e);
	elements=newdata.first;
	first_free=newdata.second;
}

String::String(const String& s)
{
	range_initializer(s.begin(),s.end());
	cout<<"copy constructor(String)"<<endl;
}

//rewrite_:
String::String(const char* c_const)
{
	char* c=const_cast<char*>(c_const);
	while(*c)
		++c;
	//###debug_:
	range_initializer(c_const,c);
	cout<<"copy constructor(char)"<<endl;
}

String& String::operator=(const String& s)
{
	auto newdata=alloc_n_copy(s.begin(), s.end());
	free();
	elements=newdata.first;
	first_free=newdata.second;
	cout<<"operator ="<<endl;
	return *this;
}

String::~String()
{
	free();
}

void String::free()
{
	if(elements)
	{
		std::for_each(elements,first_free,[](const char& c){alloc.destroy(&c);});
		alloc.deallocate(elements,size());
	}
}

/*
void String::reallocate()
{
	//allocate;
	auto newcapacity=elements?2*capacity():1;
	auto newdata=alloc.allocdate(newcapacity);
	//construct;
	auto ele_new=newdata;
	auto ele_old=elements;
	for(int i=0;i<size();++i)
		alloc.construct(ele_new++,*ele_old++);
	free();
	//ptr;
	elements=newdata;
	first_free=ele_new;
	cap=newdata+newcapacity;
}
*/
//
