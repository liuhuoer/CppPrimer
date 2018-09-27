#include "ex13_55.h"
void StrBlob::pop_back()
{
	check(0,"pop_back on empty StrBlob");
	data->pop_back();
}

string & StrBlob::front()
{
	check(0,"front on empty StrBlob");
	return data->front();
}

string & StrBlob::back()
{
	check(0,"back on empty StrBlob");
	return data->back();
}

void StrBlob::check(size_type i,const string & msg)const
{
	if(i>=data->size())
		throw out_of_range(msg);
}


/*
 * StrBlobPtr
 */
shared_ptr<vector<string>> StrBlobPtr::check(size_t i,const string & msg)const
{
	//using lock() test the effective of vector;
	//rewrite_:using lock();
	auto ptr=wpvs.lock();
	if(!ptr)
		throw std::runtime_error("unbound StrBlobPtr");
	if(i>=ptr->size())
		throw out_of_range(msg);

	return ptr;
}

string & StrBlobPtr::deref()const
{
	auto ptr=check(curr,"dereference past end");
	return (*ptr)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
	check(curr,"increase past end of StrBlobPtr");
	++curr;
	//rewrite_:return *this;
	return *this;
}

///*
//implementation functions in StrBlob;
StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this,data->size());
}
//*/

int main()
{
	return 0;
}
