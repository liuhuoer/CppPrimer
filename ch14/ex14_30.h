#ifndef EX14_30
#define EX14_30

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
class ConstStrBlobPtr;

/*****************************************************************
 * 				class - StrBlob
 * **************************************************************/

class StrBlob 
{
	using size_type=vector<string>::size_type;
	friend class StrBlobPtr;
	friend class ConstStrBlobPtr;
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

	ConstStrBlobPtr cbegin();
	ConstStrBlobPtr cend();

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

	const string& operator*() const;
	const string* operator->() const;
	StrBlobPtr operator+(size_t) const;
	StrBlobPtr operator-(size_t) const;
	StrBlobPtr& operator+=(size_t);
	StrBlobPtr& operator-=(size_t);
	
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
const string& StrBlobPtr::operator*() const
{
	auto ptr = check(curr, "dereference past end");
	return (*ptr)[curr];
}

inline 
const string* StrBlobPtr::operator->() const 
{
	return & this->operator*();
}

inline
StrBlobPtr& StrBlobPtr::operator++()
{
	++curr;
	check(curr, "increase past end of StrBlobPtr");
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
StrBlobPtr& StrBlobPtr::operator+=(size_t n)
{
	curr += n;
	check(curr, "increase past end of StrBlobPtr");
	return *this;

}

inline 
StrBlobPtr& StrBlobPtr::operator-=(size_t n) 
{
	 curr -= n;
	 check(curr, "decrease past end of StrBlobPtr");
	 return *this;
}

inline 
StrBlobPtr StrBlobPtr::operator+(size_t n) const
{
	StrBlobPtr temp = *this;
	temp += n;
	return temp;
}

inline 
StrBlobPtr StrBlobPtr::operator-(size_t n) const
{
	StrBlobPtr temp = *this;
	temp -= n;
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
	if(i > ptr->size())
		throw out_of_range(msg);

	return ptr;
}

/********************************************************************
 * 				class - ConstStrBlobPtr
 * *****************************************************************/

class ConstStrBlobPtr
{
	friend bool operator==(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
	friend bool operator!=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);

	friend bool operator<(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
	friend bool operator>(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
	friend bool operator<=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
	friend bool operator>=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);

public:
	ConstStrBlobPtr():curr(0){}
	ConstStrBlobPtr(StrBlob &a, size_t curr_ = 0):
		wpvs(a.data), curr(curr_) {}
	ConstStrBlobPtr(const ConstStrBlobPtr& sbp) : wpvs(std::weak_ptr<vector<string>>(sbp.wpvs)), curr(sbp.curr) {}
	ConstStrBlobPtr& operator=(const ConstStrBlobPtr&);

	const string& operator*() const;
	const string* operator->() const;
	ConstStrBlobPtr operator+(size_t) const;
	ConstStrBlobPtr  operator-(size_t) const;
	ConstStrBlobPtr& operator+=(size_t);
	ConstStrBlobPtr& operator-=(size_t);
	
	ConstStrBlobPtr& operator++();
	ConstStrBlobPtr operator++(int);
	ConstStrBlobPtr& operator--();
	ConstStrBlobPtr operator--(int);

private:
	shared_ptr<vector<string>> check(size_t, const string &)const;
	weak_ptr<vector<string>> wpvs;
	size_t curr;
};

/**************************************************************
 *			StrBlobPtr - inline & operator_friend
 * ***********************************************************/
bool operator==(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator!=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);

bool operator<(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator>(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator<=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator>=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);

inline
const string& ConstStrBlobPtr::operator*() const
{
	auto ptr = check(curr, "dereference past end");
	return (*ptr)[curr];
}

inline 
const string* ConstStrBlobPtr::operator->() const 
{
	return & this->operator*();
}

inline
ConstStrBlobPtr& ConstStrBlobPtr::operator++()
{
	++curr;
	check(curr, "increase past end of StrBlobPtr");
	return *this;
}

inline
ConstStrBlobPtr ConstStrBlobPtr::operator++(int)
{
	ConstStrBlobPtr temp = *this;
	++*this;
	return temp;
}

inline
ConstStrBlobPtr& ConstStrBlobPtr::operator--()
{
	--curr;
	check(curr, "decrease past end of StrBlobPtr");
	return *this;
}

inline
ConstStrBlobPtr ConstStrBlobPtr::operator--(int)
{
	ConstStrBlobPtr temp = *this;
	--*this;
	return temp;
}

inline
ConstStrBlobPtr& ConstStrBlobPtr::operator+=(size_t n)
{
	curr += n;
	check(curr, "increase past end of StrBlobPtr");
	return *this;

}

inline 
ConstStrBlobPtr& ConstStrBlobPtr::operator-=(size_t n) 
{
	 curr -= n;
	 check(curr, "decrease past end of StrBlobPtr");
	 return *this;
}

inline 
ConstStrBlobPtr ConstStrBlobPtr::operator+(size_t n) const
{
	ConstStrBlobPtr temp = *this;
	temp += n;
	return temp;
}

inline 
ConstStrBlobPtr ConstStrBlobPtr::operator-(size_t n) const
{
	ConstStrBlobPtr temp = *this;
	temp -= n;
	return temp;
}

inline
shared_ptr<vector<string>> ConstStrBlobPtr::check(size_t i, const string & msg) const
{
	//using lock() test the effective of vector;
	//rewrite_: using lock();
	auto ptr = wpvs.lock();
	if(!ptr)
		throw std::runtime_error("unbound StrBlobPtr");
	if(i > ptr->size())
		throw out_of_range(msg);

	return ptr;
}


#endif
