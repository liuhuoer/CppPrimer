#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string>
using std::cout;using std::endl;
using std::string;

class Base
{
public:
	string name() const 
	{ return basename;}
	virtual void print(std::ostream& os) 
	{ os << "basename : " << basename << endl;}
private:
	string basename = "base";
};

#endif
