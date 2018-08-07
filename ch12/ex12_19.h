#ifndef ex12_19_h
#define ex12_19_h

#include <iostream> 
#include <string>
#include <vector>
#include <memory>
#include <initializer_list>
#include <stdexcept>

using std::cout;using std::endl;using std::vector;using std::string;using std::weak_ptr;using std::shared_ptr;using std::size_t;using std::initializer_list;using std::out_of_range;

class StrBlobPtr;
/*StrBlob
 * */
class StrBlob 
{
public:
	friend class StrBlobPtr;
	StrBlobPtr begin();
	StrBlobPtr end();
//	StrBlobPtr begin(){return StrBlobPtr(*this);}
//	StrBlobPtr end(){return StrBlobPtr(*this,data->size());}

	using size_type=vector<string>::size_type;
	StrBlob():data(std::make_shared<vector<string>>()){}
	StrBlob(initializer_list<string> ils):data(std::make_shared<vector<string>>(ils)){}
	//information about size;
	size_type size()const{return data->size();}
	bool empty()const{return data->empty();}
	//insert or delete element;
	void push_back(const string & s){data->push_back(s);}
	void pop_back();
	//get element;
	string & front();
	string & back();
private:
	std::shared_ptr<vector<string>> data;
	void check(size_type i,const string & msg)const;
};

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


/*StrBlobPtr
 * */
class StrBlobPtr
{
public:
	StrBlobPtr():curr(0){}
	StrBlobPtr(StrBlob &a,size_t curr_=0):
		wpvs(a.data),curr(curr_){}
	string& deref()const;//deref*;
	StrBlobPtr& incr();//increase++;
	bool operator !=(const StrBlobPtr & ptr){return curr!=ptr.curr;}
private:
	shared_ptr<vector<string>> check(size_t,const string &)const;
	weak_ptr<vector<string>> wpvs;
	size_t curr;
};

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
#endif
