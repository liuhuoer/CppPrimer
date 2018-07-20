#ifndef EX7_50_H
#define EX7_50_H

#include <iostream>
#include <string>

struct Person
{
	friend std::istream & read(std::istream & is,Person & person);
	friend std::ostream & print(std::ostream & os,Person & person);

public:
	Person()=default;
	Person(const std::string sname,const std::string saddr):name(sname),address(saddr){}
	explicit Person(std::istream & is)
	{read(is,*this);}

	std::string getName() const{return name;}
	std::string getAddress() const{return address;}
private:
	std::string name;
	std::string address;
};

std::istream & read(std::istream & is,Person & person)
{
	is>>person.name>>person.address;
	return is;
}

std::ostream & print(std::ostream & os,Person & person)
{
	os<<person.name<<" "<<person.address;
	return os;
}

#endif
