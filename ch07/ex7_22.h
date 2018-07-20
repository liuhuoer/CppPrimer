
#ifndef EX7_09_H
#define EX7_09_H

#include <string>

class Person
{
	friend istream & read(istream & is, Person & p);
	friend ostream & prient(ostream & os,const Person & p);
public:
	Person()=default;
	Person(const std::string sname,const std::string saddress)
		:name(sname),address(saddress){}
	Person(std::istream & is){read(is,*this);}
	auto get_name const&{return name;}
	auto get_address const&{return address;}
private:
	std::string name;
	std::string address;

}

istream & read(istream & is,Person & p)
{
	return is>>p.name>>p.address;
}

ostream & print(ostream & os,const Person & p);
{
	return os<<p.name<<" "<<p.address;
}


#endif
