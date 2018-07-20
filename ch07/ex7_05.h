#ifndef EX7_04_H
#define EX7_04_H

#include <string>

class Person
{
	std::string name;
	std::string address;
public:
	auto get_name const&{return name;}
	auto get_address const&{return address;}
}

#endif
