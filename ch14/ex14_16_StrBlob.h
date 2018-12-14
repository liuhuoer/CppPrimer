#ifndef EX14_16_STRBLOB
#define EX14_16_STRBLOB

#include <iostream> 
#include <string>
#include <vector>
#include <memory>
#include <initializer_list>
#include <stdexcept>

using std::cout;using std::endl;
using std::vector;
using std::string;
using std::weak_ptr;using std::shared_ptr;
using std::size_t;
using std::initializer_list;
using std::out_of_range;

class StrBlobPtr;

/*StrBlob
 * */

class StrBlob 
{
	using size_type=vector<string>::size_type;
	friend class StrBlobPtr;
	friend bool operator==(const StrBlob&, const StrBlob&);
	friend bool operator!=(const StrBlob&, const StrBlob&);
	
public:
	StrBlob() : data(std::make_shared<vector<string>>()) {}
	StrBlob(initializer_list<string> ils) : data(std::make_shared<vector<string>>(ils)) {}

	StrBlob(const StrBlob& sb) : data(std::make_shared<vector<string>>(*sb.data)) {}
	StrBlob& operator=(const StrBlob&);

	StrBlob(StrBlob&& sb) noexcept : data(std::move(sb.data)) {}
	StrBlob& operator=(StrBlob&&) noexcept;
	
	StrBlobPtr begin();
	StrBlobPtr end();

	//insert or delete element;
	void push_back(const string & s) {data->push_back(s);}
	void push_back(string&& s) {data->push_back(std::move(s));}
	void pop_back();

	//information about size;
	size_type size()const {return data->size();}
	bool empty()const {return data->empty();} 

	//get element;
	string & front();
	string & back();

private:
	std::shared_ptr<vector<string>> data;
	void check(size_type, const string &)const;
};

/*
 * */
bool operator==(const StrBlob&, const StrBlob&);
bool operator!=(const StrBlob&, const StrBlob&);


inline
void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

inline 
string& StrBlob::front()
{
	check(0, "front on empty StrBlob");
	data->front();
}

inline 
string& StrBlob::back()
{
	check(0, "back on empty StrBlob");
	data->back();
}

inline 
void StrBlob::check(size_type i, const string & msg)const
{
	if(i >= data->size())
		throw std::out_of_range(msg);
}


/*StrBlobPtr
 * */

class StrBlobPtr
{
	friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);

public:
	StrBlobPtr():curr(0){}
	StrBlobPtr(StrBlob &a, size_t curr_ = 0):
		wpvs(a.data), curr(curr_) {}

	string& deref() const;//deref*;
	StrBlobPtr& incr();//increase++;

private:
	shared_ptr<vector<string>> check(size_t, const string &)const;
	weak_ptr<vector<string>> wpvs;
	size_t curr;
};

/*
 * */
bool operator==(const StrBlobPtr&, const StrBlobPtr&);
bool operator!=(const StrBlobPtr&, const StrBlobPtr&);


inline
string & StrBlobPtr::deref()const
{
	auto ptr=check(curr, "dereference past end");
	return (*ptr)[curr];
}

inline
StrBlobPtr& StrBlobPtr::incr()
{
	check(curr, "increase past end of StrBlobPtr");
	++curr;
	//rewrite_:return *this;
	return *this;
}

inline
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

#endif
