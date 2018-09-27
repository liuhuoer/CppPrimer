#ifndef ex13_58_h
#define ex13_58_h

#include <iostream>
#include <vector>

using std::vector;using std::cout;using std::endl;

class Foo
{
public:
	Foo sorted() &&;
	Foo sorted() const &;
private:
	vector<int> data;
};

#endif
