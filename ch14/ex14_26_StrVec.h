#ifndef ex14_26_StrVec
#define ex14_26_StrVec

#include <iostream>
#include <string>
#include <memory>
#include <utility>
#include <initializer_list>
#include <algorithm>

using std::string;using std::allocator;using std::pair;using std::initializer_list;

class StrVec
{
	friend bool operator==(const StrVec&, const StrVec&);
	friend bool operator!=(const StrVec&, const StrVec&);
	friend bool operator<(const StrVec&, const StrVec&);
	friend bool operator>(const StrVec&, const StrVec&);
	friend bool operator<=(const StrVec&, const StrVec&);
	friend bool operator>=(const StrVec&, const StrVec&);
public:
	StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr){ }
	StrVec(const StrVec &);
	StrVec(initializer_list<string>);
	StrVec& operator=(const StrVec&);
	//move
	StrVec(StrVec &&)noexcept;
	StrVec& operator=(StrVec &&)noexcept;
	~StrVec();

	string& operator[](std::size_t n);
	const string& operator[](std::size_t n) const ;
	
	void push_back(const string &);
	size_t size()const {return first_free - elements;}
	size_t capacity()const {return cap - elements;}
	string* begin()const {return elements;}
	string* end()const {return first_free;}
private:
	static allocator<string> alloc;
	void chk_n_alloc()
		{if(size() == capacity())reallocate();}
	void reallocate();
	pair<string*, string*> alloc_n_copy (const string*, const string*);
	void range_initialize (const string*, const string*);
	void free();

private:
	string* elements;
	string* first_free;
	string* cap;	//capacity;
};

bool operator==(const StrVec&, const StrVec&);
bool operator!=(const StrVec&, const StrVec&);

bool operator<(const StrVec&, const StrVec&);
bool operator>(const StrVec&, const StrVec&);
bool operator<=(const StrVec&, const StrVec&);
bool operator>=(const StrVec&, const StrVec&);

inline
string& StrVec::operator[](std::size_t n)
{
	if(n <= size())
		return *(elements+n);
}

inline
const string& StrVec::operator[](std::size_t n) const 
{
	if(n <= size())
		return *(elements+n);
}

#endif
