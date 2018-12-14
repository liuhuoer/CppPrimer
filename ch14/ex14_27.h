#ifndef EX14_27
#define EX14_27

#include <iostream> 
#include <string>
#include <vector>
#include <memory>
#include <initializer_list>
#include <stdexcept>
#include <algorithm>

using std::cout;using std::endl;
using std::vector;
using std::string;
using std::weak_ptr;using std::shared_ptr;
using std::size_t;
using std::initializer_list;
using std::out_of_range;

class StrBlobPtr;

/*****************************************************************
 * 				class - StrBlob
 * **************************************************************/

class StrBlob 
{
	using size_type=vector<string>::size_type;
	friend class StrBlobPtr;
	friend bool operator==(const StrBlob&, const StrBlob&);
	friend bool operator!=(const StrBlob&, const StrBlob&);
	friend bool operator<(const StrBlob&, const StrBlob&);
	friend bool operator>(const StrBlob&, const StrBlob&);
	friend bool operator<=(const StrBlob&, const StrBlob&);
	friend bool operator>=(const StrBlob&, const StrBlob&);
	
public:
	//constructors
	StrBlob() : data(std::make_shared<vector<string>>()) {}
	StrBlob(initializer_list<string> ils) : data(std::make_shared<vector<string>>(ils)) {}

	StrBlob(const StrBlob& sb) : data(std::make_shared<vector<string>>(*sb.data)) {}
	StrBlob& operator=(const StrBlob&);

	StrBlob(StrBlob&& sb) noexcept : data(std::move(sb.data)) {}
	StrBlob& operator=(StrBlob&&) noexcept;
	
	//member_functions
	string& operator[](size_t n);
	const string& operator[](size_t n) const;

	StrBlobPtr begin();
	StrBlobPtr end();

	void push_back(const string & s) {data->push_back(s);}
	void push_back(string&& s) {data->push_back(std::move(s));}
	void pop_back();

	size_type size()const {return data->size();}
	bool empty()const {return data->empty();} 

	string & front();	//get element;
	string & back();

private:
	std::shared_ptr<vector<string>> data;
	void check(size_type, const string &)const;
};

/*****************************************************************
 *			StrBlob - inline & operator_friend
 * **************************************************************/
bool operator==(const StrBlob&, const StrBlob&);
bool operator!=(const StrBlob&, const StrBlob&);

bool operator<(const StrBlob&, const StrBlob&);
bool operator>(const StrBlob&, const StrBlob&);
bool operator<=(const StrBlob&, const StrBlob&);
bool operator>=(const StrBlob&, const StrBlob&);



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

inline
string& StrBlob::operator[](size_t n)
{
	check(n, "out of range");
	return data->at(n);
}

inline
const string& StrBlob::operator[](size_t n) const
{
	check(n, "out of range");
	return data->at(n);
}



/********************************************************************
 * 				class - StrBlobPtr
 * *****************************************************************/

class StrBlobPtr
{
	friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);

	friend bool operator<(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator>(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator>=(const StrBlobPtr&, const StrBlobPtr&);

public:
	StrBlobPtr():curr(0){}
	StrBlobPtr(StrBlob &a, size_t curr_ = 0):
		wpvs(a.data), curr(curr_) {}
	StrBlobPtr(const StrBlobPtr&);

	string& deref() const;//deref*;

	StrBlobPtr& operator++();
	StrBlobPtr operator++(int);
	StrBlobPtr& operator--();
	StrBlobPtr operator--(int);

private:
	shared_ptr<vector<string>> check(size_t, const string &)const;
	weak_ptr<vector<string>> wpvs;
	size_t curr;
};

/**************************************************************
 *			StrBlobPtr - inline & operator_friend
 * ***********************************************************/
bool operator==(const StrBlobPtr&, const StrBlobPtr&);
bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
bool operator<(const StrBlobPtr&, const StrBlobPtr&);
bool operator>(const StrBlobPtr&, const StrBlobPtr&);
bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
bool operator>=(const StrBlobPtr&, const StrBlobPtr&);


inline
string & StrBlobPtr::deref()const
{
	auto ptr=check(curr, "dereference past end");
	return (*ptr)[curr];
}

inline
StrBlobPtr& StrBlobPtr::operator++()
{
	check(curr, "increase past end of StrBlobPtr");
	++curr;
	return *this;
}

inline
StrBlobPtr StrBlobPtr::operator++(int)
{
	StrBlobPtr temp = *this;
	++*this;
	return temp;
}

inline
StrBlobPtr& StrBlobPtr::operator--()
{
	--curr;
	check(curr, "decrease past end of StrBlobPtr");
	return *this;
}

inline
StrBlobPtr StrBlobPtr::operator--(int)
{
	StrBlobPtr temp = *this;
	--*this;
	return temp;
}

inline
shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string & msg) const
{
	//using lock() test the effective of vector;
	//rewrite_: using lock();
	auto ptr = wpvs.lock();
	if(!ptr)
		throw std::runtime_error("unbound StrBlobPtr");
	if(i >= ptr->size())
		throw out_of_range(msg);

	return ptr;
}

#endif
