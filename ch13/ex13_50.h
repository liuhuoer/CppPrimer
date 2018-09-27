#ifndef ex13_50_h
#define ex13_50_h

#include <memory>
#include <utility>
#include <algorithm>

using std::allocator;using std::pair;

class String
{
public:
	//rewrite_:
	String():String(" "){ }
	String(const char*);
	String(const String&);
	String(String&&)noexcept;
	String& operator=(String&&)noexcept;
	String& operator=(const String&);
	~String();

	char* deref() const{return elements;}
	auto begin() const{return elements;}
	auto end() const{return first_free;}
	auto size() const{return first_free-elements;}
/*	auto capacity() const{return cap-elements;}
 */

private:
	static allocator<char> alloc;
	void free();
/*
 *	void chk_n_alloc(){if(size()==capacity())reallocate();}
 *	void reallocate();
 */
	void range_initializer(const char*, const char*);
	pair<char*, char*> alloc_n_copy(const char*, const char*);

	char* elements;
	char* first_free;
/*	char* cap;
 */
};

allocator<char> String::alloc;

#endif
