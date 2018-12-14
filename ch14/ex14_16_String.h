#ifndef ex14_16_String
#define ex14_16_String

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>

using std::cin;using std::cout;using std::endl;using std::allocator;using std::pair;

class String
{
	friend std::istream& operator>>(std::istream&, String&);
	friend std::ostream& operator<<(std::ostream&, const String&);
	friend bool operator==(const String&, const String&);
	friend bool operator!=(const String&, const String&);

	friend bool operator<(const String&, const String&);
	friend bool operator>(const String&, const String&);
	friend bool operator<=(const String&, const String&);
	friend bool operator>=(const String&, const String&);
public:
	//rewrite_:
	String() : String("") { }
	String(const char*);
	String(const String&);
	String(String&&)noexcept;
	String& operator=(String&&)noexcept;
	String& operator=(const String&);
	~String();

	const char* c_str() const {return elements;}
	void push_back(const char);
	char* begin() const {return elements;}
	char* end() const {return first_free;}
	
	size_t size() const {return first_free - elements;}
	size_t capacity() const {return cap - elements;}

private:
 	void chk_n_alloc() {if(first_free == cap)reallocate();}
 	void reallocate();

	void range_initializer(const char*, const char*);
	pair<char*, char*> alloc_n_copy(const char*, const char*);

	void free();

private:
	char* elements;
	char* first_free;
	char* cap;
	static allocator<char> alloc;
};

allocator<char> String::alloc;
std::istream& operator>>(std::istream&, String&);
std::ostream& operator<<(std::ostream&, const String&);
bool operator==(const String&, const String&);
bool operator!=(const String&, const String&);

bool operator<(const String&, const String&);
bool operator>(const String&, const String&);
bool operator<=(const String&, const String&);
bool operator>=(const String&, const String&);

#endif
