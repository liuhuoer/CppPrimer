
#ifndef EX7_09_H
#define EX7_09_H

#include <string>

class Person
{
	std::string name;
	std::string address;
public:
	auto get_name const&{return name;}
	auto get_address const&{return address;}
}

istream & read(istream & is,Person & p)
{
	return is>>p.name>>p.address;
}
ostream & print(ostream & os,Person & p);
{
	return os<<p.name<<" "<<p.address;
}


#endif
